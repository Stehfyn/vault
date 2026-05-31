# Xaml Islands Minimal Win32 Host

Xaml Islands is the supported bridge for hosting UWP XAML controls inside a classic desktop HWND tree. The minimum sequence is deceptively small: initialize the WinRT/XAML apartment, create `WindowsXamlManager`, create `DesktopWindowXamlSource`, attach it to the host HWND, size the island HWND, and assign XAML content. The hard parts are focus, keyboard accelerators, DPI, lifetime, and controls that assume more of the UWP app model than the island provides.

Use this note as the official counterpart to `uwplib`. The sample is valuable because it keeps the boilerplate visible, which makes hybrid-app failures easier to classify: message-loop integration, parent HWND sizing, XAML lifetime, or unsupported control behavior.

## Source Shape

Source pass: `MarkIngramUK/XamlIslands/Common/Sample.cpp` shows the important HWND/XAML handshake. The host creates `DesktopWindowXamlSource`, queries `IDesktopWindowXamlSourceNative`, attaches to the parent HWND, retrieves the child HWND, forwards pre-translation, and resizes the island explicitly.

```cpp
auto manager = WindowsXamlManager::InitializeForCurrentThread();

DesktopWindowXamlSource source;
auto native = source.as<IDesktopWindowXamlSourceNative>();
check_hresult(native->AttachToWindow(hostHwnd));

HWND island = nullptr;
check_hresult(native->get_WindowHandle(&island));
SetWindowPos(island, nullptr, 0, 0, width, height, SWP_NOZORDER | SWP_SHOWWINDOW);

auto native2 = source.as<IDesktopWindowXamlSourceNative2>();
BOOL processed = FALSE;
native2->PreTranslateMessage(&msg, &processed);
```

This is a child-HWND interop contract, not a magic conversion of a Win32 app into UWP. The parent still owns its message loop, sizing, teardown, DPI policy, and non-XAML chrome.

## Source Walkthrough

The sample splits the host correctly:

- `Common/WinMain.cpp` is ordinary Win32: register a class, create the top-level HWND, route `WM_CREATE` / `WM_SIZE` / `WM_DESTROY` into the sample object.
- `Common/Sample.cpp` owns XAML lifetime: `WindowsXamlManager`, `DesktopWindowXamlSource`, the child island HWND, and message pre-translation.
- `HelloXaml/HelloXaml.cpp` owns only content: create a `Grid`, create `TextBlock`, set alignment/brush/text, then call `SetXamlContent(grid)`.
- `FilePicker/FilePicker.cpp` demonstrates the other critical interop contract: `FileOpenPicker` must be queried for `IInitializeWithWindow` and initialized with the host HWND before `PickSingleFileAsync`.

The shape worth stealing is the separation between "island plumbing" and "XAML content." `Sample::OnWindowCreated` initializes XAML once for the UI thread, attaches the source to the host HWND, stores the child HWND returned by `get_WindowHandle`, then calls `LayoutXaml`. `Sample::OnWindowSize` only re-runs layout. `Sample::PreTranslateMessage` queries `IDesktopWindowXamlSourceNative2` and lets XAML consume keyboard messages before the Win32 accelerator path sees them.

```cpp
// Common/Sample.cpp shape.
_windowsXamlManager = WindowsXamlManager::InitializeForCurrentThread();
_xamlSource = DesktopWindowXamlSource();
_xamlSource.as<IDesktopWindowXamlSourceNative>()->AttachToWindow(_hWnd);
native->get_WindowHandle(&_hWndXaml);
SetWindowPos(_hWndXaml, ..., SWP_SHOWWINDOW);
```

```cpp
// FilePicker/FilePicker.cpp shape.
FileOpenPicker picker;
picker.as<IInitializeWithWindow>()->Initialize(_hWnd);
auto file = co_await picker.PickSingleFileAsync();
```

That second snippet is the buried rule: many WinRT UI objects are not usable from desktop just because C++/WinRT can construct them. They still need an owner HWND through a classic COM interop interface.

## Discussion Claim To Verify

Claim: XAML Islands keyboard bugs are usually message routing and focus-boundary bugs, not proof that the hosted control is broken.

