<!-- generated-from-dump2 -->
# EasyRing0 — WDM Driver Skeleton

Skeleton WDM kernel driver with a usermode client that demonstrates the standard ring-0 primitives: IOCTL dispatch, `IoCreateDevice` + symbolic link, KM↔UM buffer transfer modes (`METHOD_BUFFERED` vs `METHOD_NEITHER`), and a handful of common operations (read/write process memory via `MmCopyVirtualMemory`, attach to process with `KeStackAttachProcess`). A clean starting point if you're learning kernel driver plumbing rather than the security/cheat side.

```cpp
NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING reg)
{
    UNICODE_STRING devName, linkName;
    RtlInitUnicodeString(&devName, L"\\Device\\EasyRing0");
    RtlInitUnicodeString(&linkName, L"\\DosDevices\\EasyRing0");

    PDEVICE_OBJECT devObj;
    NTSTATUS s = IoCreateDevice(drv, 0, &devName, FILE_DEVICE_UNKNOWN,
                                FILE_DEVICE_SECURE_OPEN, FALSE, &devObj);
    if (!NT_SUCCESS(s)) return s;

    IoCreateSymbolicLink(&linkName, &devName);
    drv->MajorFunction[IRP_MJ_CREATE]         = DispatchCreate;
    drv->MajorFunction[IRP_MJ_CLOSE]          = DispatchClose;
    drv->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DispatchIoctl;
    drv->DriverUnload                         = Unload;
    return STATUS_SUCCESS;
}
```

## References
- <https://github.com/mq1n/EasyRing0>
