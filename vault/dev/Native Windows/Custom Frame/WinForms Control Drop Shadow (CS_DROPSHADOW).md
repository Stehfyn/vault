# WinForms Control Drop Shadow (CS_DROPSHADOW)

Stack Overflow Q&A on giving WinForms controls a real drop shadow. The trick is to OR `CS_DROPSHADOW` (0x00020000) into the window class style by overriding `CreateParams.ClassStyle`. This is the same class style that gives Win32 tooltips/menus their drop shadow at the OS level (no GDI/manual blur work, DWM handles it). Caveat: only applies to top-level windows / popups; for child controls inside a form, the class-style approach won't do anything — you need a layered popup or owner-drawn shadow.

## References
- <https://stackoverflow.com/questions/2463519/drop-shadow-in-winforms-controls>
