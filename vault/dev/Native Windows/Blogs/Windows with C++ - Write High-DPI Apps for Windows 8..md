# Windows with C++ - Write High-DPI Apps for Windows 8.1

This MSDN Magazine article is a useful snapshot of per-monitor DPI awareness as it became a normal Win32 responsibility. The key lesson remains current: a DPI-aware app must handle scale changes dynamically, not just opt out of bitmap stretching at process startup.

Connect it to Custom Frame and shell-window entries. Frameless windows, owner-drawn controls, tray utilities, and Direct2D surfaces all need coherent `WM_DPICHANGED` handling, font/resource scaling, and suggested-rectangle adoption or they look broken on mixed-DPI desktops.

## References
- <https://learn.microsoft.com/en-us/archive/msdn-magazine/2014/february/windows-with-c-write-high-dpi-apps-for-windows-8-1>
