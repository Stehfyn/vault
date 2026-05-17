# MMCSS Research

Short description: Community research notes indicate the hidden MMCSS “Latency Sensitive” task value defaults to `TRUE` on Windows 10 and drives latency-sensitive hints under heavy CPU load. The registry path used for per-task settings is `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\MultiMedia\systemprofile\Tasks\<TaskName>`. Additional notes cover Clock Rate behavior and BackgroundPriority effects on base thread priority when Scheduling Category is LOW.

Optional usage snippet (tag a thread with MMCSS):
```c
DWORD taskIndex = 0;
HANDLE mmcssHandle = AvSetMmThreadCharacteristicsW(L"Audio", &taskIndex);
// ... work ...
if (mmcssHandle) {
    AvRevertMmThreadCharacteristics(mmcssHandle);
}
```

References:
- https://www.overclock.net/threads/research-on-multimedia-class-scheduler-service-mmcss.1774590/
