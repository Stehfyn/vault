# Arbitrary Window Activate

Forcing another process's window to the foreground is deliberately constrained by USER32's foreground-lock rules. The linked `EConHostProc` code works around that by getting execution into the target GUI thread with `SetWindowsHookEx`, then calling activation APIs from a context USER is more willing to trust. That is qualitatively different from spamming `SetForegroundWindow` from your own process.

The practical sequence is restore if iconic, bring the window to top, activate it, and invalidate/redraw if the frame was stale after restore. Treat this as a last-resort UI automation technique: a cooperative app should expose IPC, and a normal launcher should use documented foreground permission flows instead.

## References
- <https://github.com/jredfox/EConHostProc/blob/e0b34e8fe9a05028201904bb5ab533a3e2b08b59/src/DLLMain.cpp#L44> - demonstrates the hook-injection activation path.

## Connections
- `Window Messaging.md` covers cross-window message delivery constraints.
- `Borderless Window.md` and `Window Sizing.md` are usually the next problems once activation works but frame state is wrong.
