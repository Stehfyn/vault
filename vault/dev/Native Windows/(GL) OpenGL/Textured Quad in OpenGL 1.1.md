# Textured Quad in OpenGL 1.1

The fixed-function textured quad is useful only as a compatibility primitive: enable `GL_TEXTURE_2D`, bind a texture, provide texture coordinates, and draw a `GL_QUADS` rectangle. It is appropriate for old Win32/OpenGL 1.1 contexts, quick bitmap display, or understanding legacy code, not for new renderers.

The non-obvious parts are coordinate and pixel conventions. OpenGL texture coordinate `(0,0)` is the lower-left by convention, while many Windows image sources are top-down or bottom-up DIBs depending on how they were created. If a GDI-loaded bitmap appears upside down, fix the upload/coordinates deliberately rather than randomly flipping vertices.

## References
- <https://stackoverflow.com/questions/41555409/how-can-i-create-a-textured-quad-in-opengl-1-1/41555890#41555890>

## Connections
- `Converting HBITMAP to Texture.md`
- `OpenGL in MFC CView (KB Q127071).md`