Why it matters to code: issue threads about Tab, accelerators, dead keys, and invisible focus often lead developers into control-specific workarounds. The hosting contract says the Win32 loop must offer messages to each `DesktopWindowXamlSource` through `IDesktopWindowXamlSourceNative2::PreTranslateMessage`, and focus must be moved explicitly into and out of the island.

Verification route:

1. Count every keyboard message before `TranslateMessage`.
2. Call `PreTranslateMessage` for the island.
3. Count messages where XAML reports `processed`.
4. Log `GotFocus`, `TakeFocusRequested`, host focus HWND, and island child HWND.
5. Repeat with the `PreTranslateMessage` call removed.

```cpp
BOOL processed = FALSE;
auto native2 = xamlSource.as<IDesktopWindowXamlSourceNative2>();
native2->PreTranslateMessage(&msg, &processed);
if (processed) {
    ++xamlConsumedKeyMessages;
    continue;
}

TranslateMessage(&msg);
DispatchMessage(&msg);
```

Interpretation: if Tab/accelerators fail only when `PreTranslateMessage` is removed, the claim is verified at the host contract. If messages are offered and focus still fails, move to `GotFocus` / `TakeFocusRequested` handling and control-specific focusability.

Claim: an island is a child HWND, so normal HWND rules still apply.

Verification route: print the parent HWND, island HWND, styles, z-order, `GetWindowRect`, `GetClientRect`, DPI, and focus owner after attach and after every `WM_SIZE` / `WM_DPICHANGED`.

```cpp
LONG_PTR style = GetWindowLongPtrW(island, GWL_STYLE);
HWND parent = GetParent(island);
wprintf(L"host=%p island=%p parent=%p style=%Ix dpi=%u\n",
        hostHwnd, island, parent, style, GetDpiForWindow(island));
```

Interpretation: clipping, airspace-like overlap, and resize drift are often ordinary child-window composition problems. XAML owns rendering inside the island; the Win32 host still owns placement, lifetime, and top-level chrome.

References: <https://learn.microsoft.com/en-us/windows/apps/desktop/modernize/xaml-islands/advanced-scenarios-xaml-islands-cpp> and <https://blogs.windows.com/windowsdeveloper/2018/11/02/xaml-islands-a-deep-dive-part-1/>.

## Connections

- `UWP Controls in Win32 HWND (uwplib).md` is the experimental counterpart.
- `Win32 To WinRT.md` and `Windows App SDK Bootstrapper.md` explain activation/runtime prerequisites.
- `../(MFC) Microsoft Foundation Classes/MFCStoreClient - MFC to WinRT Store Bridge.md` shows the alternative isolation pattern: call WinRT from a helper module instead of embedding XAML UI.
- `../(WPF) Windows Presenation Format/nodify - WPF Node Graph Editor.md` is the retained-mode desktop UI comparison point when the app can use WPF instead of XAML islands.

## Experiment Harness

Goal: verify the island is a real child HWND with independent focus and sizing.

```cpp
native->AttachToWindow(hostHwnd);
HWND island = nullptr;
native->get_WindowHandle(&island);

RECT host{}, child{};
GetClientRect(hostHwnd, &host);
GetWindowRect(island, &child);
wprintf(L"host=%p island=%p child=%ldx%ld focus=%d\n",
        hostHwnd, island, child.right-child.left, child.bottom-child.top,
        source.HasFocus());
```

Procedure: resize parent, tab into/out of the island, send accelerators through `PreTranslateMessage`, and attach a second island on the same UI thread.

Measured signal: child HWND dimensions, focus state, consumed accelerator count, attach HRESULT.

Failure interpretation: wrong top-level attachment or skipped XAML initialization produces attach/focus failures; size drift means the host forgot ordinary child-window layout. Reference: <https://learn.microsoft.com/windows/apps/desktop/modernize/xaml-islands/using-the-xaml-hosting-api>.

## References
- <https://github.com/MarkIngramUK/XamlIslands> - minimal Win32 C++ demonstration of `DesktopWindowXamlSource` hosting.
