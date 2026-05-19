# gdi-3d-renderer - Pure GDI Software 3D

`gdi-3d-renderer` is a software-rendering exercise that projects 3D geometry to 2D and rasterizes with GDI primitives. Its value is pedagogical: it exposes the transform, projection, clipping, fill, and z-order problems that GPU APIs normally hide. It is not a performance strategy; `SetPixel`-style loops and immediate GDI primitives are the slow path for any real 3D workload.

For this vault, keep it as a reference for the boundary between GDI as a 2D raster API and proper GPU rendering. If the interesting part is math or rasterization, the sample is relevant; if the interesting part is shipping graphics, move to Direct2D/Direct3D/OpenGL.

## References
- <https://github.com/thenanisore/gdi-3d-renderer> - pure-GDI software 3D renderer.

## Connections
- `Path and Outline Text.md` uses GDI paths/transforms for 2D geometry.
- DirectX and OpenGL directories cover real GPU rendering paths.
