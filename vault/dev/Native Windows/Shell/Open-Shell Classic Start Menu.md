# Open-Shell Classic Start Menu

Community-maintained continuation of Ivo Beltchev's Classic Shell after he stopped public development. ATL/COM-heavy C++ codebase that ships an in-process shell extension hosting a Windows-7-style start menu, classic Explorer toolbar, and an IE9-era address bar. Important reference for: subclassing the shell's `Shell_TrayWnd`, injecting an `IShellFolder` enumeration via `SHGetDesktopFolder`, and `SetWindowsHookEx(WH_GETMESSAGE)` to redirect Win-key presses without breaking the OS shortcuts.

## References
- <https://github.com/Open-Shell/Open-Shell-Menu>
