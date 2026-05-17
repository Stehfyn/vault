1. https://web.archive.org/web/20200508205532/http://www.mathematik.tu-dortmund.de/~goeddeke/gpgpu/tutorial3.html
2. Summary: streams large double-precision arrays to GPU, converts to float textures, and uses ping-pong FBOs + PBOs to overlap transfers with compute; performance depends on texture formats and memory bandwidth.
3. Snippet (PBO upload path):
```c
glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, ioBuf[array]);
glBufferData(GL_PIXEL_UNPACK_BUFFER_ARB, texSize*texSize*sizeof(float), NULL, GL_STREAM_DRAW);
void* ioMem = glMapBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, GL_WRITE_ONLY);
copy(chunks[chunk][array], ioMem);
glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER_ARB);
glTexSubImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, 0, 0, texSize, texSize,
                GL_LUMINANCE, GL_FLOAT, BUFFER_OFFSET(0));
glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
```
