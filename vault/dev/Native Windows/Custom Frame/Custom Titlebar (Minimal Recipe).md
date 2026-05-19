# Custom Titlebar (Minimal Recipe)

The canonical minimal recipe for a custom-painted caption that still feels native: snap, Aero peek, maximize-quirks, and the invisible resize border all keep working because the window remains a regular top-level window — only the nonclient *paint* is intercepted. Two gotchas this repo gets right that most copies online get wrong: (1) when `WM_NCCALCSIZE` is called with `wParam==TRUE` you must *not* zero the top inset on a maximized window, because Windows positions a maximized frame so that the resize border lies offscreen — subtracting your title height there clips real client pixels; (2) `DwmExtendFrameIntoClientArea` with nonzero margins is what re-enables the DWM drop shadow that a zero-sized nonclient area otherwise kills. Pair this with hit-testing that returns `HTCAPTION` over caption dead-zones so the OS handles drag, double-click-to-maximize, and Win+Arrow snapping for free instead of reimplementing them badly.

## References
- <https://github.com/grassator/win32-window-custom-titlebar>
