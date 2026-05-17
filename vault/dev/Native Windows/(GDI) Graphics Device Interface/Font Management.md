# Font Management

`AddFontResourceExW` with `FR_PRIVATE` loads a font file into the current process only (not visible to other apps). Use `CreateFontW` or `CreateFontIndirectW` with a `LOGFONTW` to instantiate it. `RemoveFontResourceExW` cleans up on exit.

```cpp
// Load a private font and use it
AddFontResourceExW(L"C:\\Fonts\\MyFont.ttf", FR_PRIVATE, nullptr);

LOGFONTW lf = {};
lf.lfHeight  = -MulDiv(12, GetDeviceCaps(hdc, LOGPIXELSY), 72);  // 12pt
lf.lfWeight  = FW_NORMAL;
lf.lfQuality = CLEARTYPE_QUALITY;
wcscpy_s(lf.lfFaceName, L"MyFont");
HFONT font = CreateFontIndirectW(&lf);
HFONT oldFont = (HFONT)SelectObject(hdc, font);
TextOutW(hdc, 10, 10, L"Private font", 12);
SelectObject(hdc, oldFont);
DeleteObject(font);

// Cleanup
RemoveFontResourceExW(L"C:\\Fonts\\MyFont.ttf", FR_PRIVATE, nullptr);
```

## References
- https://github.com/ysc3839/FontMod
