<!-- generated-from-dump2 -->
# Fazen2d — Console Cell-Grid 2D Framework

Console-based 2D "graphics" framework for Windows that treats the conhost cell grid as a 2D framebuffer. Draws shapes/sprites/text by writing CHAR_INFO arrays via `WriteConsoleOutput`, optionally using a double-buffered backing screen buffer + `SetConsoleActiveScreenBuffer` to avoid tearing. The teaching value is the double-buffer pattern: most beginner console games flicker because they `printf`+`SetConsoleCursorPosition`, and the fix is to maintain two `CONSOLE_SCREEN_BUFFER` handles and atomically swap. Unicode support requires the console's code page set to 65001 (UTF-8) or the wide-char API path.

```cpp
#include <windows.h>
// Double-buffered console drawing pattern Fazen2d implements:
HANDLE back = CreateConsoleScreenBuffer(
    GENERIC_READ|GENERIC_WRITE, 0, NULL,
    CONSOLE_TEXTMODE_BUFFER, NULL);

COORD size = {80, 25};
CHAR_INFO frame[80 * 25]{};
// ...fill frame[] with shapes/sprites/text...

SMALL_RECT region = {0, 0, 79, 24};
WriteConsoleOutputW(back, frame, size, {0,0}, &region);
SetConsoleActiveScreenBuffer(back); // atomic swap
```

## References
- <https://github.com/adi3120/Fazen2d>
