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

## Route Selection

The useful split is not "old API versus new API"; it is which image you are asking Windows to give you.

```cpp
enum class CaptureRoute {
    GdiVisibleDesktop,       // GetDC(NULL) -> BitBlt -> DIB/GetDIBits
    DxgiOutputDuplication,   // IDXGIOutputDuplication -> monitor image
    DwmWindowSurface,        // DwmGetDxSharedSurface -> HWND redirection surface
    GraphicsCaptureItem      // Windows Graphics Capture -> documented modern item capture
};
```

Use `GdiVisibleDesktop` for small tools and CPU-bound screenshots. Use `../(DX) DirectX/DXGI Output Duplication Capture.md` when the next step is GPU copy, encode, or high frame rate. Use `../(DWM) Desktop Window Manager/DwmGetDxSharedSurface Window Capture.md` when the question is "what did DWM keep for this HWND?" rather than "what is on the monitor?"

## Experiment Harness

Goal: learn exactly what GDI capture sees and where it falls apart compared with DXGI/DWM routes.

Procedure:
1. Capture the same rectangle with `GetDC(NULL)` and `GetWindowDC(hwnd)` using `SRCCOPY` and `SRCCOPY | CAPTUREBLT`.
2. Place a layered window, normal overlapped window, video playback, and capture-protected window over the target.
3. Hash the resulting DIB pixels and save only mismatch frames for inspection.

```cpp
BitBlt(mem, 0, 0, w, h, src, x, y, SRCCOPY | CAPTUREBLT);
uint64_t hash = xxhash64(pixels, w * h * 4);
log(route, hash, qpc_blit_cost);
```

Metric: blit time, mismatch count against DXGI output duplication, black/protected regions, layered-window inclusion, and CPU cost per megapixel.

Failure interpretation: black regions can be intentional capture policy. Missing layered windows means `CAPTUREBLT` did not apply to that route or content class. Slow captures mean DIB readback and memory bandwidth dominate; switch to DXGI when the next stage is GPU or video encode.

## Discussion Claim To Verify

The Stack Overflow exclusion thread is more important in 2026 than the old GDI question suggests. The original comment pointed at deprecated DWM filter/image-transform ideas; the later answer points at `SetWindowDisplayAffinity(hwnd, WDA_EXCLUDEFROMCAPTURE)`. That turns "can BitBlt exclude my own window?" into a policy probe across capture APIs.

```cpp
SetWindowDisplayAffinity(owned_top_level_hwnd, WDA_EXCLUDEFROMCAPTURE);

for (auto route : { GdiBitBlt, DxgiDuplication, GraphicsCapture }) {
    auto frame = CaptureSameDesktopRect(route);
    log(route, ContainsMarkerPixels(frame, owned_window_marker),
        HashRect(frame, owned_window_bounds));
}
```

Expected interpretation: `WDA_EXCLUDEFROMCAPTURE` applies only to a top-level window owned by the current process and depends on DWM composition. If GDI still sees the marker while Windows Graphics Capture excludes it, the claim is API-dependent rather than false. If all documented routes exclude it but a private DWM-surface route still sees content, that route is outside the policy model the note is testing and should be documented as an observation, not a supported bypass.

## References

- <https://stackoverflow.com/questions/8080559/excluding-certain-windows-from-screen-capture#comment9903716_8080559> - notes the limits of selective exclusion in GDI capture.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowdisplayaffinity> - documented display-affinity and capture-exclusion contract.
- <https://github.com/luodh/ffmpeg_record_screen> - GDI frames converted to FFmpeg input.
- <https://github.com/Fals3R/Kernel-GDI> - low-level GDI desktop capture/drawing exploration.
- <https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-bitblt> - `BitBlt` and `CAPTUREBLT` contract.

## Connections

- `Read Pixels with GetDIBits().md` covers pixel extraction.
- `libcamcapture — GDI Screen Capture.md` is a compact capture-source implementation.
- `../(DX) DirectX/DXGI Output Duplication Capture.md` is the monitor-frame GPU path.
- `../(DWM) Desktop Window Manager/Capture-Protected Window (Sprite Hack).md` explains why some compositor content is intentionally blacked out in capture.
