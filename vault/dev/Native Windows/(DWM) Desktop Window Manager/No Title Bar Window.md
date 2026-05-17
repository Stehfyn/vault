# No Title Bar Window

Use `WS_POPUP`/`SetWindowLong` to remove standard chrome, and strip the non-client area via `WM_NCCALCSIZE`.

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
