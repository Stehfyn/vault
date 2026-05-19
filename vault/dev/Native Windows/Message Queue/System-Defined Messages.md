# System-Defined Messages

System-defined messages are not a flat bag of constants; they encode several different delivery contracts. Posted messages such as paint/timer/input notifications wait in the thread queue, sent messages may execute synchronously inside the receiver's window procedure, and some messages are synthesized by USER32 during translation or modal tracking. That distinction is why `SendMessage`, `PostMessage`, `PeekMessage`, and `DispatchMessage` have different deadlock and reentrancy behavior.

## Private Message Ranges

The Microsoft message-queue documentation contributes the namespace rule. `WM_USER` belongs to a window class/control contract, `WM_APP` is safer for application-private messages, and registered messages solve cross-process naming.

```cpp
constexpr UINT WM_APP_REFRESH = WM_APP + 1;

UINT wm_taskbar_created = RegisterWindowMessageW(L"TaskbarCreated");
PostMessageW(hwnd, WM_APP_REFRESH, 0, 0);
```

## Dispatch and Historical IPC

The old DDE references are useful because they stress-test the same message model: synchronous conversation state, broadcasts, and data handles riding through window messages.

```cpp
MSG msg;
while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
}
```

## Connections

- `dtc` shows how modal message loops affect application architecture.
- `NT User Message Definitions` shows how public message ranges coexist with NTUSER private traffic.
- `SetWindowsHookEx` and WinSpy++ depend on the same dispatch path to observe or intercept messages.

## References

- <https://learn.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues#system-defined-messages>
- <https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms711436(v=vs.85)>
- <https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms705252(v=vs.85)>
