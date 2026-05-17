Read pixel data from an HBITMAP into a CPU buffer using GetDIBits(). Create a compatible DC, select the bitmap, then call GetDIBits with a BITMAPINFO describing the desired format.

```cpp
HDC hdc = GetDC(nullptr);
HDC memDC = CreateCompatibleDC(hdc);
SelectObject(memDC, hBitmap);

BITMAPINFOHEADER bi = {};
bi.biSize        = sizeof(bi);
bi.biWidth       = width;
bi.biHeight      = -height; // top-down
bi.biPlanes      = 1;
bi.biBitCount    = 32;
bi.biCompression = BI_RGB;

std::vector<BYTE> pixels(width * height * 4);
BITMAPINFO bmi = {};
bmi.bmiHeader = bi;
GetDIBits(memDC, hBitmap, 0, height, pixels.data(), &bmi, DIB_RGB_COLORS);

DeleteDC(memDC);
ReleaseDC(nullptr, hdc);
```

## References
1. https://stackoverflow.com/questions/26233848/c-read-pixels-with-getdibits/26238387#26238387
