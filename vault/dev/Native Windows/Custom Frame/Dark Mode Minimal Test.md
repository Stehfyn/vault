# Dark Mode Minimal Test

Minimal test harness for the dark-mode private API surface — `SetPreferredAppMode`/`AllowDarkModeForWindow` from uxtheme.dll ordinals plus `DwmSetWindowAttribute(DWMWA_USE_IMMERSIVE_DARK_MODE)` — useful as a sanity check when porting the bigger libraries (cf. ysc3839/win32-darkmode #25, ozone10/win32-darkmodelib #16, TBOpen/CWin32DarkMode #18). The reason this is a "test" and not a one-liner: the uxtheme ordinals (`#135` for `SetPreferredAppMode`, previously `#135` was `AllowDarkModeForApp` pre-1903) changed between 1809 and 1903, and `DWMWA_USE_IMMERSIVE_DARK_MODE` was attribute `19` before 20H1 and `20` after — getting either wrong silently leaves the titlebar white.

## Source Shape

The minimal test shape is dynamic ordinal loading plus a DWM caption attribute. It is a compatibility probe, not a stable SDK surface.

```cpp
auto uxtheme = LoadLibraryW(L"uxtheme.dll");
auto SetPreferredAppMode = reinterpret_cast<SetPreferredAppMode_t>(
    GetProcAddress(uxtheme, MAKEINTRESOURCEA(135)));
auto AllowDarkModeForWindow = reinterpret_cast<AllowDarkModeForWindow_t>(
    GetProcAddress(uxtheme, MAKEINTRESOURCEA(133)));

SetPreferredAppMode(AllowDark);
AllowDarkModeForWindow(hwnd, true);

BOOL dark = TRUE;
DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE,
                      &dark, sizeof(dark));
```

The useful test is whether controls repaint after `WM_THEMECHANGED` and whether the caption buttons follow the requested mode on the target Windows build.

## References
- <https://github.com/Pixelsuft/win32-darkmode-test>

## Connections
- `Dark Mode (Uxtheme Ordinals).md` is the reverse-engineered map this test exercises.
- `Dark Mode Library (Maintained).md` is the dependency route once the probe succeeds.
- `../Common Controls/Darkmode.md` explains why the top-level frame and child controls need separate treatment.
- `win32mica.md` is the adjacent DWM caption/backdrop attribute path.
