# Feedback Cursor

This sample covers the old but still useful cursor-feedback path: change the cursor while a window is busy, hit-testing, dragging, or waiting on an operation that should not look idle. The nuance is that cursors are part of message handling; `WM_SETCURSOR`, capture, and modal loops can override one-off cursor calls.

Connect it to `Mouse Input`, custom-frame hit testing, and shell drag/drop notes. Cursor state is a UI contract with the current HWND and thread, not just a global decoration.

## References
- <https://learn.microsoft.com/en-us/windows/win32/menurc/using-cursors>
