# Win32 Mica

Enable Mica/Backdrop on a classic Win32 window using `DwmSetWindowAttribute` (Windows 11+).

```cpp
#include <windows.h>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

DWM_SYSTEMBACKDROP_TYPE type = DWMSBT_MAINWINDOW;
DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &type, sizeof(type));

BOOL dark = TRUE;
DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &dark, sizeof(dark));
```

## References
- https://github.com/littlewhitecloud/win32mica/blob/main/win32mica/win32mica.cpp

## Source Code Reading

`littlewhitecloud/win32mica` is a tiny DLL plus Python wrapper. The useful files are `win32mica/win32mica.cpp`, `win32mica/win32mica.py`, and `example/micawin32.cpp`.

`ApplyDocumentMica(hwnd, theme, micaalt)` does two DWM calls:

```cpp
DwmSetWindowAttribute(hwnd, 20, &theme, sizeof(int));
DwmSetWindowAttribute(hwnd, mica_entry, &mica_value, sizeof(int));
```

The first attribute enables immersive dark mode. The second selects Mica versus Mica Alt through the documented backdrop attribute path. `ApplyUndocumentMica` uses the older private attribute/value pair for builds before the public contract settled. The Python wrapper chooses the branch with `getwindowsversion().build < 22523`.

That build gate is a demo shortcut. A production probe should call the documented `DWMWA_SYSTEMBACKDROP_TYPE` path first, inspect the `HRESULT`, and only fall back to the private path when the documented call is unavailable or visibly inert.

### Claim -> Probe

Claim: "Mica is only a top-level backdrop/caption effect." Probe by applying the function to a top-level overlapped HWND and to a child control HWND. Interpretation: DWM backdrop attributes are meaningful on the top-level surface; they do not theme the client controls. Pair this with dark-mode/uxtheme notes when you need controls to change too.

## Connections
- `Dark Mode (Uxtheme Ordinals).md` and `../Common Controls/Darkmode.md` cover the client-control side; Mica only fixes the top-level backdrop/caption surface.
- `Mica Backport for Windows 10.md` explains the private fallback route when `DWMWA_SYSTEMBACKDROP_TYPE` is unavailable.
- `Acrylic via WinRT Composition Interop.md` and `Acrylic with DirectComposition.md` are heavier composition routes when a DWM attribute is not enough.
- `Custom Titlebar (Minimal Recipe).md` is the frame-geometry route that usually surrounds a Mica client area.
