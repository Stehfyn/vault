# WIC Image Loading

Windows Imaging Component is the native decoder/encoder layer for common image formats. The normal load path is `IWICImagingFactory`, decoder, frame, optional `IWICFormatConverter`, then either copy pixels into your own buffer or into a 32-bpp DIB section. Converting to `GUID_WICPixelFormat32bppPBGRA` is a good default when the next step is GDI/Direct2D alpha composition because the pixels are already premultiplied BGRA.

Use WIC instead of hand-written decoders for PNG/JPEG/TIFF/GIF/BMP unless the point is file-format study. `RadImgViewer2` matters here because it shows WIC used in an actual viewer pipeline, not just a one-file sample.

## References
- <https://github.com/RadAd/RadImgViewer2> - Windows image viewer using WIC-style loading paths.

## Connections
- `Alpha Blending a Bitmap.md` explains why premultiplied BGRA matters.
- `BitmapPlusPlus - Single-Header BMP IO.md` is the deliberately narrow BMP-only alternative.
