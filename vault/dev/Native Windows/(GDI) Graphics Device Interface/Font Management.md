# Font Management

`AddFontResourceExW` with `FR_PRIVATE` loads a font for the current process without installing it system-wide. Create actual `HFONT` instances with `CreateFontIndirectW`, using negative `lfHeight` for character height in logical units, and remove the resource with `RemoveFontResourceExW` when the process no longer needs it. A private font still participates in GDI font matching by face name, so naming collisions and fallback remain possible.

`FontMod` is relevant because it shows font substitution/modification pressure in real Windows UI rather than a hello-world draw call. For application UI, the hard part is not loading the font; it is recomputing metrics, control sizes, and cached text extents when DPI, theme, or font choice changes.

## References
- <https://github.com/ysc3839/FontMod> - Windows font modification/substitution utility.

## Connections
- `Text Shaping (Uniscribe).md` covers glyph shaping beyond selecting an `HFONT`.
- `Symbol Fonts.md` covers icon glyph fonts.
