# Translucent Win32 Flyouts

Hooks the per-process drawing path of the legacy Win32 flyout/menu/tooltip stack (`DrawThemeBackground`, `BeginBufferedPaint`, the menu owner-draw plumbing) and substitutes a DWM-blurred backdrop, so Win32 context menus and combo dropdowns visually match Win11's WinUI flyouts. Same author as ALTaleX531/OpenGlass (#13) and ALTaleX531/Win32Acrylic (#14); this is the "third leg" — OpenGlass restores Aero, Win32Acrylic adds the acrylic backdrop, TranslucentFlyouts brings the menus along.

## References
- <https://github.com/ALTaleX531/TranslucentFlyouts>
