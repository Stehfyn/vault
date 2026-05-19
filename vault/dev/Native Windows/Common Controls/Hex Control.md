# Hex Control

HexCtrl is a substantial pure-Win32 hex viewer/editor rather than a demo control. The important capabilities are virtual data mode for very large inputs, mutable buffers, bookmarks, search/replace, undo/redo, custom colors, data interpretation, and Per-Monitor V2 DPI support. That makes it a useful reference for how a complex custom control handles state, painting, scrolling, and command surfaces without switching UI frameworks.

The integration model is also instructive: it can be created as a normal child window or attached to a dialog custom-control placeholder. For a vault of native UI notes, HexCtrl is more valuable as an architecture example than as "a hex widget": it shows the amount of infrastructure required when owner drawing stops being a cosmetic tweak and becomes an application surface.

## References
- <https://github.com/jovibor/HexCtrl> - full-featured Win32 hex editor/viewer control.

## Connections
- `Custom Controls.md` covers the custom-control design categories.
- `Per-Monitor V2 DPI Reference.md` explains the DPI contract HexCtrl explicitly supports.
