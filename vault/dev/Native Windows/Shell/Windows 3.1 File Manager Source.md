# Windows 3.1 File Manager Source

Microsoft's open-source release of the actual Win3.1 File Manager source, modernized just enough to build on current MSVC and run on Win10/11. Pure Win32 — no MFC, no ATL — and remarkably small (~30 KLOC). Best published reading material for: `MDIClient` / `MDIChild` window class usage, `WM_PAINT` with explicit double-buffering pre-DWM, `ITaskbarList` integration, and the original `IShellFolder`-free way of enumerating directories via `FindFirstFileW`.

## References
- <https://github.com/microsoft/winfile>
