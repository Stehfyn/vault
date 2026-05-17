Utility for saving an HBITMAP to a .bmp file by manually writing BITMAPFILEHEADER + BITMAPINFOHEADER followed by raw pixel data.

```cpp
BITMAPFILEHEADER bfh = {};
BITMAPINFOHEADER bih = {};
bih.biSize = sizeof(bih);
bih.biWidth = width;
bih.biHeight = -height;
bih.biPlanes = 1;
bih.biBitCount = 32;
bfh.bfType = 0x4D42; // 'BM'
bfh.bfOffBits = sizeof(bfh) + sizeof(bih);
bfh.bfSize = bfh.bfOffBits + width * height * 4;

FILE* f = nullptr;
_wfopen_s(&f, L"output.bmp", L"wb");
fwrite(&bfh, 1, sizeof(bfh), f);
fwrite(&bih, 1, sizeof(bih), f);
fwrite(pixels, 1, width * height * 4, f);
fclose(f);
```

## References
1. https://github.com/katahiromz/SaveBitmapToFile
