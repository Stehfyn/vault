<!-- generated-from-dump2 -->
# Remote Thread Creation Detection Driver

Pavel Yosifovich's sample kernel driver demonstrating `PsSetCreateThreadNotifyRoutine` to detect cross-process thread injection (a classic CreateRemoteThread / NtCreateThreadEx anti-cheat / EDR signal). Logs source PID, target PID, and start address so a user-mode service can flag CRSS/lsass-style abuses.

```cpp
void OnThreadNotify(HANDLE ProcessId, HANDLE ThreadId, BOOLEAN Create) {
    if (!Create) return;
    HANDLE currentPid = PsGetCurrentProcessId();
    if (currentPid != ProcessId) {
        DbgPrint("Remote thread: src=%llu -> target=%llu tid=%llu\n",
            (ULONG64)currentPid, (ULONG64)ProcessId, (ULONG64)ThreadId);
    }
}

NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING) {
    drv->DriverUnload = [](PDRIVER_OBJECT){ PsRemoveCreateThreadNotifyRoutine(OnThreadNotify); };
    return PsSetCreateThreadNotifyRoutine(OnThreadNotify);
}
```

## References
- <https://github.com/zodiacon/RemoteThreadDetection>
