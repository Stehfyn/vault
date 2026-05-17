Window class atoms are integer tokens returned by `RegisterClass`/`RegisterClassEx` from USER32's internal atom table. They can be passed via `MAKEINTATOM` to `CreateWindow` instead of a class name string, and retrieved from a window with `GetClassWord(hwnd, GCW_ATOM)`. In practice they're largely an anachronism—`GetClassName` is more practical for comparisons. The global atom table (`GlobalAddAtom`) is shared across all processes in the session.

```cpp
#include <windows.h>

// RegisterClass returns an ATOM identifying the class
WNDCLASS wc = {};
wc.lpfnWndProc   = MyWndProc;
wc.hInstance     = hInst;
wc.lpszClassName = TEXT("MyWindowClass");
ATOM atom = RegisterClass(&wc);

// Use the atom directly instead of a string class name
HWND hwnd = CreateWindow(
    MAKEINTATOM(atom),       // avoids string lookup in USER32
    TEXT("Title"),
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
    NULL, NULL, hInst, NULL);

// Retrieve the atom from an existing window
ATOM wndAtom = (ATOM)GetClassWord(hwnd, GCW_ATOM);

// Global atom table — shared across all processes in the session
ATOM g = GlobalAddAtom(TEXT("MySharedAtom"));
ATOM f = GlobalFindAtom(TEXT("MySharedAtom"));  // find without adding
GlobalDeleteAtom(g);
```

## References
- https://devblogs.microsoft.com/oldnewthing/20041011-00/?p=37603
