Windows 10 1809+ exposes undocumented dark mode APIs in `uxtheme.dll`. Key functions—`AllowDarkModeForApp` (ordinal 132), `AllowDarkModeForWindow` (133), `RefreshImmersiveColorPolicyState` (104)—must be loaded by ordinal. After enabling, call `SetWindowTheme` and send `WM_THEMECHANGED` to force controls to repaint in dark mode.

```cpp
#include <windows.h>
#include <uxtheme.h>

using fnAllowDarkModeForApp    = BOOL(WINAPI*)(BOOL);
using fnAllowDarkModeForWindow = BOOL(WINAPI*)(HWND, BOOL);
using fnRefreshColorPolicy     = void(WINAPI*)();

static fnAllowDarkModeForApp    pAllowDarkModeForApp    = nullptr;
static fnAllowDarkModeForWindow pAllowDarkModeForWindow = nullptr;
static fnRefreshColorPolicy     pRefreshColorPolicy     = nullptr;

void InitDarkMode() {
    HMODULE hUx = LoadLibraryExW(L"uxtheme.dll", nullptr,
                                 LOAD_LIBRARY_SEARCH_SYSTEM32);
    pAllowDarkModeForApp    = (fnAllowDarkModeForApp)   GetProcAddress(hUx, MAKEINTRESOURCEA(132));
    pAllowDarkModeForWindow = (fnAllowDarkModeForWindow)GetProcAddress(hUx, MAKEINTRESOURCEA(133));
    pRefreshColorPolicy     = (fnRefreshColorPolicy)    GetProcAddress(hUx, MAKEINTRESOURCEA(104));

    if (pAllowDarkModeForApp)    pAllowDarkModeForApp(TRUE);
    if (pRefreshColorPolicy)     pRefreshColorPolicy();
}

void EnableWindowDarkMode(HWND hwnd) {
    if (pAllowDarkModeForWindow) pAllowDarkModeForWindow(hwnd, TRUE);
    SetWindowTheme(hwnd, L"DarkMode_Explorer", nullptr);
    SendMessage(hwnd, WM_THEMECHANGED, 0, 0);
}
```

## References
- https://github.com/ysc3839/win32-darkmode

https://github.com/HFaeiro/ThemeEngine
DwmSetWindowAttribute can set dark mode and Mica effects. DWMWA_USE_IMMERSIVE_DARK_MODE enables the dark title bar; DWMWA_SYSTEMBACKDROP_TYPE = 2 enables Mica on Windows 11.
```cpp
BOOL dark = TRUE;
DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &dark, sizeof(dark));
INT backdrop = 2; // DWMSBT_MAINWINDOW = Mica
DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &backdrop, sizeof(backdrop));

// Also apply to any comctl32 controls via SetWindowTheme
SetWindowTheme(hCtrl, L"DarkMode_Explorer", nullptr);
InvalidateRect(hwnd, nullptr, TRUE);
```

https://github.com/MicaForEveryone/MicaForEveryone/blob/669b6b21df5801faedba112981f922bd3338c956/MicaForEveryone.App/Services/RuleService.cs#L258-L271
MicaForEveryone applies DWM backdrop attributes per-window based on process rules. The key attribute is DWMWA_SYSTEMBACKDROP_TYPE (38) available on Windows 11 Build 22000+.
```cpp
// DWMWA_SYSTEMBACKDROP_TYPE values:
// 0 = Auto, 1 = None, 2 = Mica, 3 = Acrylic, 4 = Tabbed
int backdropType = 2;
DwmSetWindowAttribute(hwnd, 38 /*DWMWA_SYSTEMBACKDROP_TYPE*/,
    &backdropType, sizeof(backdropType));
```

