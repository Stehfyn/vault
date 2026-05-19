# BitmapPlusPlus - Single-Header BMP I/O

BitmapPlusPlus is a small C++ header for reading and writing 24-bit BMP files without GDI+, WIC, or stb. Its real value is boring correctness: `BITMAPFILEHEADER`, `BITMAPINFOHEADER`, BGR ordering, bottom-up row order, and DWORD-aligned scanline stride. That makes it useful in console tools, tests, and cross-platform utilities that only need simple BMP interchange.

Do not treat it as a general Windows imaging layer. It is intentionally narrower than WIC and does not solve alpha, color management, indexed formats, or compressed image formats. Pair it with the BMP header notes when debugging files produced by GDI code.

## References
- <https://github.com/baderouaich/BitmapPlusPlus> - dependency-light 24-bit BMP reader/writer.

## Connections
- `Saving a Bitmap to a File.md` covers manual HBITMAP/BMP output.
- `WIC Image Loading.md` is the broader Windows decoder path.
