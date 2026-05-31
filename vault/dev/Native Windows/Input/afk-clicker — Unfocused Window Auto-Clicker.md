# afk-clicker — Unfocused Window Auto-Clicker

Auto-clicker that sends mouse/keyboard input into a *specific* unfocused window — that "unfocused" part is the technically interesting bit. `SendInput` always goes to the foreground; you have to use `PostMessage(WM_KEYDOWN/WM_LBUTTONDOWN)` directly against the target HWND (which works for some apps that read messages from their queue) or, for games that use raw input / DirectInput, you need to interpose at a lower level via a DLL injection. This project demonstrates the simpler `PostMessage` route.

## Source Shape

The project belongs in the message-simulation branch, not the physical-input branch. The target must be an HWND that trusts queued messages.

```cpp
LPARAM point = MAKELPARAM(x_client, y_client);
PostMessageW(target, WM_MOUSEMOVE, 0, point);
PostMessageW(target, WM_LBUTTONDOWN, MK_LBUTTON, point);
PostMessageW(target, WM_LBUTTONUP, 0, point);

PostMessageW(target, WM_KEYDOWN, VK_SPACE, 0);
PostMessageW(target, WM_KEYUP, VK_SPACE, 0);
```

That will not satisfy code reading Raw Input, DirectInput, XInput, or anti-synthetic input checks.

## Source Code Reading

The Windows implementation is `windows/Main.py`, using pywin32 wrappers over USER32. It teaches the exact difference between locating an HWND and delivering a physical input event.

`Afk_Clicker.get_hwnds_by_pid` calls `win32gui.EnumWindows`, filters with `IsWindowVisible` and `IsWindowEnabled`, then uses `win32process.GetWindowThreadProcessId(hwnd)` to compare the top-level HWND's process ID. `get_hwnds_by_name` uses `FindWindow` by title or class. `get_child_hwnd` takes only the first child with `GetWindow(hwnd, GW_CHILD)`, which is a major limitation: many real apps have nested controls, owner-drawn surfaces, or multiple children.

Mouse delivery is synchronous message delivery to the chosen wrapper HWND:

```python
lParam = y << 15 | x
pycwnd.SendMessage(WM_LBUTTONDOWN, MK_LBUTTON, lParam)
pycwnd.SendMessage(WM_LBUTTONUP, 0, lParam)
pycwnd.UpdateWindow()
```

That `lParam` construction is a bug-shaped detail. Win32 mouse messages pack signed 16-bit client coordinates with `MAKELPARAM(x, y)`, conceptually `(y << 16) | (x & 0xffff)`. The source uses `y << 15 | x`, so the note should not present it as a canonical packing expression. A falsifiable probe is to send `(x=1, y=1)` and `(x=1, y=2)` to a logging test window and compare `GET_X_LPARAM` / `GET_Y_LPARAM` output.

Keyboard delivery is even narrower:

```python
win32api.PostMessage(child_hwnd, WM_CHAR, keyboard_key, 0)
```

That bypasses keydown/up state, scan codes, accelerator translation, Raw Input, DirectInput, and foreground focus. It works only for targets that accept posted character messages as authoritative input. The quickest confirmation probe is a test `WndProc` that logs `WM_CHAR`, `WM_KEYDOWN`, `WM_INPUT`, and focus state; `afk-clicker` should produce `WM_CHAR` without a physical-device `WM_INPUT` trail.

## References
- <https://github.com/eHonnef/afk-clicker>

## Connections
- `Mouse Input.md` explains the HWND message contract this relies on.
- `../Common Controls/Window Messaging.md` covers why posted parameters must remain valid after return.
- `../Hooks/MinHook - Minimal Hooking Library.md` and `../Hooks/UniversalHookX - Universal Graphical Hook.md` are the lower-level route when the target bypasses queued window messages.
