# tacentview - Image and Texture Viewer

tacentview is a multi-format image and texture viewer for game-development assets: DDS, KTX/KTX2, ASTC, PVR, EXR, HDR, QOI, PNG, WebP, BMP, and more. It uses Dear ImGui/OpenGL/Tacent rather than GDI, but it belongs near these notes because it is a practical inspector for properties GDI code often mishandles: alpha presence, channel order, compression format, mip levels, and exact pixel values.

Use it as a diagnostic companion, not as a GDI example. When a BMP or texture looks wrong after a Win32 load/blit path, an external viewer that exposes pixel/channel facts can separate file-format bugs from drawing bugs.

## References
- <https://github.com/bluescan/tacentview> - multi-format image/texture viewer with inspection tools.

## Connections
- `BmpHeaderViewer - DIB Header Forensics.md` is the BMP-specific inspector.
- `WIC Image Loading.md` covers Windows-native decoding for common image formats.
