# GDI+ Examples

Reference:
- https://github.com/AkshayVats/CC-Graphics

Description:
- Win32 GDI+ sample code and helper utilities for modern C++ graphics coursework.

Minimal GDI+ initialization:
```cpp
#include <gdiplus.h>
using namespace Gdiplus;

ULONG_PTR gdiplusToken = 0;
GdiplusStartupInput gdiplusStartupInput;
GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
// ...
GdiplusShutdown(gdiplusToken);
```
