GDI AlphaBlend() blits a source bitmap onto a destination DC with per-pixel or constant alpha transparency.

```cpp
BLENDFUNCTION bf = {};
bf.BlendOp = AC_SRC_OVER;
bf.BlendFlags = 0;
bf.SourceConstantAlpha = 128; // 50% opacity
bf.AlphaFormat = AC_SRC_ALPHA;
AlphaBlend(hdcDest, xDest, yDest, width, height,
           hdcSrc,  xSrc,  ySrc,  width, height, bf);
```

## References
1. https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/gdi/alpha-blending-a-bitmap.md

https://learn.microsoft.com/en-us/answers/questions/642735/how-to-make-a-bitmap-with-alpha-using-transparentb
Creating a 32bpp DIB section with BI_RGB and filling it with premultiplied ARGB pixels is the correct way to get per-pixel alpha in GDI. AlphaBlend with AC_SRC_ALPHA requires premultiplied values (R,G,B must each be <= A).
```cpp
// Create a 32bpp DIB section with premultiplied ARGB
BITMAPINFO bmi = {};
bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
bmi.bmiHeader.biWidth       = w;
bmi.bmiHeader.biHeight      = -h;   // top-down
bmi.bmiHeader.biPlanes      = 1;
bmi.bmiHeader.biBitCount    = 32;
bmi.bmiHeader.biCompression = BI_RGB;
void* bits = nullptr;
HBITMAP dib = CreateDIBSection(nullptr, &bmi, DIB_RGB_COLORS, &bits, nullptr, 0);

// Write premultiplied BGRA pixels, then AlphaBlend
BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
AlphaBlend(dst, 0, 0, w, h, src, 0, 0, w, h, bf);
```

https://web.archive.org/web/20150417080754/https://www.codeproject.com/Articles/251892/Guide-to-Image-Composition-with-Win32-MsImg32-dll
MsImg32.dll exports AlphaBlend and TransparentBlt. AlphaBlend supports per-pixel (AC_SRC_ALPHA) and constant-alpha (SourceConstantAlpha) modes; they compose multiplicatively.
```cpp
// Composite with 75% opacity and per-pixel alpha combined
BLENDFUNCTION bf = {};
bf.BlendOp             = AC_SRC_OVER;
bf.SourceConstantAlpha = 192;   // ~75% constant alpha
bf.AlphaFormat         = AC_SRC_ALPHA;  // AND with per-pixel alpha
HDC mem = CreateCompatibleDC(hdc);
SelectObject(mem, hSprite);
AlphaBlend(hdc, x, y, w, h, mem, 0, 0, w, h, bf);
DeleteDC(mem);
```
