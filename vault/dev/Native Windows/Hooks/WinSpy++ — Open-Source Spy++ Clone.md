# WinSpy++ - Open-Source Spy++ Clone

WinSpy++ is valuable because it shows what a serious window inspector actually has to do. Enumerating windows from the outside gives handles, titles, classes, rectangles, styles, and hierarchy, but it does not give message flow. To observe messages the tool uses USER32 hook machinery in the target thread, which is the same architectural reason Microsoft's Spy++ has always felt closer to a debugger than to a simple enumeration sample.

The finder-tool behavior is also instructive: hit-testing, child-window selection, visual highlighting, and cross-thread/process inspection all sit on ordinary USER32 APIs until message logging requires injected hook code. This makes WinSpy++ the clean, defensive counterexample to treating SetWindowsHookEx only as an injection trick.

## Source Shape

The non-invasive inspection half is plain USER32 enumeration. Message logging is the point where hooks enter.

```cpp
EnumWindows([](HWND hwnd, LPARAM) -> BOOL {
    wchar_t class_name[256];
    wchar_t title[256];
    RECT rc;
    DWORD pid = 0;

    GetClassNameW(hwnd, class_name, ARRAYSIZE(class_name));
    GetWindowTextW(hwnd, title, ARRAYSIZE(title));
    GetWindowRect(hwnd, &rc);
    DWORD tid = GetWindowThreadProcessId(hwnd, &pid);

    AddWindowNode(hwnd, tid, pid, class_name, title, rc);
    return TRUE;
}, 0);
```

## Source Code Reading

The best code to read is not the message logger first; it is the finder and hit-test machinery.

`src/WindowFromPointEx.c` starts with `WindowFromPoint(pt)`, then improves on it by walking around sibling/child ambiguity. `FindBestChild` chooses a search root from `GetParent(hwndFound)` unless the found window is top-level or `WS_POPUP`, then `EnumChildWindows` calls `FindBestChildProc`. The callback filters children with `PtInRect(GetWindowRect(child), screenPoint)` and picks the smallest containing rectangle. That explains why Spy++-style tools often select nested controls better than raw `WindowFromPoint`.

`src/FindTool.c` turns a static bitmap into a drag selector:

```cpp
MakeFinderTool:
    SetWindowLong(hwnd, GWL_STYLE, SS_NOTIFY | SS_BITMAP | ...)
    SendMessage(hwnd, STM_SETIMAGE, IMAGE_BITMAP, dragBitmap)
    SetWindowLongPtr(hwnd, GWLP_USERDATA, callback)
    oldstaticproc = SetWindowLongPtr(hwnd, GWLP_WNDPROC, StaticProc)
```

`StaticProc` handles `WM_LBUTTONDOWN`, calls `SetCapture`, installs a temporary `WH_KEYBOARD` hook, and begins highlighting. `WM_MOUSEMOVE` maps the point to screen coordinates, calls `WindowFromPointEx`, hides the old selection, notifies the parent, and shows the new selection. `WM_LBUTTONUP` and `WM_CANCELMODE` call `EndFindToolDrag`, which releases capture, restores the cursor, unhooks the keyboard hook, and restores the drag bitmap.

The visual selection path is deliberately old-school: `InvertWindow` gets a window DC with `GetWindowDC`, computes frame/client rectangles, and uses `InvertRect` on the target border. If transparent overlay creation fails, the finder falls back to border inversion. This is useful because it works without cooperating with the target process.

The falsifiable claims are straightforward:

- Raw `WindowFromPoint` can select a parent/group box when a smaller sibling control is under the cursor; `WindowFromPointEx` should return the smallest visible containing child.
- The finder should keep receiving mouse moves outside its original static control because it called `SetCapture`.
- Escape should cancel selection because the temporary hook posts `WM_CANCELMODE`; removing that hook should make Escape inert unless focus happens to be on the finder tool.

## Connections
- `SetWindowsHookEx` explains the hook contract behind message logging.
- `WND Internal Structure` and `Win32k Kernel Structures` explain the deeper state that a supported inspector can only infer indirectly.
- `System-Defined Messages` and `Message Queue Implementation` explain what the logger is watching.
- `../Input/getconkbl - Console Keyboard Layout Probe.md` uses the same HWND-to-thread/process route for console input ownership.

## References
- <https://github.com/strobejb/winspy>
