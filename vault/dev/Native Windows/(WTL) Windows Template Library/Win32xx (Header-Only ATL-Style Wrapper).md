# Win32xx (Header-Only ATL-Style Wrapper)

Win32++ is a header-only C++ wrapper over raw Win32 in the ATL/WTL tradition: `CWnd`, frames, dialogs, views, device contexts, MDI, docking, ribbon support, and message dispatch without an MFC runtime. It is the pragmatic choice when a project wants native HWND/GDI semantics and a small binary, but does not want to write every `WNDPROC`, `CreateWindowEx`, and `WM_COMMAND` switch by hand.

Compare it with WTL and WCL. WTL leans on ATL and Microsoft's older template style; WCL is a smaller personal library; Win32++ is more actively packaged as an application framework. It still does not free you from Win32 rules: HWND lifetime, reentrancy, message order, DPI, and common-control quirks remain visible.

## References
- <https://github.com/DavidNash2024/Win32xx> - maintained header-only C++ framework for classic Win32 desktop applications.
