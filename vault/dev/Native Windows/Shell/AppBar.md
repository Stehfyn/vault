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

## Experiment Harness

Goal: verify the shell reserved work area and callback behavior.

```cpp
RECT before{}, after{};
SystemParametersInfoW(SPI_GETWORKAREA, 0, &before, 0);

APPBARDATA abd{ sizeof(abd) };
abd.hWnd = hwnd;
abd.uCallbackMessage = WM_APP + 20;
abd.uEdge = ABE_BOTTOM;
abd.rc = { 0, screenH - 48, screenW, screenH };
auto r1 = SHAppBarMessage(ABM_NEW, &abd);
auto r2 = SHAppBarMessage(ABM_QUERYPOS, &abd);
auto r3 = SHAppBarMessage(ABM_SETPOS, &abd);

SystemParametersInfoW(SPI_GETWORKAREA, 0, &after, 0);
printf("new=%Iu query=%Iu set=%Iu workarea_delta=%ld\n",
       r1, r2, r3, before.bottom - after.bottom);
```

Measured signal: `SHAppBarMessage` return values, adjusted rectangle, work-area delta, callback messages after taskbar/monitor changes.

Failure interpretation: if work area does not change, the appbar is only a topmost window; if callbacks do not arrive, the shell cannot negotiate edge changes. Reference: <https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shappbarmessage>.
