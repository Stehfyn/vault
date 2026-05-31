# Custom Titlebar (Minimal Recipe)

The canonical minimal recipe for a custom-painted caption that still feels native: snap, Aero peek, maximize-quirks, and the invisible resize border all keep working because the window remains a regular top-level window — only the nonclient *paint* is intercepted. Two gotchas this repo gets right that most copies online get wrong: (1) when `WM_NCCALCSIZE` is called with `wParam==TRUE` you must *not* zero the top inset on a maximized window, because Windows positions a maximized frame so that the resize border lies offscreen — subtracting your title height there clips real client pixels; (2) `DwmExtendFrameIntoClientArea` with nonzero margins is what re-enables the DWM drop shadow that a zero-sized nonclient area otherwise kills. Pair this with hit-testing that returns `HTCAPTION` over caption dead-zones so the OS handles drag, double-click-to-maximize, and Win+Arrow snapping for free instead of reimplementing them badly.

## Source Shape

The practical call sequence is DWM first, then non-client calculation, then hit testing. Let DWM consume caption-button messages before your client chrome handles the rest.

```cpp
LRESULT result = 0;
if (DwmDefWindowProc(hwnd, msg, wParam, lParam, &result)) {
    return result;
}

case WM_NCCALCSIZE:
    if (wParam) {
        AdjustClientForCustomCaption(hwnd,
            reinterpret_cast<NCCALCSIZE_PARAMS *>(lParam));
        return 0;
    }
    break;

case WM_NCHITTEST:
    return HitTestCaptionAndResizeBorder(hwnd, GET_X_LPARAM(lParam),
                                         GET_Y_LPARAM(lParam));
```

The maximize case is the trap: derive the resize-border/caption math from monitor work area and current DPI instead of subtracting a constant title height.

## References
- <https://github.com/grassator/win32-window-custom-titlebar>

## Connections
- `Borderless Window (Aero Shadow).md` is the complete shadow/Snap variant of the same recipe.
- `Custom Chrome Sample (NCCALCSIZE).md` isolates the NCCALCSIZE/NCHITTEST mechanics.
- `../Common Controls/Window Sizing.md` covers the maximize/min-track side.
- `../DPI Awareness/Per-Monitor V2 DPI Reference.md` covers per-monitor border and caption metrics.
