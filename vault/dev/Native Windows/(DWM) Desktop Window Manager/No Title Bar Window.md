# No Title Bar Window

Removing the title bar is not just "use `WS_POPUP`". The moment you strip the non-client area, you inherit the work DWM and USER32 normally do for you: hit testing for resize borders, maximize/snap affordances, DPI-aware frame metrics, dark-mode caption colors, and caption button layout. `WM_NCCALCSIZE` removes the frame; `WM_NCHITTEST` and `DwmExtendFrameIntoClientArea` decide whether the resulting window still behaves like a Windows window.

Use `WS_POPUP` for true borderless surfaces such as overlays or games. For normal app chrome, prefer keeping an overlapped window and customizing the non-client area, otherwise Snap Layouts and system menu behavior degrade quickly.

## Snippet
```c
HWND hwnd = CreateWindowEx(
    0, L"MyClass", L"",
    WS_POPUP | WS_VISIBLE,
    0, 0, width, height,
    nullptr, nullptr, hInstance, nullptr);

SetWindowLong(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
SetWindowPos(hwnd, nullptr, 0, 0, width, height, SWP_FRAMECHANGED);

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_NCCALCSIZE && wParam)
    {
        return 0; // remove title bar + borders
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
```

## References
- https://stackoverflow.com/questions/7442939/opening-a-window-that-has-no-title-bar-with-win32
- Related: `Snap Layout API.md`, `Title Bar Customization.md`, `DWM Internals Documentation.md`
