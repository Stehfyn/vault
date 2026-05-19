# GDI Rectangle Operations Reference

The GDI rectangle helpers are small but worth using because they encode Win32's half-open rectangle convention: `left/top` inclusive, `right/bottom` exclusive. `SetRect`, `OffsetRect`, `InflateRect`, `IntersectRect`, `UnionRect`, `PtInRect`, and `EqualRect` keep hit testing and invalidation code readable, especially around non-client calculations and dirty regions.

The subtlety is coordinate ownership. A `RECT` may be in screen, client, window, dialog-unit-converted, or device coordinates; the helper functions do not know. Most rectangle bugs in custom controls are not arithmetic mistakes but mixing coordinate spaces.

## References
- <https://learn.microsoft.com/en-us/windows/win32/gdi/rectangle-operations> - canonical list of GDI rectangle helpers.

## Connections
- `Common Controls/Window Sizing.md` and `Borderless Window.md` depend heavily on correct rectangle space conversion.
