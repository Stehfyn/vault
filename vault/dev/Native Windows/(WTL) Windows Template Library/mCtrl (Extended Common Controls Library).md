# mCtrl (Extended Common Controls Library)

mCtrl is Martin Mitas's C library of controls that COMCTL32 never shipped: grid, HTML view, chart, MDI tab, expandable sections, tree-list, and image view. Its design matters because it follows native common-control conventions rather than inventing a framework: register window classes, create child HWNDs, configure with messages, and notify parents through `WM_NOTIFY`.

This belongs with WTL/Win32xx/custom-control notes because it is the raw Win32 answer to "I need richer controls but not Qt/WPF." Compare it with `CustCntl.h`: that header described design-time custom controls for old dialog editors; mCtrl is a runtime control library meant to be embedded in normal Win32 apps.

## References
- <https://github.com/mity/mctrl> - C extended-control library complementary to USER32 and COMCTL32 controls.
