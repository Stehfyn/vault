# Power State APIs

`SetThreadExecutionState` is the pragmatic API for telling Windows that a thread is doing work that should delay sleep or display idle. It is a cooperative hint, commonly used by media playback, recording, installation, and long-running transfer code; the legacy `SetSystemPowerState` path is much heavier because it attempts to drive suspend/hibernate directly.

The nuance is lifetime and cleanup. Execution-state requests are process/thread-scoped policy hints that should be paired with a clear reset when work ends, otherwise a utility can silently ruin power behavior. This belongs near `MMCSS Research` and low-latency audio because media applications often coordinate scheduler class, timer behavior, and sleep inhibition together.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setthreadexecutionstate>
- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setsystempowerstate>
