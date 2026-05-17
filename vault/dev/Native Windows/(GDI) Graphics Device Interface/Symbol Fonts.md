# Symbol Fonts (Segoe UI Symbol / Segoe MDL2 Assets)

`Segoe UI Symbol` provides Unicode dingbats and emoji; `Segoe MDL2 Assets` (Windows 8.1+) provides the flat glyph icon set used throughout modern Windows UI. Select the font with `SYMBOL_CHARSET` to suppress GDI glyph substitution. Reference the codepoints by Unicode scalar value.

```cpp
// Draw a Segoe MDL2 Assets icon glyph (U+E10F = "Contact")
HFONT iconFont = CreateFontW(
    24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
    SYMBOL_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
    CLEARTYPE_QUALITY, FF_DONTCARE, L"Segoe MDL2 Assets");
HFONT oldFont = (HFONT)SelectObject(hdc, iconFont);
SetTextColor(hdc, RGB(0, 120, 215));
SetBkMode(hdc, TRANSPARENT);
TextOutW(hdc, 10, 10, L"\uE10F", 1);   // Contact icon
SelectObject(hdc, oldFont);
DeleteObject(iconFont);
```

## References
- https://learn.microsoft.com/en-us/windows/apps/design/style/segoe-ui-symbol-font
