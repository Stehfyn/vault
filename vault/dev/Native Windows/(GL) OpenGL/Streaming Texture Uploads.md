# Streaming Texture Uploads

Pixel Buffer Objects help texture uploads only when they break a synchronization dependency. The useful pattern is double/triple-buffered PBOs: orphan or map the next unpack buffer, copy CPU pixels into it, issue `glTexSubImage2D` with offset zero, then let the driver DMA to texture memory while the CPU moves on. A single PBO used synchronously can be slower than a direct pointer upload.

The Khronos discussion matters because it pushes past the basic API recipe into stalls: orphaning, persistent mapping, pixel format matching, `GL_UNPACK_ALIGNMENT`, and whether the producer can write directly into mapped memory. This note belongs beside video upload and HBITMAP conversion because all three fail the same way: hidden format conversion plus CPU/GPU sync.

## References
- <https://www.songho.ca/opengl/gl_pbo.html#unpack>
- <https://community.khronos.org/t/performance-of-texture-upload-with-pbo/61565/23>

## Connections
- `Converting HBITMAP to Texture.md`
- `OpenGL Examples.md`
- `GPGPU Tutorial 3.md`
