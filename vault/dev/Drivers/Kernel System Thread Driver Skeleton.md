<!-- generated-from-dump2 -->
# Kernel System Thread Driver Skeleton

Tiny driver + user-mode loader pair showing how to spawn a `PsCreateSystemThread` from `DriverEntry` and signal it for graceful unload. Useful as a skeleton for polling tasks (periodic memory scans, hardware watchdogs) that must run at PASSIVE_LEVEL with a dedicated `ETHREAD`.

```cpp
HANDLE g_ThreadHandle = nullptr;
KEVENT g_Stop;

void WorkerThread(PVOID) {
    LARGE_INTEGER timeout; timeout.QuadPart = -10 * 1000 * 1000; // 1s
    while (KeWaitForSingleObject(&g_Stop, Executive, KernelMode, FALSE, &timeout) == STATUS_TIMEOUT) {
        DbgPrint("tick\n");
    }
    PsTerminateSystemThread(STATUS_SUCCESS);
}

NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING) {
    KeInitializeEvent(&g_Stop, NotificationEvent, FALSE);
    drv->DriverUnload = [](PDRIVER_OBJECT){ KeSetEvent(&g_Stop, 0, FALSE); ZwClose(g_ThreadHandle); };
    return PsCreateSystemThread(&g_ThreadHandle, GENERIC_ALL, nullptr, nullptr, nullptr, WorkerThread, nullptr);
}
```

## References
- <https://github.com/Spuckwaffel/Kernel-Thread-Driver>
