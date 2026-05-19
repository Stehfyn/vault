# Window Sizing

`WM_GETMINMAXINFO` is the main hook for top-level tracking constraints. Set `ptMinTrackSize` and `ptMaxTrackSize` to control resize limits, and use `MonitorFromWindow` plus `GetMonitorInfo` when overriding maximized size or position so the work area respects taskbars and the monitor containing the window. Hard-coding primary-screen metrics is the classic multi-monitor bug.

Sizing is also a DPI problem. Minimum widths, splitter thicknesses, toolbar heights, and custom frame borders should be derived from the window's current DPI or font metrics, then recalculated on `WM_DPICHANGED`. A borderless window in particular must pair `WM_GETMINMAXINFO` with non-client hit testing or it will maximize and resize unlike a normal overlapped window.

## References
- <https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-getminmaxinfo> - tracking-size message contract.
- <https://stackoverflow.com/questions/4134946/wm-getminmaxinfo-does-not-seem-to-work-how-to-get-a-windows-minimum-and-maximu> - monitor work-area correction for maximize bounds.

## Connections
- `Borderless Window.md` depends on this for correct custom chrome.
- `DPI Awareness/Per-Monitor V2 DPI Reference.md` covers DPI-triggered recomputation.
