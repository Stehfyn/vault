# WTL Examples

WTL is ATL's windowing layer grown into a lightweight application framework: `CWindowImpl`, `CFrameWindowImpl`, message maps, command/update UI routing, dialog helpers, and wrappers over common controls. The examples are useful when they show how WTL maps classic Win32 concepts into templates without hiding the message model entirely.

The key distinction from MFC is deployment and thickness. WTL is mostly headers/templates over ATL and the platform SDK; it does not impose the same runtime library or document/view architecture. The distinction from raw Win32 is the object-to-HWND thunk and message-map dispatch, which is why the ATL x64 thunk note belongs in the same folder.

## Source Shape

Source pass: `wtl-examples/src/wtl_control_examples/Kibbles/mainfrm.h` shows the WTL frame pattern: inheritance supplies the frame, update UI, message filter, and idle hooks; the message map is the routing table from HWND messages and commands into methods.

```cpp
class CMainFrame :
    public CFrameWindowImpl<CMainFrame>,
    public CUpdateUI<CMainFrame>,
    public CMessageFilter,
    public CIdleHandler
{
    BEGIN_MSG_MAP(CMainFrame)
        MSG_WM_CREATE(OnCreate)
        COMMAND_ID_HANDLER_EX(ID_APP_EXIT, OnFileExit)
        CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)
        CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
    END_MSG_MAP()
};
```

The source is useful because it keeps the native message model visible. WTL reduces boilerplate around `WNDPROC`, command routing, toolbar/status-bar state, and common controls; it does not remove reentrancy, HWND lifetime, DPI, or COM apartment concerns.

## Connections

- `ATL x64 stdcall Thunk Reference.md` explains the low-level object-to-window callback mechanism that makes this pattern work.
- `Win32xx (Header-Only ATL-Style Wrapper).md` and `WCL - Win32 C++ Class Library.md` are neighboring lightweight-HWND frameworks.
- `WIL (Windows Implementation Library).md` is complementary: use WIL for resources and HRESULTs, WTL for windows and commands.
- `../(MFC) Microsoft Foundation Classes/MFC Examples.md` is the heavier framework comparison point.

## Experiment Harness

Goal: prove what WTL changes and what remains raw Win32.

```cpp
BEGIN_MSG_MAP(CMainFrame)
    MESSAGE_HANDLER(WM_CREATE, OnCreate)
    MESSAGE_HANDLER(WM_DPICHANGED, OnDpiChanged)
    MESSAGE_HANDLER(WM_NCDESTROY, OnNcDestroy)
END_MSG_MAP()
```

Procedure: log `HWND`, message ID, handler name, and `this` pointer for create, DPI change, command, and destroy paths.

Measured signal: object-to-HWND association, dispatch order, final `WM_NCDESTROY`, accelerator/message-filter hits.

Failure interpretation: WTL reduces boilerplate but does not remove HWND lifetime, message reentrancy, DPI, or COM apartment requirements. Reference: <https://learn.microsoft.com/en-us/cpp/atl/reference/atl-window-classes>.

## References
- <https://github.com/wyrover/wtl-examples> - sample WTL applications demonstrating ATL-style windows, message maps, and control wrappers.
