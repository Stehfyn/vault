# Dark Mode Library (Maintained)

A maintained, packaged fork of the ysc3839 dark-mode work, turned into a drop-in library with explicit per-control subclasses (button, combobox, listview, treeview, status bar, tab, header, scrollbar) instead of just the global `SetWindowTheme(hwnd, L"DarkMode_Explorer", nullptr)` trick. Worth pulling in over rolling your own because it has already absorbed the breaking changes between 1809, 1903, and 22H2 in the undocumented `uxtheme.dll` ordinals (cf. ysc3839/win32-darkmode for the original PoC, TBOpen/CWin32DarkMode for the C port, Pixelsuft/win32-darkmode-test for a minimal repro).

## References
- <https://github.com/ozone10/win32-darkmodelib>
