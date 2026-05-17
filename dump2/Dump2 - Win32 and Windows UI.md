# Dump2 - Win32 and Windows UI

Starred GitHub repositories related to Win32, custom window decoration, and Windows UI toolkits.

---

## grassator/win32-window-custom-titlebar
https://github.com/grassator/win32-window-custom-titlebar

C99/C++98 implementation of a custom Win32 title bar. The key insight: extend the client area over the nonclient region using DWM (`DwmExtendFrameIntoClientArea` with all margins = 1), suppress default NC painting in `WM_NCCALCSIZE`, and draw your own caption in the client area. Hit testing for the caption drag region is done by returning `HTCAPTION` in `WM_NCHITTEST` when the cursor is above the button zone.

```cpp
// Extend client area over entire window to paint our own titlebar
MARGINS margins = {1, 1, 1, 1};
DwmExtendFrameIntoClientArea(hwnd, &margins);

// In WM_NCCALCSIZE: allow default processing but shift up by titlebar height
case WM_NCCALCSIZE:
    if (wParam) {
        NCCALCSIZE_PARAMS* params = (NCCALCSIZE_PARAMS*)lParam;
        params->rgrc[0].top -= TITLEBAR_HEIGHT; // reclaim nonclient space
    }
    return 0;

// In WM_NCHITTEST: route drag area to HTCAPTION
case WM_NCHITTEST: {
    LRESULT hit = DefWindowProcW(hwnd, msg, wParam, lParam);
    if (hit == HTCLIENT) {
        POINT pt = {GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
        ScreenToClient(hwnd, &pt);
        if (pt.y < TITLEBAR_HEIGHT && !IsInButtonArea(pt))
            return HTCAPTION;
    }
    return hit;
}
```

---

## zodiacon/AccessMask
https://github.com/zodiacon/AccessMask

Tool by Pavel Yosifovich (zodiacon) for decoding Windows access mask bits. References a known issue with the Win32 API: `ACCESS_MASK` is a 32-bit bitfield, and the upper 16 bits carry STANDARD_RIGHTS and GENERIC_RIGHTS while the lower 16 are object-specific. This tool lets you select an object type and decode all set bits symbolically.

```cpp
// Access mask layout
// Bits 0-15:  object-specific (e.g., FILE_READ_DATA, THREAD_SUSPEND_RESUME)
// Bits 16-23: standard rights (DELETE, READ_CONTROL, WRITE_DAC, SYNCHRONIZE)
// Bits 24-27: standard rights continued
// Bits 28-31: GENERIC_READ/WRITE/EXECUTE/ALL

// Check if a process has PROCESS_VM_READ access
DWORD mask = PROCESS_VM_READ; // 0x0010
bool canRead = (processAccessMask & mask) != 0;

// Generic rights mapping happens in the kernel via the object type's GenericMapping
GENERIC_MAPPING gm;
GetKernelObjectSecurity(...); // resolve GENERIC_READ -> specific file rights
MapGenericMask(&accessMask, &gm);
```

---

## strobejb/winspy
https://github.com/strobejb/winspy

WinSpy++ — a Spy++ clone for inspecting window properties, messages, and class info. The source shows how to enumerate all top-level windows with EnumWindows, retrieve extended window style info, and set up a WH_GETMESSAGE hook to intercept messages to any process window.

```cpp
// Enumerate all top-level windows and collect info
struct WndInfo { HWND hwnd; DWORD pid; wchar_t cls[256]; wchar_t title[256]; };
std::vector<WndInfo> windows;

EnumWindows([](HWND hwnd, LPARAM lp) -> BOOL {
    auto* v = (std::vector<WndInfo>*)lp;
    WndInfo info;
    info.hwnd = hwnd;
    GetWindowThreadProcessId(hwnd, &info.pid);
    GetClassNameW(hwnd, info.cls, 256);
    GetWindowTextW(hwnd, info.title, 256);
    v->push_back(info);
    return TRUE;
}, (LPARAM)&windows);

// Inspect extended styles
LONG_PTR exStyle = GetWindowLongPtrW(hwnd, GWL_EXSTYLE);
bool isToolWindow = (exStyle & WS_EX_TOOLWINDOW) != 0;
bool isLayered    = (exStyle & WS_EX_LAYERED)    != 0;
```

