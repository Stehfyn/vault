# Native Windows

This directory is an index for low-level Windows desktop material: Win32, COM, WinRT, shell, graphics, packaging, diagnostics, app compatibility, and the awkward overlap between documented SDK APIs and the behavior developers actually depend on. The entries below group references by engineering use so each link has a reason to exist beyond being another URL in the pile.

## Coalesced Topic Map
- ABI and loader substrate: `Headers/winnt.h.md`, `Headers/ntdll.lib.md`, `(NTAPI) Undocumented Kernel/`, `(PE) Portable Executable Format/`.
- Windowing and controls: `Common Controls/`, `Message Queue/`, `Hooks/`, `DPI Awareness/`, `Custom Frame/`.
- Shell integration: `Shell/Shell Execute.md`, `Shell/Shell Shortcuts.md`, `Shell/Shell Link Tracking (Object IDs and Distributed Link Tracking).md`, `Shell/Windows Explorer Integration.md`, `Shell/Notification Area (Tray).md`, `Shell/Legacy Shell References.md`.
- Graphics/composition: `(GDI) Graphics Device Interface/`, `(DWM) Desktop Window Manager/`, `(DX) DirectX/`, `(GL) OpenGL/`, `Display Control/`.
- Runtime and deployment: `(CRT) C Runtime/`, `Windows Installer/`, `(REG) Windows Registry/`, `(WinRT) Windows Runtime/`, `App Compatibility/`.
- Diagnostics and security research: `(ETW) Event Tracing For Windows/`, `(WMI) Windows Management Instrumentation/`, `OpSec/`, `Services/`.

## Overarching Topic Graph
- `HWND` is the central seam: `Message Queue/` explains delivery, `Common Controls/` explains child/control protocols, `Custom Frame/` explains non-client takeover, `DPI Awareness/` explains coordinate validity, and `Hooks/`/`Input/` explain observation and synthesis.
- COM is the ABI spine above raw Win32: Shell items, taskbar APIs, file dialogs, WMI, DirectComposition, DXGI, Media Foundation, WinRT, and WIL all reduce to interface identity, `QueryInterface`, reference counting, HRESULTs, and apartment/threading assumptions.
- DWM/DXGI/DirectComposition form the presentation triangle: DXGI owns adapter and swap-chain identity, DComp owns retained visuals and commit timing, and DWM owns desktop integration, thumbnails, backdrops, shadows, and most modern non-client behavior.
- NT and PE material explains what Win32 hides: object namespaces, process parameters, native strings, loader state, section mapping, import/export resolution, status codes, and the split between documented SDK declarations and private ntdll/win32k contracts.
- Shell and packaging are one deployment surface, not two: shortcuts, known folders, app identity, MSIX/AppX, WinAppSDK bootstrap, Explorer integration, notification area state, and AppCompat shims decide how an EXE becomes a Windows application.
- Diagnostics should be chosen by layer: ETW for time-ordered events, WMI/SCM for system inventory and services, dump/debug APIs for process state, Spy++/window tools for USER objects, and graphics capture tools for compositor/presentation state.
- Reversing notes should route back to legitimate boundaries: private DWM exports connect to DXGI shared resources; shell patching connects to COM/DirectUI; driver and kernel notes connect to object manager, IOCTL, signing, and ETW visibility.

`Story Routes.md` is the implementation backlog above this map. It turns the local note clusters into probes, repros, bridges, matrices, and forensics helpers for window behavior, graphics, modern API identity, compatibility, diagnostics, and trust-sensitive API use.

