# Dark Mode (C Port)

`CWin32DarkMode` is a C-only port of the ysc3839 dark-mode shim. That matters for old C codebases, plug-ins, or tiny Win32 utilities that cannot introduce C++ runtime dependencies just to call undocumented UxTheme ordinals. It dynamically resolves functions such as `AllowDarkModeForWindow` and `SetPreferredAppMode`, then applies dark Explorer themes to individual controls.

The same caveats as the C++ original apply: these APIs are undocumented, ordinal mappings changed across Windows 10 builds, and enabling dark preference does not repaint every classic control correctly. Pair this with explicit `WM_THEMECHANGED` handling and DWM titlebar attributes if the top-level frame must match the client area.

## References
- <https://github.com/TBOpen/CWin32DarkMode> - C implementation of the Win32 dark-mode ordinal shim.

## Connections
- `Darkmode.md` gives the broader C++/DWM context.
- `Visual Styles.md` covers documented UxTheme drawing and `SetWindowTheme`.
