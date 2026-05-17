# Window Manager Internals (winmgr.c)

`winmgr.c` in the NT RTL layer implements z-order management, `SetWindowPos` routing, and desktop window enumeration. `SetWindowPos` with `SWP_FRAMECHANGED` forces a re-evaluation of all NC metrics and is the correct way to apply a style change made via `SetWindowLongPtr`.

```cpp
// Move a window to the top without changing size/position
RECT rc = {};
GetWindowRect(hwnd, &rc);
SetWindowPos(hwnd, HWND_TOP, rc.left, rc.top,
    rc.right - rc.left, rc.bottom - rc.top, SWP_SHOWWINDOW);

// Toggle TOPMOST without moving
SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/rtl/winmgr.c#L19
- https://shreklane.github.io/winkrnldocs/d3/d7/rtl_2winmgr_8c-source.html#l00856
