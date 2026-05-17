# Streaming Texture Uploads

## Song Ho PBO unpack notes
https://www.songho.ca/opengl/gl_pbo.html#unpack
Brief: Basic pixel unpack PBO usage for async texture uploads.
```c
GLuint pbo = 0;
glGenBuffers(1, &pbo);
glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbo);
glBufferData(GL_PIXEL_UNPACK_BUFFER, dataSize, NULL, GL_STREAM_DRAW);
glBindTexture(GL_TEXTURE_2D, tex);
glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, 0);
glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
```

## Khronos forum: PBO performance
https://community.khronos.org/t/performance-of-texture-upload-with-pbo/61565/23
Brief: Orphan and map PBOs to avoid stalls during streaming.
```c
static int idx = 0;
idx = (idx + 1) % 2;
glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbos[idx]);
glBufferData(GL_PIXEL_UNPACK_BUFFER, dataSize, NULL, GL_STREAM_DRAW);
void* ptr = glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);
if (ptr) { memcpy(ptr, pixels, dataSize); glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER); }
```
