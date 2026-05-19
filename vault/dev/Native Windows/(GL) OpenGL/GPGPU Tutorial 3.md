# GPGPU Tutorial 3

The archived TU Dortmund tutorial is a pre-compute-shader GPGPU snapshot: large arrays become float textures, computation is expressed as fragment shading over rectangles, and FBO/PBO ping-pong hides transfers where possible. It is dated, but still useful for understanding why early OpenGL GPGPU code cared so much about texture formats, rectangle textures, readback stalls, and bandwidth.

The modern lesson is architectural: GPU compute performance collapses when upload/readback dominates. Read this beside `Streaming Texture Uploads.md` and `Offscreen Rendering.md`; the same PBO/FBO synchronization traps remain even when the shader code has moved to compute shaders or CUDA.

## References
- <https://web.archive.org/web/20200508205532/http://www.mathematik.tu-dortmund.de/~goeddeke/gpgpu/tutorial3.html>
