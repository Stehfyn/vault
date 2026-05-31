# Saving a Bitmap to a File

Saving an `HBITMAP` as `.bmp` means writing a `BITMAPFILEHEADER`, an appropriate DIB header, optional masks/palette/profile data, then scanlines padded to DWORD stride. The common shortcut `width * height * 4` is only safe for a tightly packed 32-bpp top-down buffer you already control. For a device-dependent bitmap, query or convert through `GetDIBits` first.

`SaveBitmapToFile` is useful because it shows the mechanical file-format bridge from GDI objects to disk. For real image output beyond BMP, WIC is the better Windows-native encoder path.

## Source Code Reading

`katahiromz/SaveBitmapToFile/SaveBitmapToFile.c` is the useful Win32-C path for turning an `HBITMAP` into a BMP file without hiding DIB details. `SaveBitmapToFile` first validates the `HBITMAP` with `GetObject`, fills a `BITMAPINFOHEADER` from `BITMAP`, computes palette/color table bytes, sets `BITMAPFILEHEADER::bfOffBits`, allocates an image buffer, calls `GetDIBits`, and then writes file header, info header, optional colors, and pixel bits with `WriteFile`.

```c
GetObject(hbm, sizeof(BITMAP), &bm);
bih.biSize = sizeof(BITMAPINFOHEADER);
bih.biWidth = bm.bmWidth;
bih.biHeight = bm.bmHeight;
bih.biPlanes = 1;
bih.biBitCount = bm.bmBitsPixel;
bih.biCompression = BI_RGB;
bih.biSizeImage = bm.bmWidthBytes * bm.bmHeight;
bf.bfOffBits = sizeof(BITMAPFILEHEADER) + bih.biSize + color_bytes;
GetDIBits(hdc, hbm, 0, bm.bmHeight, bits, (BITMAPINFO*)&bmi, DIB_RGB_COLORS);
WriteFile(file, &bf, sizeof bf, ...);
WriteFile(file, &bmi, sizeof(BITMAPINFOHEADER) + color_bytes, ...);
WriteFile(file, bits, bih.biSizeImage, ...);
```

This is a better probe than a library save call because every ambiguity is visible: bottom-up versus top-down height, `bmWidthBytes` padding, palette bytes for low-bpp images, and whether the source HBITMAP is a DIB section or a compatible bitmap. When comparing with WIC/GDI+ encoders, hash the raw `GetDIBits` buffer first so file-container differences do not obscure capture differences.

## References
- <https://github.com/katahiromz/SaveBitmapToFile> - focused HBITMAP-to-BMP helper.

## Connections
- `Read Pixels with GetDIBits().md` covers extracting a stable pixel buffer.
- `WIC Image Loading.md` is the broader imaging component; WIC can also encode.
