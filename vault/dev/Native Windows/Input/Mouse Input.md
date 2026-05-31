# Mouse Input

Classic Win32 mouse input is HWND-relative message delivery, not a device stream. `WM_MOUSEMOVE`, button messages, capture, hit testing, and coordinate conversion are all tied to the thread's message queue and the target window; `GetCursorPos` gives screen coordinates, while `ScreenToClient` maps them into the client area that rendering code actually uses.

The distinction matters when mixing old and new input paths. Raw Input can report hardware packets while unfocused, `SendInput` targets the foreground queue, `PostMessage` can fake messages only for controls that trust their queue, and `InteractionContext` consumes pointer frames to synthesize gestures. This page is the baseline for those comparisons.

## Source Shape

Mouse messages are window-contract events. Capture, coordinate conversion, and hit-test intent all have to stay together.

```cpp
case WM_LBUTTONDOWN:
    SetCapture(hwnd);
    break;

case WM_MOUSEMOVE: {
    POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
    if (GetCapture() == hwnd) {
        TrackDragInClientCoordinates(hwnd, pt);
    }
    break;
}

case WM_LBUTTONUP:
    if (GetCapture() == hwnd) {
        ReleaseCapture();
    }
    break;
```

Screen-space APIs must be converted before they feed client painting or gesture code.

```cpp
POINT pt;
GetCursorPos(&pt);
ScreenToClient(hwnd, &pt);
```

## References
- <https://web.archive.org/web/20070123100817/http://msdn.microsoft.com/library/en-us/winui/winui/windowsuserinterface/userinput/mouseinput/aboutmouseinput.asp>

## Connections
- `../Message Queue/System-Defined Messages.md` explains how mouse messages reach the owner thread.
- `InteractionContext.h - Pointer Gesture Interpreter.md` is the route from pointer frames to gestures.
- `afk-clicker - Unfocused Window Auto-Clicker.md` shows why posting mouse messages is not equivalent to real device input.
