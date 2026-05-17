# Windows with C++ - Write High-DPI Apps for Windows 8.1

MSDN Magazine article on DPI-aware Win32 apps for Windows 8.1. Covers per-monitor DPI awareness introduced in Windows 8.1, handling `WM_DPICHANGED` to reposition/resize windows, and the updated `SetProcessDpiAwarenessContext` API available in Windows 10 1703+.

Key technique: `SetProcessDPIAware()` / `SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2)`

```cpp
// Windows 10 1703+
SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);

// In WM_DPICHANGED:
case WM_DPICHANGED:
{
    RECT* newRect = (RECT*)lParam;
    SetWindowPos(hwnd, nullptr,
        newRect->left, newRect->top,
        newRect->right - newRect->left,
        newRect->bottom - newRect->top,
        SWP_NOZORDER | SWP_NOACTIVATE);
    break;
}
```

## References

- https://learn.microsoft.com/en-us/archive/msdn-magazine/2014/february/windows-with-c-write-high-dpi-apps-for-windows-8-1
