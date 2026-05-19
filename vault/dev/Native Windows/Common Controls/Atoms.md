# Atoms

Window class atoms are integer identifiers returned by `RegisterClass` / `RegisterClassEx`. You can pass the atom through `MAKEINTATOM` to `CreateWindowEx` instead of a class-name string, and `GetClassWord(hwnd, GCW_ATOM)` can recover a class atom from an existing HWND. In modern code this is mostly a performance and historical detail; class names are clearer, and class lookup is rarely the bottleneck.

Do not confuse window-class atoms with the global atom table. `GlobalAddAtom` creates session-visible string atoms used by old IPC conventions and shell protocols; it is unrelated to per-process window class registration except for sharing the same broad atom-table idea.

## References
- <https://devblogs.microsoft.com/oldnewthing/20041011-00/?p=37603> - Raymond Chen explains why atoms exist and why most code should not obsess over them.

## Connections
- `cbClsExtra and cbWndExtra.md` is the adjacent class-registration storage topic.
