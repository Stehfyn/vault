# Dark Mode Minimal Test

Minimal test harness for the dark-mode private API surface — `SetPreferredAppMode`/`AllowDarkModeForWindow` from uxtheme.dll ordinals plus `DwmSetWindowAttribute(DWMWA_USE_IMMERSIVE_DARK_MODE)` — useful as a sanity check when porting the bigger libraries (cf. ysc3839/win32-darkmode #25, ozone10/win32-darkmodelib #16, TBOpen/CWin32DarkMode #18). The reason this is a "test" and not a one-liner: the uxtheme ordinals (`#135` for `SetPreferredAppMode`, previously `#135` was `AllowDarkModeForApp` pre-1903) changed between 1809 and 1903, and `DWMWA_USE_IMMERSIVE_DARK_MODE` was attribute `19` before 20H1 and `20` after — getting either wrong silently leaves the titlebar white.

## References
- <https://github.com/Pixelsuft/win32-darkmode-test>
