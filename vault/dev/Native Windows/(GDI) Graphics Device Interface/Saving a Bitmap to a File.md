# Saving a Bitmap to a File

Saving an `HBITMAP` as `.bmp` means writing a `BITMAPFILEHEADER`, an appropriate DIB header, optional masks/palette/profile data, then scanlines padded to DWORD stride. The common shortcut `width * height * 4` is only safe for a tightly packed 32-bpp top-down buffer you already control. For a device-dependent bitmap, query or convert through `GetDIBits` first.

`SaveBitmapToFile` is useful because it shows the mechanical file-format bridge from GDI objects to disk. For real image output beyond BMP, WIC is the better Windows-native encoder path.

## References
- <https://github.com/katahiromz/SaveBitmapToFile> - focused HBITMAP-to-BMP helper.

## Connections
- `Read Pixels with GetDIBits().md` covers extracting a stable pixel buffer.
- `WIC Image Loading.md` is the broader imaging component; WIC can also encode.
