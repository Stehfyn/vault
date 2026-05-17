1. https://superuser.com/questions/334007/how-to-save-image-as-32-bit-bmp
2. https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader
3. https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapv4header

Snippet (32bpp BGRA with alpha masks):

```cpp
BITMAPINFOHEADER bi = {};
bi.biSize = sizeof(BITMAPINFOHEADER);
bi.biWidth = width;
bi.biHeight = -height; // top-down
bi.biPlanes = 1;
bi.biBitCount = 32;
bi.biCompression = BI_BITFIELDS;

DWORD masks[4] = { 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000 }; // BGRA
```
