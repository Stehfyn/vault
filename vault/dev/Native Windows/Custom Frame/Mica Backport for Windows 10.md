# Mica Backport for Windows 10

Back-ports the Win11 Mica material onto Windows 10 by re-implementing what `DwmExtendFrameIntoClientArea` + `DWMWA_SYSTEMBACKDROP_TYPE` would do — except those flags don't exist pre-22H2, so it falls back to the undocumented `SetWindowCompositionAttribute(ACCENT_ENABLE_HOSTBACKDROP)` path plus its own desktop-wallpaper-aware blur tint to fake the wallpaper-tinted look (cf. wangwenx190/Win32Acrylic #50, ALTaleX531/Win32Acrylic #14, Maplespe/DWMBlurGlass #54 which goes the other direction and rewrites DWM itself).

## References
- <https://github.com/ahmed605/10Mica>
