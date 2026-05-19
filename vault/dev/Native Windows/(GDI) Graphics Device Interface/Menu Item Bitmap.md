# Menu Item Bitmap

Menu bitmaps are old USER objects with modern alpha expectations bolted on. `MIIM_BITMAP` through `SetMenuItemInfo` is the cleaner path than the older `SetMenuItemBitmaps`, and loading with `LR_CREATEDIBSECTION` helps preserve pixel data instead of converting to a device-dependent bitmap too early. The hard part is transparent edges: the menu renderer, bitmap format, and alpha premultiplication must agree.

For themed applications, consider whether an owner-draw menu or command UI is the better abstraction. Plain menu bitmaps are fine for small glyphs, but scaling, dark mode, disabled-state rendering, and high-DPI variants become manual responsibilities quickly.

## References
- <https://stackoverflow.com/questions/60176811/win32-menu-item-bitmap-with-transparent-background> - discusses transparent menu bitmap behavior.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadimagew> - `LoadImageW` flags, including `LR_CREATEDIBSECTION`.

## Connections
- `Common Controls/Custom Menubar.md` covers top-level menu drawing.
- `Alpha Blending a Bitmap.md` covers the alpha rules behind clean glyph edges.
