# Splitter Sash Control

`SplitterCtrl` packages the draggable sash half of a pane layout. The non-obvious pieces are all message-contract details: capture the mouse so the drag survives leaving the bar, return `TRUE` from `WM_SETCURSOR` after setting `IDC_SIZEWE` or `IDC_SIZENS`, and clamp movement before notifying or resizing consumers.

This pairs naturally with `MultiPaneCtrl`: the sash should report a constrained delta, while the container decides how that delta redistributes across child panes. Keeping those responsibilities separate avoids rubber-band drag behavior and duplicated min-size logic.

## References
- <https://github.com/baradzenka/SplitterCtrl> - Win32 splitter/sash control.

## Connections
- `Multi-Pane Container Control.md` covers pane redistribution.
- `Splitter Control.md` outlines the from-scratch message loop.
