A transparent, click-through overlay window is created with `WS_EX_LAYERED | WS_EX_TRANSPARENT`. `SetLayeredWindowAttributes` with `LWA_ALPHA` controls opacity. To toggle click-through at runtime, add or remove `WS_EX_TRANSPARENT` from the extended style with `SetWindowLongPtr`.

```cpp
#include <windows.h>

HWND CreateOverlayWindow(HINSTANCE hInst, int w, int h)
{
    // WS_EX_LAYERED   – enables transparency / per-pixel alpha
    // WS_EX_TRANSPARENT – passes all mouse input through to windows below
    // WS_EX_TOPMOST   – always on top
    HWND hwnd = CreateWindowEx(
        WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST | WS_EX_NOACTIVATE,
        L"OverlayClass", L"Overlay",
        WS_POPUP,                  // no title-bar / border
        0, 0, w, h,
        NULL, NULL, hInst, NULL);

    // 1/255 alpha: nearly invisible but still "exists" for the compositor
    SetLayeredWindowAttributes(hwnd, 0, 1, LWA_ALPHA);

    ShowWindow(hwnd, SW_SHOWNOACTIVATE);
    return hwnd;
}

// Toggle click-through: remove WS_EX_TRANSPARENT to capture mouse input
void SetClickThrough(HWND hwnd, bool enable)
{
    LONG_PTR style = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
    if (enable)
        style |=  WS_EX_TRANSPARENT;
    else
        style &= ~WS_EX_TRANSPARENT;
    SetWindowLongPtr(hwnd, GWL_EXSTYLE, style);
}
```

## References
- https://github.com/zaafar/ClickableTransparentOverlay
