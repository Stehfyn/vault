# Acrylic with DirectComposition

Stitches together the two halves nobody wants to write themselves: a `DwmEnableBlurBehindWindow` / `SetWindowCompositionAttribute(ACCENT_ENABLE_ACRYLICBLURBEHIND)` call to get the OS to blur whatever is behind the window, plus a DirectComposition visual tree on top so your own content composes against that blur without the GDI artifacts you get if you just `BeginPaint` over an acrylic surface (cf. ALTaleX531/Win32Acrylic, wangwenx190/Win32Acrylic, ahmed605/10Mica). The `ACCENT_ENABLE_ACRYLICBLURBEHIND` path is undocumented and was deliberately throttled in 1903+ for unfocused windows — that perf regression is the reason every modern acrylic implementation either accepts the throttle or moves to the DComp `CreateBackdropBrush` route used by ALTaleX531/TranslucentFlyouts (#63).

## References
- <https://github.com/selastingeorge/Win32-Acrylic-Effect>