## Cross-Reference Routes
- To build a custom top-level window: start with `Common Controls/Borderless Window.md`, then `Custom Frame/Custom Chrome Sample (NCCALCSIZE).md`, then `(DWM) Desktop Window Manager/Title Bar Customization.md`, `Common Controls/Darkmode.md`, and `DPI Awareness/Per-Window DPI Awareness.md`. That path keeps style bits, non-client hit testing, dark titlebar attributes, and per-monitor sizing in the same mental model.
- To reason about composition and capture: read `(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md` before `(DX) DirectX/Windows Composition Engine.md`, then use `(DWM) Desktop Window Manager/DWM Internals Documentation.md`, `(DWM) Desktop Window Manager/DwmGetDxSharedSurface Window Capture.md`, and `(GDI) Graphics Device Interface/How to Capture the Screen.md` to separate documented swap-chain ownership from undocumented redirection-surface capture.
- To bridge Win32 into modern Windows UI: pair `(COM) Component Object Model/COM in plain C.md` with `(WinRT) Windows Runtime/WinRT is fundamentally COM.md`, then use `(WinRT) Windows Runtime/Windows App SDK Bootstrapper.md`, `(WinRT) Windows Runtime/WinUI 3 in Pure C (No cppwinrt).md`, and `Custom Frame/Acrylic via WinRT Composition Interop.md`. This prevents treating WinRT, XAML Islands, and WinAppSDK deployment as one undifferentiated "modern UI" blob.
- To extend Explorer or shell UX: start with `Shell/Shell Items and Folders.md`, `Shell/Known Folders.md`, and `Shell/Shell Execute.md` for supported COM/API surfaces; then compare `Shell/DUI70 — Shell DirectUI Framework.md`, `Shell/Explorer Patcher (Win11 Shell Restore).md`, `libvalinet — ExplorerPatcher Helpers.md`, and `Custom Frame/Immersive Context Menu (Explorer Look-Alike).md` for unsupported patching and shell-internals work.
- To debug runtime behavior: combine `(ETW) Event Tracing For Windows/`, `Examples/wintrace.md`, `(WMI) Windows Management Instrumentation/WMI C++ Usage.md`, `Services/Win32 Service Template.md`, and `(NTAPI) Undocumented Kernel/Process Dump Tools.md`. ETW explains what happened, WMI/SCM explain long-lived system state, and dumps/native APIs explain the process boundary.

The rule for this page is strict: external links stay only when they point at code, ABI contracts, or a doc page whose declarations are directly useful while writing code. Reading-list links should be promoted into a specific note with a concrete code contribution or removed.

## Canonical Code Shapes
These snippets are the local baseline for interpreting many links below. They are intentionally small, but each one marks a subsystem boundary that recurs throughout the vault.

### HWND and message lifetime
```cpp
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM w, LPARAM l) {
    switch (msg) {
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    case WM_DESTROY: PostQuitMessage(0); return 0;
    }
    return DefWindowProcW(hwnd, msg, w, l);
}

MSG m;
while (GetMessageW(&m, nullptr, 0, 0) > 0) {
    TranslateMessage(&m);
    DispatchMessageW(&m);
}
```

### COM activation and interface ownership
```cpp
wil::com_ptr<IFileOpenDialog> dialog;
CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&dialog));

if (SUCCEEDED(dialog->Show(hwnd))) {
    wil::com_ptr<IShellItem> item;
    dialog->GetResult(&item);
}
```

### Shell-mediated launch
```cpp
SHELLEXECUTEINFOW sei = { sizeof(sei) };
sei.fMask = SEE_MASK_NOCLOSEPROCESS;
sei.lpVerb = L"open";
sei.lpFile = L"notepad.exe";
sei.nShow = SW_SHOWNORMAL;
ShellExecuteExW(&sei);
```

### Native/NT string boundary
```cpp
UNICODE_STRING name;
RtlInitUnicodeString(&name, L"\\??\\C:\\Temp\\file.txt");
```

### DXGI adapter boundary
```cpp
wil::com_ptr<IDXGIFactory6> factory;
CreateDXGIFactory2(0, IID_PPV_ARGS(&factory));

wil::com_ptr<IDXGIAdapter1> adapter;
for (UINT i = 0; factory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i) {
    DXGI_ADAPTER_DESC1 desc = {};
    adapter->GetDesc1(&desc);
    adapter.reset();
}
```

