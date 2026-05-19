<!-- generated-from-dump2 -->
# Kernel Read Write IOCTL Driver

Minimal kernel driver exposing two IOCTLs (read / write) that operate on a target process's address space using `MmCopyVirtualMemory`. The canonical "first cheat driver" template: load the driver, open `\\.\DeviceName`, send a struct describing pid+address+length, get bytes back.

```cpp
struct RwRequest { ULONG pid; PVOID address; PVOID buffer; SIZE_T size; };

NTSTATUS DoRead(RwRequest* r) {
    PEPROCESS target;
    NTSTATUS s = PsLookupProcessByProcessId((HANDLE)(ULONG_PTR)r->pid, &target);
    if (!NT_SUCCESS(s)) return s;
    SIZE_T copied;
    s = MmCopyVirtualMemory(target, r->address, PsGetCurrentProcess(), r->buffer, r->size, UserMode, &copied);
    ObDereferenceObject(target);
    return s;
}
```

## References
- <https://github.com/beans42/kernel-read-write-using-ioctl>
