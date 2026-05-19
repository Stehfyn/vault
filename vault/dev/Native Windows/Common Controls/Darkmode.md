# Darkmode

Native Win32 dark mode is a patchwork. Classic controls are themed through UxTheme, top-level chrome through DWM attributes such as `DWMWA_USE_IMMERSIVE_DARK_MODE`, and older Windows 10 builds require undocumented UxTheme ordinals popularized by `ysc3839/win32-darkmode`. Calling one function is not enough; every HWND that owns themed drawing may need `AllowDarkModeForWindow`, `SetWindowTheme`, and invalidation on `WM_THEMECHANGED`.

## DWM Chrome

ThemeEngine and MicaForEveryone contribute the public DWM side: titlebar color and backdrop are per-window attributes, guarded by OS build support.

```cpp
BOOL dark = TRUE;
DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE,
                      &dark, sizeof(dark));

DWORD backdrop = 2; // DWMSBT_MAINWINDOW on supported Windows 11 builds.
DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE,
                      &backdrop, sizeof(backdrop));
```

## UxTheme Controls

The `win32-darkmode` link contributes the missing classic-control layer. `SetWindowTheme` and invalidation are what the child controls actually see; DWM attributes alone do not recolor them.

```cpp
SetWindowTheme(list_view, L"Explorer", nullptr);
SendMessageW(list_view, WM_THEMECHANGED, 0, 0);
InvalidateRect(list_view, nullptr, TRUE);
```

## References

- <https://github.com/ysc3839/win32-darkmode> - canonical undocumented UxTheme ordinal shim.
- <https://github.com/HFaeiro/ThemeEngine> - DWM dark titlebar/backdrop attribute usage.
- <https://github.com/MicaForEveryone/MicaForEveryone/blob/669b6b21df5801faedba112981f922bd3338c956/MicaForEveryone.App/Services/RuleService.cs#L258-L271> - process-rule based use of `DWMWA_SYSTEMBACKDROP_TYPE`.

## Connections

- `Dark Mode (C Port).md` is the C-only version of the ordinal approach.
- `Custom Menubar.md` covers the remaining menubar gap.
- `Custom Frame` entries outside this folder go deeper on non-client theming.