## Core API and ABI
- <https://learn.microsoft.com/en-us/windows/win32/api/> - canonical Win32 API index; use it for function signatures, required headers, libraries, minimum client versions, and structure layout.
- <https://learn.microsoft.com/en-us/previous-versions/windows/desktop/> - legacy desktop documentation index; still matters for DirectShow, Shell, multimedia, and APIs that were removed from the current Learn navigation but not from old code.
- <https://learn.microsoft.com/en-us/windows/win32/winprog64/designing-64-bit-compatible-interfaces> and <https://learn.microsoft.com/en-us/windows/win32/winprog64/rules-for-using-pointers> - ABI hygiene for handles, pointer-sized integers, RPC/COM boundaries, and structures that cross 32/64-bit process lines.
- <https://learn.microsoft.com/en-us/windows/win32/api/winternl/ns-winternl-string> - `UNICODE_STRING` reference; the small struct that marks the boundary between Win32 string APIs and native NT interfaces.
- <https://github.com/reactos/reactos> and <https://doxygen.reactos.org/d0/db9/ntoskrnl_2ke_2clock_8c_source.html#l00228> - ReactOS is not Windows source, but it is often the best public way to study compatible object-manager, kernel, and timekeeping behavior before validating against real Windows.

## Raw Win32 Samples
- <https://github.com/mity/c-win32> - small C Win32 examples from the mCtrl author; useful when a full MFC/WTL/WinUI sample hides the actual message and control plumbing.
- <https://github.com/rprichard/win32-console-docs> - focused console-host documentation, especially modern VT mode and historical console quirks.
- <https://github.com/rrmhearts/Serial-Programming-Win32API-C> - serial-port examples around `CreateFile`, `DCB`, timeouts, and overlapped I/O.
- <https://github.com/federicadomani/TinyWinSpyOff> - tiny window-inspection utility; keep near hooks, Spy++ clones, and HWND-tree tools.
- <https://github.com/7etsuo/windows-api-function-cheatsheets> - quick lookup aid, not a substitute for Learn, but useful when triaging unfamiliar Win32 call families.

## UI, Shell, and Desktop Integration
- <https://github.com/fobrs/Win2DinMFC> - MFC bridge into Direct2D-style drawing; belongs with the MFC and Direct2D notes rather than generic Win32.
- <https://github.com/ChrisAnd1998/TaskbarX> and <https://github.com/ozone10/Rainmeter-TranslucentRM> - examples of taskbar/window appearance manipulation; read beside custom-frame, layered-window, DWM, and shell-patching entries.
- <https://github.com/qqkookie/XPAccApps> - legacy XP accessory source; useful mostly for studying older UI/resource patterns and compatibility assumptions.
- <https://answers.microsoft.com/en-us/windows/forum/all/restore-old-right-click-context-menu-in-windows-11/a62e797c-eaf3-411b-aeec-e460e6e5a82a> - user-facing registry workaround thread for Windows 11 classic context menus; pair with shell extension and Explorer customization notes, not with API references.

## Media, Graphics, and Capture
- <https://www.codeproject.com/Articles/5051/Various-methods-for-capturing-the-screen> - old but still useful survey of GDI capture paths; compare with DXGI Output Duplication and Windows Graphics Capture notes.
- <https://learn.microsoft.com/en-us/previous-versions/windows/desktop/mstv/creating-stream-buffer-graphs>, <https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ee415253(v=vs.85)>, and <https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ee415252(v=vs.85)> - legacy DirectShow stream-buffer material; keep for old TV/DVR code and COM graph-building examples.
- <https://learn.microsoft.com/en-us/windows/uwp/audio-video-camera/media-playback> - UWP `MediaPlayer` documentation; useful as the modern WinRT media counterpoint to DirectShow.
- <https://github.com/microsoft/Windows-appsample-photo-editor/blob/d57f02afab83ad506584c71a06dc550c1d74ea95/PhotoEditor/DetailPage.cpp#L444-L480> - concrete UWP image-loading and UI-update sample; belongs with WIC/WinRT image handling.
- <https://stackoverflow.com/questions/67988506/magnification-windows-api-how-to-add-smoothing-anti-aliasing/67990364#67990364> - practical limitation note for the Magnification API; keep because smoothing/quality is exactly the kind of behavior the API reference under-specifies.

