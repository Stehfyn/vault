# WCL - Chris Oldwood Win32 C++ Class Library

WCL is Chris Oldwood's personal C++ wrapper over Win32 from the pre-modern-template era: windows, dialogs, GDI objects, registry helpers, app classes, and small ownership wrappers without MFC's runtime or WTL's ATL dependency. It is a historical but readable answer to "what if MFC had stayed thin?"

Its value is comparative. WCL shows object-oriented Win32 before RAII-heavy WIL and before header-only ATL-style libraries such as Win32xx became common. Read it for message-pump structure, dialog/window ownership, and how much boilerplate a single-developer library chooses to hide without changing the underlying API model.

Code contribution: compare wrappers around `HWND`, `WNDPROC`, dialog procedures, `HDC`, registry handles, and message maps with WTL/WIL equivalents.

## References
- <https://github.com/chrisoldwood/WCL> - compact C++ class library wrapping classic Win32 application and UI primitives.
