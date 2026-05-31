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

## Discussion Claims to Test

The Raymond Chen link is useful because it turns `PostMessage` from a convenience API into a lifetime contract. A posted message copies `HWND`, `UINT`, `WPARAM`, and `LPARAM` values into a queue; it does not deep-copy whatever your `LPARAM` points at. The falsifiable rule is simple: post an `LPARAM` pointer to stack memory, return, then let the receiver read it later. If the receiver "works," it is luck and timing, not a contract.

Probe:

```cpp
struct Payload { DWORD magic; wchar_t text[32]; };

void BadPost(HWND target) {
    Payload p = { 0x12345678, L"stack" };
    PostMessageW(target, WM_APP + 1, 0, (LPARAM)&p);
} // p is dead here

case WM_APP + 1:
    // This intentionally tests a bug. The pointer lifetime is invalid.
    Inspect((Payload*)lParam);
    return 0;
```

Now replace `PostMessageW` with `SendMessageW`; the pointer remains valid for the duration of the call, but the sender is synchronously executing receiver code and can be reentered through nested pumps. Replace both with `WM_COPYDATA` when you need a synchronous, structured cross-window payload and make the receiver copy the bytes before returning.

Message tracing should show the practical difference:

- Spy++ sees a posted app message arrive later when the target thread pumps.
- A debugger breakpoint inside the receiver during `SendMessage` runs on the sender's call stack.
- `WM_COPYDATA` only works with `SendMessage`; posting it is invalid because the payload lifetime cannot be guaranteed.

## Verification Route

Claim: thread messages and window messages fail differently in modal loops. The Old New Thing modal-loop discussion is a warning that `PostThreadMessage` to a GUI thread is not interchangeable with `PostMessage(hwnd, ...)` because `DispatchMessage` has no window procedure to call for a thread message.

Why it matters for new code: background-to-UI signaling should target a real message-only or normal HWND owned by the UI thread. Posting to the thread itself looks simpler until menus, move/size loops, dialog boxes, or accelerators introduce nested dispatch behavior.

How to verify:

- Create a UI thread with both a hidden message-only window and a thread-message handler in the outer pump.
- Start a move/size drag or modal dialog, then post both `PostThreadMessage(threadId, WM_APP+1, ...)` and `PostMessage(hwndMessageOnly, WM_APP+2, ...)`.
- Trace with Spy++ or debugger logging. The window-targeted message reaches `WndProc`; the thread message can be consumed by a loop that only calls `TranslateMessage` / `DispatchMessage`.

Minimal code/pseudocode:

```cpp
PostThreadMessageW(ui_tid, WM_APP + 1, 0, 0);   // fragile on GUI threads
PostMessageW(hwnd_signal, WM_APP + 2, 0, 0);    // dispatch has a WndProc target

while (GetMessageW(&msg, nullptr, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessageW(&msg); // thread message has no hwnd dispatch target
}
```

Interpretation: if the signal must survive modal UI behavior, create an HWND signal target. Use thread messages for worker-style loops that deliberately inspect `msg.hwnd == nullptr`; do not use them as a casual GUI-thread mailbox.

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/Winuser/ns-winuser-copydatastruct> - `COPYDATASTRUCT` layout.
- <https://learn.microsoft.com/en-us/windows/win32/dataxchg/wm-copydata> - synchronous cross-window data message contract.
- <https://learn.microsoft.com/en-us/windows/win32/winmsg/messages-and-message-queues> - queue ownership and pump behavior.
- <https://devblogs.microsoft.com/oldnewthing/20110516-00/?p=10663> - Old New Thing discussion of posted-message timing.
- <https://devblogs.microsoft.com/oldnewthing/20050426-18/?p=35783> - Old New Thing discussion of thread messages lost through modal loops.
- <https://devblogs.microsoft.com/oldnewthing/20110916-00/?p=9623> - why `WM_COPYDATA` is a sent-message lifetime contract, not a posted-message contract.

## Connections

- `Message Cracker Wizard (windowsx.h).md` helps decode messages after they arrive.
- `Modify Context Menu.md` and `Arbitrary Window Activate.md` both rely on precise message/thread behavior.
