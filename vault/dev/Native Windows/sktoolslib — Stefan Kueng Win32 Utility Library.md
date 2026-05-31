# sktoolslib - Stefan Kueng Win32 Utility Library

Stefan Kueng's shared C++ utility library backs practical Windows tools such as TortoiseSVN/TortoiseGit-adjacent components, grepWin, and BowPad. The library is a good counterweight to framework-heavy desktop code: RAII wrappers for HANDLE/HKEY/GDI objects, registry and path helpers, MRU/menu utilities, thread-pool glue, file-system watching, and thumbnail/diff-cache infrastructure gathered from shipping shell tools.

The important connection is to WTL, WIL, and Win32xx. All three try to make raw Win32 less error-prone, but sktoolslib is application-maintainer code rather than a public abstraction layer: its APIs reflect years of Explorer integration, filesystem edge cases, and native UI plumbing rather than a clean teaching sample.

Code contribution: mine it for RAII around `HANDLE`, `HKEY`, and GDI objects, plus shell/file helpers that show how shipping tools wrap raw Win32 failure paths.

## Source Shape

Source pass: `AeroGlass.cpp` shows the library's pragmatic style: dynamically bind optional Windows DLL exports, expose a stable wrapper method, and translate missing functions or API failures into ordinary `HRESULT`s. This is utility-library code for apps that must run across Windows versions without turning every call site into a loader probe.

```cpp
using DWM_EXTEND_FRAME_INTO_CLIENT_AREA =
    HRESULT (__stdcall *)(HWND, const MARGINS *);

HMODULE dwm = LoadLibraryW(L"dwmapi.dll");
auto pfn = reinterpret_cast<DWM_EXTEND_FRAME_INTO_CLIENT_AREA>(
    GetProcAddress(dwm, "DwmExtendFrameIntoClientArea"));

HRESULT ExtendFrame(HWND hwnd, const MARGINS *margins)
{
    if (!pfn) return HRESULT_FROM_WIN32(ERROR_PROC_NOT_FOUND);
    return pfn(hwnd, margins);
}
```

Source pass: `AeroControls.cpp` shows the other half: owner/subclass drawing over normal HWND controls using `SendMessage`, `WM_PRINTCLIENT`, GDI/GDI+ objects, and cached bitmaps. That places sktoolslib near WTL/MFC/common-control notes, not near WinRT/XAML abstractions.

## Connections

- `(WTL) Windows Template Library/WIL (Windows Implementation Library).md` is the general Microsoft RAII/error helper counterpart.
- `(WTL) Windows Template Library/Win32xx (Header-Only ATL-Style Wrapper).md` and `(WTL) Windows Template Library/WCL - Win32 C++ Class Library.md` are framework alternatives.
- `Shell/Explorer++ (Tabbed Win32 Explorer).md` is the shell-app scale comparison: both are native C++ codebases that wrap Shell COM and Win32 instead of replacing them with a cross-platform GUI toolkit.
- `libvalinet - ExplorerPatcher Helpers.md` is the private-shell patching contrast; sktoolslib is utility infrastructure for maintained desktop tools.

## Experiment Harness

Goal: compare utility-wrapper behavior against direct Win32 calls on optional OS features.

```cpp
HMODULE dwm = LoadLibraryW(L"dwmapi.dll");
auto p = GetProcAddress(dwm, "DwmExtendFrameIntoClientArea");
HRESULT hr = p ? WrappedExtendFrame(hwnd, &margins)
               : HRESULT_FROM_WIN32(ERROR_PROC_NOT_FOUND);
printf("dwm=%p proc=%p hr=%08lx\n", dwm, p, hr);
```

Procedure: run on supported and unsupported Windows versions or with the target DLL deliberately absent in a test harness; compare wrapper HRESULTs with raw `GetLastError`.

Measured signal: DLL/proc presence, wrapper result, raw API result, cleanup count for GDI/HANDLE objects.

Failure interpretation: a good utility library compresses version probing at the boundary while preserving enough error detail for callers to make policy decisions.

## References
- <https://github.com/stefankueng/sktoolslib> - production-oriented helper library for native Windows desktop utilities.
