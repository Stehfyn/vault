Synthesize mouse button events with `mouse_event` (legacy) or the preferred `SendInput` API. `MOUSEEVENTF_LEFTDOWN` followed by `MOUSEEVENTF_LEFTUP` produces a complete left-click; absolute-position clicks require normalising coordinates to the [0, 65535] range.

```cpp
#include <windows.h>

// Legacy approach (still works, simpler for quick use)
void ClickAtCursor_Legacy()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP,   0, 0, 0, 0);
}

// Modern approach using SendInput (preferred, respects UIPI)
void ClickAtCursor()
{
    INPUT inputs[2] = {};
    inputs[0].type       = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    inputs[1].type       = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(2, inputs, sizeof(INPUT));
}

// Click at an absolute screen position
void ClickAt(int screenX, int screenY)
{
    int normX = MulDiv(screenX, 65535, GetSystemMetrics(SM_CXSCREEN));
    int normY = MulDiv(screenY, 65535, GetSystemMetrics(SM_CYSCREEN));

    INPUT inputs[2] = {};
    inputs[0].type       = INPUT_MOUSE;
    inputs[0].mi.dx      = normX;
    inputs[0].mi.dy      = normY;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
    inputs[1].type       = INPUT_MOUSE;
    inputs[1].mi.dx      = normX;
    inputs[1].mi.dy      = normY;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE;
    SendInput(2, inputs, sizeof(INPUT));
}
```

## References
- https://github.com/Stevie-O/MouseClicker/blob/master/MouseClicker.cpp
- https://github.com/windows-2048/The-Fastest-Mouse-Clicker-for-Windows
