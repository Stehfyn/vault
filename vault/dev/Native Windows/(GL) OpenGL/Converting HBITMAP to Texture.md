Load a BMP file as an `HBITMAP` with `LoadImage`, retrieve the pixel pointer via `GetObject`/`BITMAP`, swap BGR to RGB bytes in-place, then upload with `glTexImage2D`. The bitmap bits are bottom-up (Windows DIB convention), so vertical flipping may be needed for correct orientation.

```c
GLuint LoadTextureFromBMP(const char *filename)
{
    HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0,
                                         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    BITMAP bm;
    GetObject(hBitmap, sizeof(BITMAP), &bm);

    // Swap BGR -> RGB in-place
    unsigned char *data = (unsigned char *)bm.bmBits;
    for (int i = 0; i < bm.bmWidth * bm.bmHeight; i++) {
        int idx = i * 3;
        unsigned char tmp = data[idx];      // B
        data[idx]     = data[idx + 2];      // R -> B slot
        data[idx + 2] = tmp;                // B -> R slot
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 bm.bmWidth, bm.bmHeight, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, bm.bmBits);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    DeleteObject(hBitmap);
    return tex;
}
```

## References
- https://stackoverflow.com/questions/23301171/loading-and-converting-a-hbitmap-to-an-opengl-texture/23301463#23301463
