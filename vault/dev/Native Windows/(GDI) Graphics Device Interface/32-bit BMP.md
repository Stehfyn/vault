# 32-bit BMP

The trap in "32-bit BMP" is alpha semantics. A 32-bpp `BITMAPINFOHEADER` with `BI_RGB` gives you four bytes per pixel, but many readers treat the high byte as unused padding. If you need explicit channel masks, use `BI_BITFIELDS`; if you need a real alpha/color-space contract, use `BITMAPV4HEADER` or `BITMAPV5HEADER` with masks and color-space fields. BMP stores pixels in BGR(A) byte order, and positive heights are bottom-up unless you use a negative top-down height.

## Header Choice

The `BITMAPINFOHEADER` and `BITMAPV4HEADER` references contribute the code distinction: bytes-per-pixel is not the same thing as alpha semantics.

```cpp
BITMAPV4HEADER h = {};
h.bV4Size = sizeof(h);
h.bV4Width = width;
h.bV4Height = -height;
h.bV4Planes = 1;
h.bV4BitCount = 32;
h.bV4V4Compression = BI_BITFIELDS;
h.bV4RedMask = 0x00ff0000;
h.bV4GreenMask = 0x0000ff00;
h.bV4BlueMask = 0x000000ff;
h.bV4AlphaMask = 0xff000000;
```

## GDI Alpha Boundary

The practical-tooling discussion contributes the compatibility warning: an editor may preserve alpha that a BMP reader or GDI path treats as padding. For composition, normalize pixels to premultiplied BGRA before `AlphaBlend`.

```cpp
struct Bgra {
    BYTE b;
    BYTE g;
    BYTE r;
    BYTE a;
};
```

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader> - baseline DIB header fields.
- <https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapv4header> - masks and color-space aware BMP header.
- <https://superuser.com/questions/334007/how-to-save-image-as-32-bit-bmp> - practical discussion of tools/readers disagreeing about BMP alpha.

## Connections

- `Alpha Blending a Bitmap.md` covers premultiplied alpha.
- `BmpHeaderViewer - DIB Header Forensics.md` is useful for inspecting which header variant a file actually uses.
