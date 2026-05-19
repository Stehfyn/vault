# Splitter Control

A splitter is just a small state machine around mouse capture and child layout. On button down inside the divider hit zone, call `SetCapture`; on mouse move, clamp the proposed position and relayout children; on button up or capture loss, release the drag. Cursor feedback belongs in hit testing or `WM_SETCURSOR`, not in random paint code.

The difference between a demo splitter and a usable one is constraint handling. Enforce pane minimums during the drag, batch child movement with `DeferWindowPos`, and make the splitter thickness DPI-derived. Otherwise the control will work in the happy path and feel broken under fast drags, high DPI, or small window sizes.

## References
- <https://github.com/kurtjm/splitter-layout-win32> - straightforward splitter layout sample.

## Connections
- `Splitter Sash Control.md` covers a packaged sash implementation.
- `Multi-Pane Container Control.md` covers N-pane layout after the divider moves.
