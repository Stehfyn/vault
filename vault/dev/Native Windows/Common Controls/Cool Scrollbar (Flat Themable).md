# Cool Scrollbar (Flat Themable)

CoolSB is a pre-UxTheme scrollbar replacement that subclasses an existing `HWND` and takes over non-client scrollbar behavior. The notable technique is that it does not create a parallel child control; it intercepts non-client sizing, painting, and hit testing so a window with `WS_VSCROLL` / `WS_HSCROLL` can keep its normal client behavior while presenting a custom flat scrollbar.

That makes it a good reference for the hard version of control skinning: the scrollbar is part of the non-client area, so painting alone is insufficient. You have to reserve space in `WM_NCCALCSIZE`, return the right codes from `WM_NCHITTEST`, track hover/pressed state, and forward enough scrolling semantics that the hosted control still behaves like a normal Win32 window.

## References
- <https://github.com/jsleroy/CoolSB> - classic subclass-based non-client scrollbar replacement.

## Connections
- `Visual Styles.md` covers the later UxTheme approach.
- `Window Messaging.md` matters because subclassed controls must preserve unhandled message behavior.
