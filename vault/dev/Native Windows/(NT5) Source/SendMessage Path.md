# SendMessage Path (sendmsg.c)

`sendmsg.c` is the source-level antidote to the beginner model that all messages wait in a queue. `SendMessage` is synchronous: same-thread sends can dispatch directly, cross-thread sends block the caller while the receiver processes the request, and the system has to manage reentrancy, timeouts, callback messages, and wake masks around that blocking relationship.

This matters because many GUI deadlocks are self-inflicted. A worker thread sends to a UI thread that is waiting on the worker; a hook runs inside a send path and calls back into code that was not expecting reentrancy; a modal loop dispatches messages while a function higher on the stack assumes state is stable. The NT5 implementation shows why defensive GUI code treats `SendMessage` as a call across a reentrant boundary, not just as "post but wait."

## Connections
- `Message Queue Implementation` covers the queued side.
- `Injected DLL Unload`, SetWindowsHookEx, and WinSpy++ all depend on target threads pumping and dispatching correctly.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/sendmsg.c
