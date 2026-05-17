# AppBar (Application Desktop Toolbar)

AppBars are windows that dock to a screen edge like the taskbar. Register with `SHAppBarMessage(ABM_NEW)`, request an edge with `ABM_QUERYPOS` / `ABM_SETPOS`, then set the window position to match. The shell reserves the edge and excludes it from `SystemParametersInfo(SPI_GETWORKAREA)`.

```cpp
APPBARDATA abd = { sizeof(abd) };
abd.hWnd = hwnd;
abd.uCallbackMessage = WM_APP + 20;
abd.uEdge = ABE_BOTTOM;
abd.rc = { 0, screenH - 40, screenW, screenH };

SHAppBarMessage(ABM_NEW, &abd);
SHAppBarMessage(ABM_QUERYPOS, &abd);   // shell may adjust abd.rc
SHAppBarMessage(ABM_SETPOS, &abd);     // claim the position
SetWindowPos(hwnd, HWND_TOP, abd.rc.left, abd.rc.top,
    abd.rc.right - abd.rc.left, abd.rc.bottom - abd.rc.top, SWP_SHOWWINDOW);
```

## References
- https://github.com/Open-Shell/Open-Shell-Menu/issues/91
