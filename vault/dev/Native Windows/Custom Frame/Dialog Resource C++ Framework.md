# Dialog Resource C++ Framework

Rodrigo Cesar de Freitas Dias's C++20 take on dialog-resource-driven Win32 GUIs — same author as winsafe (#55), and you can feel the Rust influence: minimalist, single-header (`<windlg/lib.h>`), drop the `.cpp`s into your build, no DLL, no macros, no MFC, no ATL. The opinion baked in: *write your UI in the resource editor (.rc DIALOGEX), not in code* — controls already exist by ID at `WM_INITDIALOG`, so the C++ side just attaches typed wrappers and wires events. The opposite philosophy of WinUI/XAML and the opposite philosophy of melak47/BorderlessWindow (#72) which is all imperative. Pick it over Win32xx (#47) if you want C++20 modules-era ergonomics and don't need MDI/docking.

## References
- <https://github.com/rodrigocfd/windlg>
