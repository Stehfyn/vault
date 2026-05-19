# OpenGL Examples

This note groups examples by what they are good for. `CRender` is a small C/OpenGL ES-style renderer with shader compilation and minimal abstractions. `3D-Model-Viewer` is useful for Win32 WGL context creation plus VBO/VAO model rendering. `glintercept` is the old Windows GL call-interception/logger path, complementary to apitrace and `glDebugMessageCallback`. `surface_splatting` shows an OpenGL 3.3 multi-pass/FBO technique, while `video-app` is relevant to streaming texture uploads.

The important editorial distinction is sample purpose. Do not use a model viewer to learn capture/replay, or a video texture uploader to learn context creation. The nearby notes split those concerns into WGL setup, streaming uploads, FBO/offscreen rendering, and tracing.

## Context and Model Rendering

The model-viewer link contributes the Win32/WGL bootstrap shape. It is useful because it shows the boring order that samples often hide: choose pixel format, create context, make it current, then load modern entry points before touching VBOs or VAOs.

```cpp
PIXELFORMATDESCRIPTOR pfd = { sizeof(pfd), 1 };
pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
pfd.iPixelType = PFD_TYPE_RGBA;
pfd.cColorBits = 32;
pfd.cDepthBits = 24;

HDC dc = GetDC(hwnd);
int format = ChoosePixelFormat(dc, &pfd);
SetPixelFormat(dc, format, &pfd);
HGLRC rc = wglCreateContext(dc);
wglMakeCurrent(dc, rc);
```

## Shader and FBO Examples

`CRender` contributes a compact shader lifecycle, while `surface_splatting` contributes the FBO/multipass boundary: each pass must state its framebuffer, viewport, textures, and synchronization assumptions.

```cpp
GLuint shader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(shader, 1, &source, nullptr);
glCompileShader(shader);

GLint ok = GL_FALSE;
glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
if (!ok) {
    char log[4096];
    glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
}

glBindFramebuffer(GL_FRAMEBUFFER, fbo);
glViewport(0, 0, target_width, target_height);
```

## Interception and Streaming Uploads

`glintercept` contributes call-boundary thinking: capture state changes and errors around real GL calls. The video sample contributes the upload path: persistent or double-buffered texture updates are a different problem from static model textures.

```cpp
glBindTexture(GL_TEXTURE_2D, video_texture);
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0,
                frame_width, frame_height,
                GL_BGRA, GL_UNSIGNED_BYTE, frame_pixels);
```

## References
- <https://github.com/jfcameron/CRender>
- <https://github.com/carllinley/3D-Model-Viewer>
- <https://github.com/dtrebilco/glintercept>
- <https://github.com/sebastianlipponer/surface_splatting>
- <https://github.com/bmewj/video-app/tree/master/src>
- <https://raw.githubusercontent.com/carllinley/3D-Model-Viewer/master/OGLWindow.cpp>

## Connections
- `Apitrace — GL and D3D Capture Replay.md`
- `Streaming Texture Uploads.md`
- `OpenGL in MFC CView (KB Q127071).md`
