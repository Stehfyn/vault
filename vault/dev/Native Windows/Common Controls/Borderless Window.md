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

## Source Code Reading

`melak47/BorderlessWindow/src/BorderlessWindow.cpp` is a concrete answer to "what composes a borderless helper?"

The style table defines three states:

```cpp
windowed         = WS_OVERLAPPEDWINDOW
aero_borderless  = WS_POPUP | WS_THICKFRAME | WS_CAPTION | WS_SYSMENU | ...
basic_borderless = WS_POPUP | WS_THICKFRAME              | WS_SYSMENU | ...
```

`select_borderless_style` calls `DwmIsCompositionEnabled` and chooses the Aero path only when composition is active. `set_borderless` compares the current mode, updates the stored boolean, calls `SetWindowLongPtrW(handle, GWL_STYLE, new_style)`, toggles shadow state, calls `ShowWindow(handle, SW_SHOW)`, and finally calls `SetWindowPos(..., SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE)`. That last call is the cache invalidation for USER's non-client metrics.

`set_shadow` calls `DwmExtendFrameIntoClientArea` with one of two `MARGINS` values. The sample uses DWM frame extension as the shadow/backdrop lever; it is not produced by `WS_POPUP` alone.

The WndProc path stores the C++ object pointer during `WM_NCCREATE`:

```cpp
auto* userdata = ((CREATESTRUCT*)lparam)->lpCreateParams;
SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)userdata);
```

Then it routes:

- `WM_NCCALCSIZE`: when `wParam == TRUE` and borderless mode is active, return `0` so the client consumes the frame area.
- `WM_NCHITTEST`: call `DefWindowProcW` first; if the result is `HTCLIENT` and borderless mode is active, compute edge/corner zones and return `HTLEFT`, `HTTOPRIGHT`, `HTCAPTION`, or `HTCLIENT`.
- `WM_KEYUP`: F8/F9/F10/F11 toggle drag, resize, borderless mode, and shadow.

The helper behind hit testing is not magic. It compares the screen-space cursor point with `GetWindowRect`, uses `GetSystemMetrics(SM_CXFRAME)` and `SM_CYFRAME` for border thickness, builds a bitmask for left/right/top/bottom, and maps the bitmask to `HT*` constants. The observable result is normal OS resize cursors and resize loops even though the visible caption is gone.

## Discussion Claim To Verify

Claim: the "resizable border without the bogus stripe" discussion is not solved by a style bit. It is a three-part contract: invalidate cached frame metrics with `SWP_FRAMECHANGED`, answer non-client sizing/hit-test messages, and decide whether DWM frame extension is part of the visual result.

Why it matters for new code: a borderless helper that only toggles `WS_POPUP` will ship broken maximize bounds, missing resize cursors, invisible resize grips, or stale frame metrics. New code should expose these as separately testable functions: `ApplyStyle`, `ApplyDwmFrame`, `HitTestResizeBorder`, and `ApplyMaximizeBounds`.

How to verify:

- Use Spy++ to watch `WM_NCCALCSIZE`, `WM_NCHITTEST`, and `WM_GETMINMAXINFO` while toggling borderless mode.
- Temporarily remove `SWP_FRAMECHANGED`; the visual/style state and USER's cached non-client metrics should diverge.
- Set breakpoints on your `WM_NCHITTEST` branch and drag each edge/corner. The return value must move through `HTLEFT`, `HTTOPLEFT`, `HTBOTTOMRIGHT`, etc., not just `HTCLIENT`.

Minimal code/pseudocode:

```text
ApplyBorderless(hwnd):
    style = GetWindowLongPtr(hwnd, GWL_STYLE)
    style = (style & ~WS_CAPTION) | WS_THICKFRAME | WS_SYSMENU
    SetWindowLongPtr(hwnd, GWL_STYLE, style)
    SetWindowPos(hwnd, 0, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED)

WndProc(WM_NCHITTEST):
    if edge_or_corner(cursor, window_rect, dpi_frame):
        return matching_HT_constant
    return HTCAPTION_or_HTCLIENT
```

Interpretation: if Spy++ never sees your non-client messages after the style change, your helper is not participating in USER's frame negotiation. If hit testing works but maximize still covers the taskbar, the missing piece is `WM_GETMINMAXINFO`, not the borderless style.

## References

- <https://github.com/melak47/BorderlessWindow> - focused runtime style-toggle example.
- <https://learn.microsoft.com/en-us/windows/win32/dwm/customframe> - Microsoft's DWM custom-frame baseline.
- <https://stackoverflow.com/questions/39731497/create-window-without-titlebar-with-resizable-border-and-without-bogus-6px-whit> - discusses client-area hit testing for borderless resize.

## Connections

- `Window Sizing.md` covers `WM_GETMINMAXINFO`.
- `Darkmode.md` covers DWM attributes that often accompany custom chrome.
