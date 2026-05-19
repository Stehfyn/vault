# MFC Examples

MFC examples matter only when they show the framework machinery that raw Win32 hides: `CWinApp` process lifetime, `CWnd`/`CFrameWnd` HWND ownership, message maps, document/view routing, `CDialog` modal state, `CString`/`CArray` legacy containers, and resource-driven UI. A minimal `CWinApp` fragment is too shallow by itself because it hides the real reasons old codebases still use MFC.

Keep sample collections here for reading patterns, not for copying style wholesale. The important editorial connection is to WTL/Win32xx: all three wrap HWNDs and messages, but MFC also brings a runtime, serialization/document architecture, resource conventions, and decades of compatibility baggage that affect deployment and maintenance.

## References
- <https://github.com/jwhu1024/MFC> - MFC sample collection; inspect individual samples for message maps, dialogs, and document/view structure.
- <https://files.cbps.xyz/archive/ipw/exe/source/> - archived legacy source tree useful for older MFC/Win32 idioms; verify provenance and relevance before relying on it.
