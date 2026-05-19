# Toolbar and Status Bar

Toolbars and status bars are comctl32 controls, not decorative strips. A toolbar needs `TB_BUTTONSTRUCTSIZE` before `TB_ADDBUTTONS`, an image list sized for the current DPI, and command IDs that flow back through `WM_COMMAND`. A status bar uses `SB_SETPARTS` with right-edge coordinates; `-1` makes the final pane stretch, and forwarding `WM_SIZE` lets the control recompute its own height and position.

The old MSDN toolbar/status-bar material is still useful because these controls have not fundamentally changed. Modern polish comes from the surrounding contracts: comctl32 v6 activation, visual styles, DPI-scaled image lists, and owner/custom draw only where the stock rendering cannot match the application.

## References
- <https://learn.microsoft.com/en-us/previous-versions/ms810439(v=msdn.10)?redirectedfrom=MSDN> - classic toolbar/status-bar programming reference.

## Connections
- `Custom Toolbar Header.md` covers custom drawing around toolbar/header surfaces.
- `Visual Styles.md` covers the comctl32 v6 and theming setup.
