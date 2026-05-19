# Per-Monitor V2 DPI Reference

Per-Monitor V2 is the first Win32 DPI mode that makes non-client scaling, child-window notifications, and dialog behavior coherent enough for serious multi-monitor apps. The trap is load compatibility: functions such as `SetProcessDpiAwarenessContext`, `GetDpiForWindow`, `AdjustWindowRectExForDpi`, and `EnableNonClientDpiScaling` do not exist on older systems, so robust code resolves them dynamically and degrades without preventing the binary from loading.

Correct handling centers on `WM_DPICHANGED`. Use the `RECT*` in `lParam` for the new window bounds, rebuild DPI-derived fonts and metrics, and resize child controls immediately. Per-Monitor V2 does not magically scale owner-drawn content; it merely tells you when the scale changed and makes the OS-managed pieces less wrong.

## References
- <https://github.com/tringi/win32-dpi> - focused sample for runtime-resolved DPI APIs across old and new Windows.

## Connections
- `Per-Window DPI Awareness.md` covers temporary thread-context changes for mixed-DPI HWND creation.
- `emphasize - Tringi Win32 Utility Snippets.md` shows the same patterns inside practical Win32 utility code.
