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
