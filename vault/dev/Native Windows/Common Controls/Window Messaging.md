# Window Messaging

Win32 messages are delivered to the thread that owns the target window. `SendMessage` is synchronous and can reenter the receiver; `PostMessage` is asynchronous and only queues values that remain valid after the call returns. `WM_COPYDATA` is the small structured exception: it is sent synchronously with a `COPYDATASTRUCT`, and the receiver must copy the payload before returning.

The queue model drives UI architecture. `GetMessage` blocks, `PeekMessage` drains without blocking for render loops, and any wait on a GUI thread must account for messages or the app will deadlock against callers sending synchronous messages. Raymond Chen's posts are valuable here because many message bugs are not API trivia; they are contract misunderstandings about ownership, reentrancy, and lifetime.

## Queue and Reentrancy Shape

The message-queue reference contributes the pump contract. On a GUI thread, long waits need a message-aware wait, and posted payloads must remain valid after `PostMessage` returns.

```cpp
MSG msg;
while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
}
```

`SendMessage` crosses into the receiver synchronously and can reenter the sender if both windows cooperate through nested message loops. Treat it as a call into foreign code, not as a cheap queue append.

```cpp
PostMessageW(hwnd, WM_APP + 1, static_cast<WPARAM>(id), 0);
LRESULT result = SendMessageW(hwnd, WM_GETTEXTLENGTH, 0, 0);
```

## WM_COPYDATA Boundary

The `COPYDATASTRUCT` links contribute the structured synchronous payload rule: sender storage must remain valid during the call, and the receiver must copy anything it wants to keep.

```cpp
std::wstring payload = L"command";
COPYDATASTRUCT cds = {};
cds.dwData = 1;
cds.cbData = static_cast<DWORD>((payload.size() + 1) * sizeof(wchar_t));
cds.lpData = payload.data();

SendMessageW(target, WM_COPYDATA, reinterpret_cast<WPARAM>(hwnd),
             reinterpret_cast<LPARAM>(&cds));
```

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/Winuser/ns-winuser-copydatastruct> - `COPYDATASTRUCT` layout.
- <https://learn.microsoft.com/en-us/windows/win32/dataxchg/wm-copydata> - synchronous cross-window data message contract.
- <https://learn.microsoft.com/en-us/windows/win32/winmsg/messages-and-message-queues> - queue ownership and pump behavior.
- <https://devblogs.microsoft.com/oldnewthing/20110516-00/?p=10663> - Old New Thing discussion of posted-message timing.

## Connections

- `Message Cracker Wizard (windowsx.h).md` helps decode messages after they arrive.
- `Modify Context Menu.md` and `Arbitrary Window Activate.md` both rely on precise message/thread behavior.
