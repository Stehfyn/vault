Sample showing GetDeviceCaps() for querying display/printer capabilities such as resolution, color depth, and DPI.

```cpp
HDC hdc = GetDC(hwnd);
int bitsPerPixel  = GetDeviceCaps(hdc, BITSPIXEL);
int numColors     = GetDeviceCaps(hdc, NUMCOLORS);
int horzRes       = GetDeviceCaps(hdc, HORZRES);   // width in pixels
int vertRes       = GetDeviceCaps(hdc, VERTRES);   // height in pixels
int logPixelsX    = GetDeviceCaps(hdc, LOGPIXELSX);// DPI horizontal
ReleaseDC(hwnd, hdc);
```

## References
1. https://github.com/MrCsabaToth/DeviceCaps
