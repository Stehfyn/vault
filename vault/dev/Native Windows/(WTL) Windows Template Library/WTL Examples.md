# WTL Examples

WTL is ATL's windowing layer grown into a lightweight application framework: `CWindowImpl`, `CFrameWindowImpl`, message maps, command/update UI routing, dialog helpers, and wrappers over common controls. The examples are useful when they show how WTL maps classic Win32 concepts into templates without hiding the message model entirely.

The key distinction from MFC is deployment and thickness. WTL is mostly headers/templates over ATL and the platform SDK; it does not impose the same runtime library or document/view architecture. The distinction from raw Win32 is the object-to-HWND thunk and message-map dispatch, which is why the ATL x64 thunk note belongs in the same folder.

## References
- <https://github.com/wyrover/wtl-examples> - sample WTL applications demonstrating ATL-style windows, message maps, and control wrappers.
