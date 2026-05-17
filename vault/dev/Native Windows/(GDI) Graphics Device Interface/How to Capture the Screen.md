```C
void CaptureScreen()
{
    int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
    HWND hDesktopWnd = GetDesktopWindow();
    HDC hDesktopDC = GetDC(hDesktopWnd);
    HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
    HBITMAP hCaptureBitmap =CreateCompatibleBitmap(hDesktopDC, 
                            nScreenWidth, nScreenHeight);
    SelectObject(hCaptureDC,hCaptureBitmap); 
    BitBlt(hCaptureDC,0,0,nScreenWidth,nScreenHeight,
           hDesktopDC,0,0,SRCCOPY|CAPTUREBLT); 
    SaveCapturedBitmap(hCaptureBitmap); //Place holder - Put your code

                                //here to save the captured image to disk

    ReleaseDC(hDesktopWnd,hDesktopDC);
    DeleteDC(hCaptureDC);
    DeleteObject(hCaptureBitmap);
}
```
https://stackoverflow.com/questions/8080559/excluding-certain-windows-from-screen-capture#comment9903716_8080559

https://github.com/luodh/ffmpeg_record_screen
Screen recording with GDI: capture each frame with BitBlt, call GetDIBits to get pixel data, then feed the raw BGRA buffer to FFmpeg's AVFrame.
```cpp
HDC screen = GetDC(nullptr);
int w = GetSystemMetrics(SM_CXSCREEN);
int h = GetSystemMetrics(SM_CYSCREEN);
HDC mem = CreateCompatibleDC(screen);
HBITMAP frame = CreateCompatibleBitmap(screen, w, h);
SelectObject(mem, frame);

// Capture
BitBlt(mem, 0, 0, w, h, screen, 0, 0, SRCCOPY | CAPTUREBLT);

// Extract pixels
BITMAPINFO bmi = {};
bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
bmi.bmiHeader.biWidth = w;
bmi.bmiHeader.biHeight = -h;
bmi.bmiHeader.biPlanes = 1;
bmi.bmiHeader.biBitCount = 32;
bmi.bmiHeader.biCompression = BI_RGB;
std::vector<uint8_t> pixels(w * h * 4);
GetDIBits(mem, frame, 0, h, pixels.data(), &bmi, DIB_RGB_COLORS);
```

https://github.com/Fals3R/Kernel-GDI
Low-level GDI exploration starting from GetDC(nullptr) for the screen DC. Note CAPTUREBLT is needed to include layered windows in BitBlt.
```cpp
HDC screen = GetDC(nullptr);
HDC mem = CreateCompatibleDC(screen);
HBITMAP bmp = CreateCompatibleBitmap(screen, 640, 480);
SelectObject(mem, bmp);
BitBlt(mem, 0, 0, 640, 480, screen, 0, 0, SRCCOPY | CAPTUREBLT);
// Save or process bmp...
DeleteObject(bmp);
DeleteDC(mem);
ReleaseDC(nullptr, screen);
```
