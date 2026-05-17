# Task Manager Source

Windows XP SP1 Task Manager source from the NT5 source tree (`shell/applets/taskmgr`). Illustrates how the classic Task Manager enumerates running processes using the native `NtQuerySystemInformation` API with `SystemProcessInformation`.

```c
// From NT5 taskmgr source: process list refresh via NtQuerySystemInformation
NTSTATUS status;
ULONG returnLen = 0;
status = NtQuerySystemInformation(SystemProcessInformation, NULL, 0, &returnLen);
// allocate returnLen bytes, then:
PSYSTEM_PROCESS_INFORMATION pInfo = (PSYSTEM_PROCESS_INFORMATION)buf;
while (TRUE) {
    // pInfo->ImageName.Buffer = process name
    // pInfo->UniqueProcessId = PID
    if (pInfo->NextEntryOffset == 0) break;
    pInfo = (PSYSTEM_PROCESS_INFORMATION)((BYTE*)pInfo + pInfo->NextEntryOffset);
}
```

## References

- https://github.com/tongzx/nt5src/tree/master/Source/XPSP1/NT/shell/applets/taskmgr
