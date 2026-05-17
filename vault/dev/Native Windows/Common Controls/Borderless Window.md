# Borderless Window

## CS_DROPSHADOW for popup windows
https://stackoverflow.com/questions/66165781/it-is-possible-to-adjust-the-offset-of-cs-dropshadow-on-a-window-class
Use CS_DROPSHADOW on a tool or popup window class for classic shadows.
```cpp
WNDCLASSEX wc = { sizeof(wc) };
wc.style = CS_DROPSHADOW;
wc.lpfnWndProc = WndProc;
wc.hInstance = hInst;
wc.lpszClassName = L"PopupShadow";
RegisterClassEx(&wc);
HWND hwnd = CreateWindowEx(WS_EX_TOOLWINDOW, wc.lpszClassName, L"", WS_POPUP,
    100, 100, 300, 200, 0, 0, hInst, 0);
```

## Borderless resizable hit testing
https://stackoverflow.com/questions/39731497/create-window-without-titlebar-with-resizable-border-and-without-bogus-6px-whit
Implement WM_NCHITTEST to expose resize borders inside the client area.
```cpp
case WM_NCHITTEST:
{
    POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
    ScreenToClient(hwnd, &pt);
    RECT rc; GetClientRect(hwnd, &rc);
    if (pt.y < 6) return HTTOP;
    if (pt.x < 6) return HTLEFT;
    if (pt.x > rc.right - 6) return HTRIGHT;
    return HTCLIENT;
}
```

## Runtime borderless toggle (BorderlessWindow)
https://github.com/melak47/BorderlessWindow
Toggle caption and frame styles, then force a non-client recalculation.
```cpp
LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
style &= ~WS_CAPTION;
style |= WS_THICKFRAME;
SetWindowLongPtr(hwnd, GWL_STYLE, style);
SetWindowPos(hwnd, NULL, 0, 0, 0, 0,
    SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
```

## DWM custom frame
https://learn.microsoft.com/en-us/windows/win32/dwm/customframe
Extend the DWM frame into the client area to keep the aero shadow.
```cpp
BOOL comp = FALSE;
DwmIsCompositionEnabled(&comp);
if (comp)
{
    MARGINS m = { 0, 0, 0, 0 };
    DwmExtendFrameIntoClientArea(hwnd, &m);
}
```
