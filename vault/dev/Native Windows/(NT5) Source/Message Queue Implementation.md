# Message Queue Implementation (queue.c)

`queue.c` is where the polite `GetMessage` story becomes concrete. NTUSER tracks per-thread queue state, posted-message lists, wake masks, sent-message processing, input attachment, foreground activation, and the rules that decide whether a caller blocks or returns. The important correction is that Windows message delivery is not simply FIFO: sent messages, input, paint, timers, quit state, and wake conditions each have distinct precedence and side effects.

This file is the backend for many visible Win32 oddities: `SendMessage` reentrancy, modal loops during moves/resizes, hooks that require pumping, and GUI threads that deadlock when they wait without `MsgWaitForMultipleObjects`. Use it when a bug looks like "the message loop is stuck"; the cause is often queue ownership or a synchronous send path, not the loop body.

## Connections
- `SendMessage Path` covers the synchronous delivery side.
- `dtc` shows an architectural response to modal queue behavior.
- Hooks and WinSpy++ rely on the same thread queues to observe message traffic.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/queue.c#L5307
