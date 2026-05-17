# OpenGL Examples

## CRender
https://github.com/jfcameron/CRender
Brief: C90 OpenGL ES 2.0 renderer with shader compilation flow.
```c
GLuint vs = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vs, 1, &vsSrc, NULL);
glCompileShader(vs);
GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fs, 1, &fsSrc, NULL);
glCompileShader(fs);
```

## 3D-Model-Viewer
https://github.com/carllinley/3D-Model-Viewer
Brief: Win32 OpenGL model viewer with VBO/VAO setup.
```cpp
GLuint vbo = 0;
glGenBuffers(1, &vbo);
glBindBuffer(GL_ARRAY_BUFFER, vbo);
glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * count, vertices, GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
```

## glintercept
https://github.com/dtrebilco/glintercept
Brief: OpenGL call interception and logging; use debug callbacks while tracing.
```cpp
glEnable(GL_DEBUG_OUTPUT);
glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
glDebugMessageCallback(DebugCallback, nullptr);
glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
glGetError();
```

## surface_splatting
https://github.com/sebastianlipponer/surface_splatting
Brief: OpenGL 3.3 demo that renders into FBOs for deferred-style passes.
```cpp
GLuint fbo = 0;
glGenFramebuffers(1, &fbo);
glBindFramebuffer(GL_FRAMEBUFFER, fbo);
glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTex, 0);
glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRb);
glBindFramebuffer(GL_FRAMEBUFFER, 0);
```

## video-app (src)
https://github.com/bmewj/video-app/tree/master/src
Brief: Upload video frames to a texture for a tiled display.
```cpp
glBindTexture(GL_TEXTURE_2D, videoTex);
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, frameData);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
```

## OGLWindow.cpp (context creation)
https://raw.githubusercontent.com/carllinley/3D-Model-Viewer/master/OGLWindow.cpp
Brief: Classic Win32 WGL pixel format and context creation flow.
```cpp
PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1,
    PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, 32 };
int pf = ChoosePixelFormat(hdc, &pfd);
SetPixelFormat(hdc, pf, &pfd);
HGLRC rc = wglCreateContext(hdc);
wglMakeCurrent(hdc, rc);
```
