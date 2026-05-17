# Power State APIs

Sources:
- https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setsystempowerstate
- https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setthreadexecutionstate

```cpp
// Prevent sleep/display idle while recording.
SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);

// Clear the execution state when done.
SetThreadExecutionState(ES_CONTINUOUS);

// Legacy suspend/hibernate (fSuspend=TRUE suspends; FALSE hibernates).
SetSystemPowerState(TRUE, FALSE);
```
