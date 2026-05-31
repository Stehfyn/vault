# Splitter Control

A splitter is just a small state machine around mouse capture and child layout. On button down inside the divider hit zone, call `SetCapture`; on mouse move, clamp the proposed position and relayout children; on button up or capture loss, release the drag. Cursor feedback belongs in hit testing or `WM_SETCURSOR`, not in random paint code.

The difference between a demo splitter and a usable one is constraint handling. Enforce pane minimums during the drag, batch child movement with `DeferWindowPos`, and make the splitter thickness DPI-derived. Otherwise the control will work in the happy path and feel broken under fast drags, high DPI, or small window sizes.

## Source Code Reading

`kurtjm/splitter-layout-win32` is a clean source for the full mouse-capture loop. Read `src/Application.cpp`, `src/Application.h`, and `src/Layout.*`.

`Application::init` registers the main window class with `Application::window_proc`, creates the parent window, builds a parsed layout string, creates child panel windows, stores `this` in `GWLP_USERDATA`, then shows the frame. Child panels are ordinary `WS_CHILD` windows created in `create_layout_windows`; layout changes become `MoveWindow` calls in `update_layout_windows`.

The splitter interaction is explicitly separated:

```cpp
WM_LBUTTONDOWN:
    splitter_select(hwnd, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))

WM_MOUSEMOVE:
    splitter_mouse_move(hwnd, x, y)
    TrackMouseEvent(TME_LEAVE)

WM_LBUTTONUP:
    splitter_clear_selection()

WM_MOUSELEAVE:
    set_cursor(None)

WM_SIZE:
    update_layout_windows()
```

`splitter_select` asks the layout model whether the point is over a vertical, horizontal, or intersection splitter. If a splitter is selected, it calls `SetCapture(hwnd)`. `splitter_mouse_move` has two branches: while selected, update the model and relayout child HWNDs; while not selected, only hit-test and change the cursor. `splitter_clear_selection` clears model state and calls `ReleaseCapture`.

The source makes the observable contract easy to test: drag outside the window and the parent still receives mouse moves because of capture; move without dragging and only the cursor changes; resize the top-level window and every child panel gets a new rectangle. A splitter helper that does not name capture, hit-testing, model update, child movement, and cursor tracking is hiding the actual control.

## References
- <https://github.com/kurtjm/splitter-layout-win32> - straightforward splitter layout sample.

## Connections
- `Splitter Sash Control.md` covers a packaged sash implementation.
- `Multi-Pane Container Control.md` covers N-pane layout after the divider moves.