---

## Aegisub/w32dumper
https://github.com/Aegisub/w32dumper

Minimal Win32 minidump helper: registers an unhandled exception filter, calls MiniDumpWriteDump to capture a full or mini dump to a file. The Aegisub project uses it to let end users generate crash reports without needing a full debugger installed.

```cpp
// Register crash dump handler at startup
SetUnhandledExceptionFilter([](EXCEPTION_POINTERS* ep) -> LONG {
    HANDLE hFile = CreateFileW(L"crash.dmp", GENERIC_WRITE, 0,
        nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hFile != INVALID_HANDLE_VALUE) {
        MINIDUMP_EXCEPTION_INFORMATION mei;
        mei.ThreadId          = GetCurrentThreadId();
        mei.ExceptionPointers = ep;
        mei.ClientPointers    = FALSE;
        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
            hFile, MiniDumpWithFullMemory, &mei, nullptr, nullptr);
        CloseHandle(hFile);
    }
    return EXCEPTION_CONTINUE_SEARCH; // let default handler run too
});
```

---

## sotanakamura/winui3-without-midl
https://github.com/sotanakamura/winui3-without-midl

Demonstrates building a WinUI 3 app with C++ and XAML but without the MIDL (Interface Definition Language) toolchain. This removes a major friction point: normally WinRT components require .idl files processed by midlrt. By using WinRT C++ projections (cppwinrt) directly, you can create a page class, override Frame navigation, and host controls without any MIDL-generated stubs.

```cpp
// Using cppwinrt directly - no .idl file needed for the host exe
// Include the generated winrt headers from nuget package
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>

struct App : winrt::implements<App, winrt::Microsoft::UI::Xaml::IApplicationOverrides> {
    void OnLaunched(winrt::Microsoft::UI::Xaml::LaunchActivatedEventArgs const&) {
        window = winrt::make<MainWindow>();
        window.Activate();
    }
    winrt::Microsoft::UI::Xaml::Window window{nullptr};
};
```

---

## sotanakamura/winui3-command-line
https://github.com/sotanakamura/winui3-command-line

Building WinUI 3 apps using command-line tools only (cl.exe + cppwinrt + NuGet). Avoids the Visual Studio project system overhead. Key: invoke `cppwinrt.exe -input sdk` to generate the WinRT headers, compile with `/std:c++20`, and link against `windowsapp.lib`. No .vcxproj required.

```batch
:: Generate cppwinrt projection headers
cppwinrt.exe -input sdk -output include

:: Compile
cl /std:c++20 /EHsc /I include main.cpp ^
   /link windowsapp.lib ole32.lib user32.lib
```

---

## tbindi723/IMGuiTool
https://github.com/tbindi723/IMGuiTool

Friend's project: a Win32+ImGui debug tool window. Shows the standard ImGui Win32 backend setup — `ImGui_ImplWin32_Init`, message pump plumbing, and `ImGui_ImplDX11_NewFrame`. A useful minimal reference for embedding ImGui into an existing Win32 application.

```cpp
// Standard ImGui Win32+DX11 setup
IMGUI_CHECKVERSION();
ImGui::CreateContext();
ImGuiIO& io = ImGui::GetIO();
io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

ImGui_ImplWin32_Init(hwnd);
ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

// Render loop
ImGui_ImplDX11_NewFrame();
ImGui_ImplWin32_NewFrame();
ImGui::NewFrame();
// ... your windows here ...
ImGui::Render();
g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
```
