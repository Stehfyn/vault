# Alpha Blending a Bitmap

`AlphaBlend` from `msimg32.dll` composites a source DC into a destination DC using `BLENDFUNCTION`. `SourceConstantAlpha` applies whole-image opacity, and `AC_SRC_ALPHA` additionally uses the source bitmap's per-pixel alpha. When both are set, they multiply. The non-obvious contract is premultiplication: with `AC_SRC_ALPHA`, each color channel in the source must already be multiplied by alpha (`r <= a`, `g <= a`, `b <= a`) or edges will render incorrectly.

The reliable source surface is a 32-bpp top-down DIB section, commonly `BI_RGB`, filled with premultiplied BGRA pixels. `TransparentBlt` is for color-key transparency, not fractional alpha. For layered windows, the same premultiplied-alpha rule applies through `UpdateLayeredWindow`.

## DIB Section and Premultiplication

The Microsoft sample and alpha-handling answer contribute the source-surface contract: use a 32-bpp DIB section and feed `AlphaBlend` premultiplied BGRA when `AC_SRC_ALPHA` is set.

```cpp
BITMAPINFO bi = {};
bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
bi.bmiHeader.biWidth = width;
bi.bmiHeader.biHeight = -height;
bi.bmiHeader.biPlanes = 1;
bi.bmiHeader.biBitCount = 32;
bi.bmiHeader.biCompression = BI_RGB;

void* pixels = nullptr;
HBITMAP bitmap = CreateDIBSection(src_dc, &bi, DIB_RGB_COLORS, &pixels, nullptr, 0);
SelectObject(src_dc, bitmap);
```

```cpp
auto premultiply = [](BYTE c, BYTE a) -> BYTE {
    return static_cast<BYTE>((static_cast<unsigned>(c) * a + 127) / 255);
};
```

## AlphaBlend Contract

The msimg32 composition references contribute the blend setup. `SourceConstantAlpha` multiplies every pixel; `AC_SRC_ALPHA` additionally consumes each pixel's alpha channel.

```cpp
BLENDFUNCTION bf = {};
bf.BlendOp = AC_SRC_OVER;
bf.SourceConstantAlpha = 255;
bf.AlphaFormat = AC_SRC_ALPHA;

AlphaBlend(dst_dc, x, y, width, height,
           src_dc, 0, 0, width, height, bf);
```

## References

- <https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/gdi/alpha-blending-a-bitmap.md> - Microsoft sample for `AlphaBlend`.
- <https://learn.microsoft.com/en-us/answers/questions/642735/how-to-make-a-bitmap-with-alpha-using-transparentb> - clarifies DIB-section alpha handling and premultiplication.
- <https://web.archive.org/web/20150417080754/https://www.codeproject.com/Articles/251892/Guide-to-Image-Composition-with-Win32-MsImg32-dll> - archived overview of `AlphaBlend` and `TransparentBlt` behavior.

## Connections

- `32-bit BMP.md` covers file/header alpha ambiguity.
- `Transparent Window GDI.md` applies the same pixel rules to top-level layered windows.
