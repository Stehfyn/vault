1. https://stackoverflow.com/questions/45676892/reliable-windowed-vsync-with-opengl-on-windows
2. Snippet (wglSwapIntervalEXT + SwapBuffers from SO):
```c
auto wglSwapIntervalEXT = (GLboolean(*)(GLint))wglGetProcAddress("wglSwapIntervalEXT");
wglSwapIntervalEXT(1);
SwapBuffers(hdc);
// Optional workaround mentioned in the thread:
// DwmFlush();
```
