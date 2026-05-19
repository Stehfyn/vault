# Read Pixels with GetDIBits

`GetDIBits` copies pixels from an `HBITMAP` into a caller-supplied buffer using the format described by `BITMAPINFO`. The usual pattern is to select the bitmap into a compatible DC, request a top-down 32-bpp `BI_RGB` DIB by setting negative height, and size the buffer for stride rather than assuming `width * bytesPerPixel` for every format.

If you control bitmap creation, a DIB section is often simpler because the pixel pointer is available from `CreateDIBSection` and no extraction call is needed. `GetDIBits` is still the right bridge when an API hands you an `HBITMAP` and you need CPU-visible bytes.

## References
- <https://stackoverflow.com/questions/26233848/c-read-pixels-with-getdibits/26238387#26238387> - practical `GetDIBits` extraction pattern.

## Connections
- `How to Capture the Screen.md` uses this after `BitBlt`.
- `Win32Bitmaps - DIB Section Tutorial.md` covers creating CPU-visible DIB sections directly.
