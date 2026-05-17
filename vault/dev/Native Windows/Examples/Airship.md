Size-optimized Win32 desktop toy written in C89 that renders an animated airship floating across the screen. The window uses `WS_EX_LAYERED` and `WS_EX_TRANSPARENT` for click-through transparency, and `SetLayeredWindowAttributes` to key out the background color. Supports autorun, launch/expire dates, screensaver/logon events, and autohide. Compresses to ~3 KB with executable packers.

```c
// Layered, click-through transparent window — core pattern used by Airship
HWND hwnd = CreateWindowExA(
    WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST | WS_EX_TOOLWINDOW,
    className, NULL,
    WS_POPUP | WS_VISIBLE,
    x, y, w, h,
    NULL, NULL, hInstance, NULL);

// Make magenta (RGB 255,0,255) the transparent color key
SetLayeredWindowAttributes(hwnd, RGB(255, 0, 255), 255, LWA_COLORKEY);

// ~33 fps animation via WM_TIMER
SetTimer(hwnd, 1, 30, NULL);

// In WndProc WM_TIMER: advance position and redraw sprite
case WM_TIMER:
    x = (x + 2) % GetSystemMetrics(SM_CXSCREEN);
    SetWindowPos(hwnd, HWND_TOPMOST, x, y, w, h, SWP_NOSIZE | SWP_NOACTIVATE);
    InvalidateRect(hwnd, NULL, TRUE);
    break;
```

## References

- <https://github.com/joric/airship>
