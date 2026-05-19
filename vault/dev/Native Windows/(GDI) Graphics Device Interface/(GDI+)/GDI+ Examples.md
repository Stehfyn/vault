# GDI+ Examples

GDI+ is the COM-era drawing layer above GDI: anti-aliased paths, gradients, image codecs, transforms, and higher-level text/image primitives behind `GdiplusStartup` and `GdiplusShutdown`. It is easier than raw GDI for simple 2D graphics and image loading, but it is not hardware-accelerated in the way Direct2D is and it has its own lifetime/status-code conventions.

`CC-Graphics` is relevant as coursework-style sample code: useful for seeing shapes, transforms, pens/brushes, and image operations in one place. For production Windows imaging, compare it against WIC for decode/encode and Direct2D for modern rendering.

## References
- <https://github.com/AkshayVats/CC-Graphics> - Win32/GDI+ graphics exercises and helper code.

## Connections
- `../WIC Image Loading.md` covers the native imaging component.
- `../GDI D2D Interop.md` covers incremental migration toward Direct2D.
