# Symbol Fonts

Windows icon glyph fonts such as Segoe UI Symbol and Segoe MDL2 Assets let GDI draw UI icons as text. Select the face into an `HFONT`, draw the Unicode private-use code point, and keep the background transparent if it is acting like an icon. This works well for simple monochrome glyphs that should scale with text metrics.

The tradeoff is semantic and visual fragility. Code points can be font-specific, not all users have the same glyph coverage, and colored/variable Fluent icons are not represented by the old MDL2 font model. For modern iconography use actual assets or a maintained symbol source; for classic Win32 tools, symbol fonts remain a lightweight option.

## References
- <https://learn.microsoft.com/en-us/windows/apps/design/style/segoe-ui-symbol-font> - Microsoft glyph/codepoint reference for Segoe symbol assets.

## Connections
- `Font Management.md` covers selecting and loading fonts.
- `Menu Item Bitmap.md` is the bitmap-glyph alternative for menus.
