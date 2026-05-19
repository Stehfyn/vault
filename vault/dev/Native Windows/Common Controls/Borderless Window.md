# Borderless Window

A credible borderless Win32 window is not just `WS_POPUP`. You need non-client behavior back: resize hit-testing in `WM_NCHITTEST`, monitor-aware maximize bounds through `WM_GETMINMAXINFO`, and a DWM shadow or frame extension if the window should still read as a top-level app. Removing `WS_CAPTION` while keeping `WS_THICKFRAME` is the common compromise; after changing styles at runtime, call `SetWindowPos(..., SWP_FRAMECHANGED)` so USER recalculates the non-client area.

## Runtime Style Change

The BorderlessWindow sample contributes the style-toggle pattern. USER caches frame metrics, so the frame-changed `SetWindowPos` call is not optional.

```cpp
LONG_PTR style = GetWindowLongPtrW(hwnd, GWL_STYLE);
style &= ~WS_CAPTION;
style |= WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
SetWindowLongPtrW(hwnd, GWL_STYLE, style);
SetWindowPos(hwnd, nullptr, 0, 0, 0, 0,
             SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
             SWP_NOACTIVATE | SWP_FRAMECHANGED);
```

## Hit Testing and DWM Frame

The custom-frame and Stack Overflow links contribute the missing behavior: resize borders and DWM-owned shadow/chrome need explicit hit-test and frame handling.

```cpp
case WM_NCHITTEST: {
    POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
    RECT rc;
    GetWindowRect(hwnd, &rc);
    const int grip = GetSystemMetrics(SM_CXFRAME) + GetSystemMetrics(SM_CXPADDEDBORDER);
    if (pt.x < rc.left + grip) return HTLEFT;
    if (pt.x >= rc.right - grip) return HTRIGHT;
    if (pt.y < rc.top + grip) return HTTOP;
    if (pt.y >= rc.bottom - grip) return HTBOTTOM;
    return HTCLIENT;
}
```

## References

- <https://github.com/melak47/BorderlessWindow> - focused runtime style-toggle example.
- <https://learn.microsoft.com/en-us/windows/win32/dwm/customframe> - Microsoft's DWM custom-frame baseline.
- <https://stackoverflow.com/questions/39731497/create-window-without-titlebar-with-resizable-border-and-without-bogus-6px-whit> - discusses client-area hit testing for borderless resize.

## Connections

- `Window Sizing.md` covers `WM_GETMINMAXINFO`.
- `Darkmode.md` covers DWM attributes that often accompany custom chrome.
