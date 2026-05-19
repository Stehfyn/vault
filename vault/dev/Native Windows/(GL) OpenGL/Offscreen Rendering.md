# Offscreen Rendering

For modern OpenGL, offscreen rendering should usually mean FBOs with texture/renderbuffer attachments, not pbuffers or hidden windows. The StackOverflow thread is a performance warning: large offscreen targets stress fill rate, texture bandwidth, and readback paths, so the bottleneck is rarely the act of being "offscreen" and usually the size/format/synchronization of the render target.

The old advice about power-of-two textures is context-dependent now, but the deeper point survives: avoid format conversions, avoid synchronous readbacks, and keep producer/consumer usage on the GPU where possible. Pair this with `Streaming Texture Uploads.md` for the opposite direction of the same bus problem.

## References
- <https://stackoverflow.com/questions/3311388/how-to-speed-up-offscreen-opengl-rendering-with-large-textures-on-win32>

## Connections
- `GPGPU Tutorial 3.md`
- `Streaming Texture Uploads.md`
