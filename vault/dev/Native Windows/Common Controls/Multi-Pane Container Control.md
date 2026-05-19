# Multi-Pane Container Control

`MultiPaneCtrl` is a layout container for multiple resizable child panes, in the same family as `SplitterCtrl`. The interesting problem is not drawing borders; it is redistribution. When the parent changes size or a sash moves, the control must allocate deltas across panes while respecting minimum sizes and avoiding flicker.

The idiomatic Win32 solution is to batch child moves with `BeginDeferWindowPos`, `DeferWindowPos`, and `EndDeferWindowPos` so all panes commit in one layout pass. This is the difference between a container that feels native and one that flashes through intermediate geometries on every drag.

## References
- <https://github.com/baradzenka/MultiPaneCtrl> - multi-pane Win32 container control.

## Connections
- `Splitter Sash Control.md` covers the draggable divider.
- `Window Sizing.md` covers the parent-level constraints that feed pane layout.
