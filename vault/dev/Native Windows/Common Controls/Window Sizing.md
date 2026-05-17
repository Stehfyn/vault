# Window Sizing

## WM_GETMINMAXINFO basics
https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-getminmaxinfo
Clamp minimum tracking size during resize or move.
```cpp
case WM_GETMINMAXINFO:
{
    MINMAXINFO* mmi = (MINMAXINFO*)lParam;
    mmi->ptMinTrackSize.x = 640;
    mmi->ptMinTrackSize.y = 480;
    return 0;
}
```

## Monitor-aware max size
https://stackoverflow.com/questions/4134946/wm-getminmaxinfo-does-not-seem-to-work-how-to-get-a-windows-minimum-and-maximu
Use the monitor work area to set max position and size.
```cpp
case WM_GETMINMAXINFO:
{
    MINMAXINFO* mmi = (MINMAXINFO*)lParam;
    HMONITOR hMon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi = { sizeof(mi) };
    if (GetMonitorInfo(hMon, &mi))
    {
        mmi->ptMaxPosition.x = mi.rcWork.left;
        mmi->ptMaxPosition.y = mi.rcWork.top;
        mmi->ptMaxSize.x = mi.rcWork.right - mi.rcWork.left;
        mmi->ptMaxSize.y = mi.rcWork.bottom - mi.rcWork.top;
    }
    return 0;
}
```
