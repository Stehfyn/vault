# Converting HBITMAP to Texture

The StackOverflow answer shows the old Win32 path: load a BMP as an `HBITMAP`, retrieve `BITMAP.bmBits`, account for Windows' BGR/BGRA layout and bottom-up DIB orientation, then upload with `glTexImage2D`. The part that matters is format discipline. If the DIB is 24-bit BGR, a blind `GL_RGB` upload after in-place byte swapping may work; for 32-bit DIBs, use `GL_BGRA` where available and avoid a CPU swizzle.

For anything beyond a tiny utility, prefer WIC/stb_image/DirectXTex-style image loading and keep `HBITMAP` conversion as interop glue for GDI-generated pixels, icons, screenshots, or legacy controls.

```c
glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
glBindTexture(GL_TEXTURE_2D, tex);
glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height,
                GL_BGRA, GL_UNSIGNED_BYTE, dibBits);
```

## References
- <https://stackoverflow.com/questions/23301171/loading-and-converting-a-hbitmap-to-an-opengl-texture/23301463#23301463>

## Connections
- `Textured Quad in OpenGL 1.1.md`
- `Streaming Texture Uploads.md`
