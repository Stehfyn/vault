# Atoms

Window class atoms are integer identifiers returned by `RegisterClass` / `RegisterClassEx`. You can pass the atom through `MAKEINTATOM` to `CreateWindowEx` instead of a class-name string, and `GetClassWord(hwnd, GCW_ATOM)` can recover a class atom from an existing HWND. In modern code this is mostly a performance and historical detail; class names are clearer, and class lookup is rarely the bottleneck.

Do not confuse window-class atoms with the global atom table. `GlobalAddAtom` creates session-visible string atoms used by old IPC conventions and shell protocols; it is unrelated to per-process window class registration except for sharing the same broad atom-table idea.

## Source Shape

The atom route is a class-registration shortcut, not a separate windowing model.

```cpp
WNDCLASSEXW wc = { sizeof(wc) };
wc.lpfnWndProc = WndProc;
wc.hInstance = instance;
wc.lpszClassName = L"MyControl";

ATOM cls = RegisterClassExW(&wc);
HWND hwnd = CreateWindowExW(0, MAKEINTATOM(cls), nullptr,
                            WS_CHILD | WS_VISIBLE,
                            0, 0, width, height,
                            parent, nullptr, instance, nullptr);
```

Use the string name unless you are specifically studying class lookup, legacy code, or atom-table behavior.

## References
- <https://devblogs.microsoft.com/oldnewthing/20041011-00/?p=37603> - Raymond Chen explains why atoms exist and why most code should not obsess over them.

## Connections
- `cbClsExtra and cbWndExtra.md` is the adjacent class-registration storage topic.
- `Custom Controls.md` is where registering your own class becomes a real control implementation.
- `Window Messaging.md` is the delivery layer once instances of that class exist.
