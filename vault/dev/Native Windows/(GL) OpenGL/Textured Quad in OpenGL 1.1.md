Draw a textured quad using the fixed-function pipeline (`GL_QUADS` + `glTexCoord2f` + `glVertex3f`). Texture coordinates map `(0,0)` to the bottom-left and `(1,1)` to the top-right; vertex winding is counter-clockwise. Requires `glEnable(GL_TEXTURE_2D)` and a bound texture before drawing.

```c
// Setup (once)
glEnable(GL_TEXTURE_2D);
GLuint tex;
glGenTextures(1, &tex);
glBindTexture(GL_TEXTURE_2D, tex);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
             GL_RGB, GL_UNSIGNED_BYTE, pixels);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

// Draw (each frame)
glBindTexture(GL_TEXTURE_2D, tex);
glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f); // bottom-left
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 0.0f); // bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 0.0f); // top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 0.0f); // top-left
glEnd();
```

## References
- https://stackoverflow.com/questions/41555409/how-can-i-create-a-textured-quad-in-opengl-1-1/41555890#41555890
