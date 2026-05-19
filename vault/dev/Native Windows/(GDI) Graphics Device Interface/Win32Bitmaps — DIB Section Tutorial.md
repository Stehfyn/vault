# Win32Bitmaps - DIB Section Tutorial

`Win32Bitmaps` is a DIB-section tutorial: create bitmaps with `CreateDIBSection`, get a stable CPU pointer, draw/blit with GDI, and save or convert as needed. The central distinction is DIB section versus device-dependent bitmap. A DIB section has application-visible pixels in a declared format; a compatible bitmap is optimized for a device and usually needs `GetDIBits` before CPU processing.

For modern GDI code that generates or post-processes pixels, prefer a top-down 32-bpp DIB section. It avoids bottom-up row surprises and makes interop with WIC, alpha blending, and encoders much more predictable.

## References
- <https://github.com/northern/Win32Bitmaps> - tutorial code for DIB sections and bitmap conversion.

## Connections
- `Read Pixels with GetDIBits().md` covers extraction from bitmaps you did not create as DIB sections.
- `Saving a Bitmap to a File.md` covers serializing pixels to BMP.
