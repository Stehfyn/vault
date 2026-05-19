# How to Capture the Screen

The classic GDI capture path is `GetDC(nullptr)` or `GetWindowDC(hwnd)`, a compatible memory DC, a compatible bitmap or 32-bpp DIB section, and `BitBlt(..., SRCCOPY | CAPTUREBLT)`. `CAPTUREBLT` asks GDI to include layered windows, but it is not a universal compositor bypass and will not reliably capture protected, hardware-overlay, or exclusive/fullscreen content.

## GDI Capture Shape

The FFmpeg and GDI examples contribute the capture loop shape. Prefer a top-down 32-bpp DIB section for frame processing so pixels are directly addressable after the blit.

```cpp
HDC screen = GetDC(nullptr);
HDC mem = CreateCompatibleDC(screen);

BITMAPINFO bi = {};
bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
bi.bmiHeader.biWidth = width;
bi.bmiHeader.biHeight = -height;
bi.bmiHeader.biPlanes = 1;
bi.bmiHeader.biBitCount = 32;
bi.bmiHeader.biCompression = BI_RGB;

void* pixels = nullptr;
HBITMAP dib = CreateDIBSection(screen, &bi, DIB_RGB_COLORS, &pixels, nullptr, 0);
SelectObject(mem, dib);
BitBlt(mem, 0, 0, width, height, screen, x, y, SRCCOPY | CAPTUREBLT);
```

## Capture Limits

The selective-exclusion discussion contributes the architectural warning: GDI capture sees a composed desktop view through old APIs. For exclusion, protected content, or high-rate recording, move the decision to DXGI output duplication or Windows Graphics Capture.

```cpp
struct CaptureChoice {
    bool needs_high_frame_rate;
    bool needs_window_exclusion;
    bool needs_protected_content_policy;
    const wchar_t* preferred_api; // "GDI", "DXGI output duplication", "Windows Graphics Capture"
};
```

## References

- <https://stackoverflow.com/questions/8080559/excluding-certain-windows-from-screen-capture#comment9903716_8080559> - notes the limits of selective exclusion in GDI capture.
- <https://github.com/luodh/ffmpeg_record_screen> - GDI frames converted to FFmpeg input.
- <https://github.com/Fals3R/Kernel-GDI> - low-level GDI desktop capture/drawing exploration.

## Connections

- `Read Pixels with GetDIBits().md` covers pixel extraction.
- `libcamcapture - GDI Screen Capture.md` is a compact capture-source implementation.
