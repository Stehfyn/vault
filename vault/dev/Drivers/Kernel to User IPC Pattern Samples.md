<!-- generated-from-dump2 -->
# Kernel to User IPC Pattern Samples

Reference collection of kernel-mode to user-mode IPC patterns: IOCTL via `DeviceIoControl`, shared memory via `ZwMapViewOfSection`, inverted call / pending IRP, named events, and async notifications. Each method ships as a minimal driver + client pair for side-by-side comparison.

```cpp
// IOCTL handler with METHOD_BUFFERED.
NTSTATUS DispatchIoctl(PDEVICE_OBJECT, PIRP irp) {
    PIO_STACK_LOCATION sp = IoGetCurrentIrpStackLocation(irp);
    if (sp->Parameters.DeviceIoControl.IoControlCode == IOCTL_ECHO) {
        ULONG len = sp->Parameters.DeviceIoControl.InputBufferLength;
        RtlCopyMemory(irp->AssociatedIrp.SystemBuffer, irp->AssociatedIrp.SystemBuffer, len);
        irp->IoStatus.Information = len;
    }
    irp->IoStatus.Status = STATUS_SUCCESS;
    IoCompleteRequest(irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}
```

## References
- <https://github.com/adspro15/km-um-communication>