## Timing, Threads, and Process Lifetime
- <https://web.archive.org/web/20120323170914/http://blog.gabefrost.com/?p=25> and <https://blat-blatnik.github.io/computerBear/making-accurate-sleep-function/> - timer-resolution and accurate-sleep discussions; compare with MMCSS, waitable timers, and frame pacing notes.
- <https://www.codeproject.com/Articles/5377342/VCplusplus-30-Multithreading-Mistakes-on-Windows> - broad Windows threading pitfall checklist; use as review material, not as a canonical API source.
- <https://handmade.network/forums/t/8892-safely_exiting_a_windows_process_with_multiple_running_threads> - concrete discussion of shutdown coordination and why killing threads is the wrong primitive.
- <https://stackoverflow.com/questions/3155782/what-is-the-difference-between-wm-quit-wm-close-and-wm-destroy-in-a-windows-pr> - good message-lifetime distinction: request close, destroy window, then quit the thread loop.
- <https://github.com/endurodave/ThreadWin>, <https://github.com/FabienCarmagnac/win32_sem>, and <https://github.com/fuyijun1989/LibWinCo/blob/master/libwinco.c> - small wrappers/samples for threads, semaphores, and fibers.

## Input and Automation
- <https://github.com/myfreeer/numlock/blob/master/numlock.c>, <https://github.com/myfreeer/sendinput/blob/master/command.h>, <https://github.com/myfreeer/input-switch>, and <https://github.com/ZaneA/Win32-Hacks/blob/master/Gapslock/main.c> - narrow keyboard state, `SendInput`, and layout-switching examples. Keep them in the input cluster because they teach edge cases better than a generic "keyboard API" note.
- <https://github.com/tomasr/wsspi/blob/master/inc/sspicred.h> - SSPI credential helper header; relevant when native code needs security-package credentials without pulling in a larger framework.

## Build, Runtime, and Deployment
- <https://github.com/bvernoux/mingw-bundledlls> - packaging checklist for MinGW runtime DLL dependencies.
- <https://github.com/microsoft/STL?tab=readme-ov-file#block-diagram> - MSVC STL project layout and architecture map; useful when debugging CRT/STL build behavior.
- <https://learn.microsoft.com/en-us/cpp/error-messages/tool-errors/vectorizer-and-parallelizer-messages?view=msvc-170> - MSVC vectorizer diagnostics; place near performance/compiler notes.
- <https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/parallel/openmp/a-examples.md> - OpenMP examples for MSVC.
- <https://learn.microsoft.com/en-us/visualstudio/install/build-tools-container?view=vs-2022> - official Build Tools container install guidance; keep with reproducible Windows build environments.
- <https://pve.proxmox.com/wiki/Windows_10_guest_best_practices> - VM tuning checklist for Windows guests; useful for test labs, driver work, and performance measurement.

## MFC and Utility Libraries
- <https://www.codeproject.com/Articles/519/PJ-Naughter-s-Freeware-Library> - PJ Naughter's long-running MFC/Win32 utility library index; many older projects still depend on these classes.
- <https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/mfc/mfc-desktop-applications.md> - Microsoft MFC overview; keep as the official baseline beside sample repos.
- <https://github.com/jwhu1024/MFC> and <https://files.cbps.xyz/archive/ipw/exe/source/> - sample/source collections for old MFC study; inspect before treating either as production guidance.

## Security and Reversing
- <https://github.com/OpenWireSec/metasploit/tree/master> and <https://github.com/OpenWireSec/metasploit/blob/master/external/source/meterpreter/source/common/arch/win/i386/base_inject.c> - offensive Windows payload/injection source. Keep these in OpSec/reversing context, not as general application-programming examples.
- <https://github.com/CesarBerriot/hard_assert/blob/master/include/hard_assert.h> - small hard-assert/debug-break helper; useful only as a diagnostic macro reference.

## Historical and Miscellaneous
- <https://github.com/w3c/libwww> - historical HTTP library source; useful for portability archaeology more than modern Windows networking.
- <https://renenyffenegger.ch/notes/Windows/dirs/Windows/System32/index> - System32 file index for quick DLL/binary lookup while spelunking.
- <https://files.rg-adguard.net/version/f0bd8307-d897-ef77-dbd6-216fefbe94c5> - Windows package listing mirror; keep only for locating legacy install media/update identifiers, then verify hashes elsewhere.

## Notes to Promote
- COMDAT folding belongs with linker/PE notes: it is the linker optimization that merges identical functions/data sections emitted into COMDATs, which affects symbol identity, stack traces, and address-based tricks.
- The UWP/WinUI 2 File Explorer shell can be launched with `explorer shell:AppsFolder\c5e2524a-ea46-4f67-841f-6a9465d9d515_cw5n1h2txyewy!App`; move this to Shell or WinRT after verifying which Windows builds still carry it.
