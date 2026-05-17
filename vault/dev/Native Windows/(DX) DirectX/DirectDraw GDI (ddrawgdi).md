1. https://learn.microsoft.com/en-us/windows/win32/api/ddrawgdi/
   - ddrawgdi.h exposes kernel-mode DirectDraw/GDI entry points for surface and DC handling.
   - Example entry points:
```c
DdCreateDirectDrawObject(...);
DdCreateSurfaceObject(...);
DdGetDC(...);
DdReleaseDC(...);
```
2.
