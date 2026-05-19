# Custom Toolbar Header

`Win32CustomToolbarHeader` is useful as a combined toolbar/header customization reference: create the toolbar with `TOOLBARCLASSNAME`, size buttons with `TB_BUTTONSTRUCTSIZE` and `TB_ADDBUTTONS`, then customize header-style painting through parent `WM_NOTIFY` handling. The point is not the creation boilerplate; it is how comctl32 controls split ownership between control state and parent-supplied drawing.

When customizing a toolbar or header, preserve the control's layout and command semantics unless you are deliberately replacing it. Let comctl32 manage button state, tooltips, and keyboard behavior, and intervene only at the custom-draw stages you need. Full owner painting should also account for DPI-scaled image lists and visual-state changes on hover, press, disabled, and hot tracking.

## References
- <https://github.com/Alexandre-Carpentier/Win32CustomToolbarHeader> - practical toolbar/header custom drawing sample.

## Connections
- `Toolbar and Status Bar.md` covers the stock controls.
- `Rendering.md` covers the `NM_CUSTOMDRAW` stage/return-code model.
