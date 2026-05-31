# MFCStoreClient - MFC to WinRT Store Bridge

MFCStoreClient shows how a classic MFC desktop app can call `Windows.Services.Store` when distributed through Desktop Bridge/MSIX. The architectural point is isolation: keep WinRT/C++/CX code in a helper DLL and late-load it from the MFC executable, rather than enabling `/ZW` across the whole legacy project and contaminating unrelated translation units with projection rules and compiler switches.

That pattern still matters even if you replace C++/CX with C++/WinRT. The classic app remains a native MFC executable with ordinary startup and fallback behavior; the WinRT-facing module is loaded only when package identity and OS support exist. Connect this to Windows App SDK bootstrapping and Win32-to-WinRT notes: all three are about adding modern Windows APIs without rewriting the host application.

## Source Shape

Source pass: `MFCClient/MFCClientDlg.cpp` shows the MFC side as a late-bound DLL boundary. The dialog does ordinary MFC initialization, then loads the WinRT-aware DLL only on supported Windows and binds a small C export table.

```cpp
HMODULE storeDll = LoadLibraryW(L"WindowsStoreDLL.dll");

auto store_initialize =
    reinterpret_cast<WindowsStoreInitializeFunc>(
        GetProcAddress(storeDll, "store_initialize"));
auto store_purchase =
    reinterpret_cast<WindowsStorePurchaseFunc>(
        GetProcAddress(storeDll, "store_purchase"));

store_initialize(&storePtr, statusHwnd, LicenseChangedCallback, this);
```

Source pass: `WindowsStoreDLL/WindowsStoreImpl.cpp` shows the WinRT side. The helper owns `StoreContext`, initializes it with the MFC HWND through interop, subscribes to license changes, and performs async Store calls away from the MFC translation units.

```cpp
StoreContext context = StoreContext::GetDefault();
auto initWindow = context.as<IInitializeWithWindow>();
initWindow->Initialize(ownerHwnd);

auto token = context.OfflineLicensesChanged(
    [](StoreContext const&, IInspectable const&) { /* notify MFC host */ });

auto result = co_await product.StoreProduct().RequestPurchaseAsync();
```

## Connections

- `../(WinRT) Windows Runtime/Win32 To WinRT.md` is the smaller C++ bridge.
- `../(WinRT) Windows Runtime/Windows App SDK Bootstrapper.md` is the runtime-binding concern for unpackaged modern APIs.
- `../(WinRT) Windows Runtime/Xaml Islands Minimal Win32 Host.md` is the UI-hosting branch; this note is the service/API branch.
- `../(WTL) Windows Template Library/WIL (Windows Implementation Library).md` is the modern cleanup style that would make the late-bound export table less fragile.

## Experiment Harness

Goal: test the late-bound WinRT helper boundary without making the MFC app depend on WinRT at startup.

```cpp
HMODULE dll = LoadLibraryW(L"WindowsStoreDLL.dll");
auto init = dll ? (WindowsStoreInitializeFunc)GetProcAddress(dll, "store_initialize") : nullptr;
wprintf(L"dll=%p init=%p gle=%lu packaged=%ld\n",
        dll, init, GetLastError(), GetCurrentPackageFullName(&len, nullptr));
```

Procedure: run unpackaged, packaged without Store identity, and packaged with Store test identity if available.

Measured signal: DLL load result, export lookup result, package identity, `StoreContext::GetDefault`/`IInitializeWithWindow` HRESULT from the helper.

Failure interpretation: MFC startup can be healthy while the Store/WinRT helper is unavailable; that is the point of the DLL boundary. Reference: <https://learn.microsoft.com/en-us/windows/uwp/monetize/in-app-purchases-and-trials>.

## References
- <https://github.com/microsoft/MFCStoreClient> - Microsoft sample for accessing Store APIs from an MFC desktop app through a WinRT helper component.
