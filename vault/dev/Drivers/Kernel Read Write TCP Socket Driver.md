<!-- generated-from-dump2 -->
# Kernel Read Write TCP Socket Driver

Kernel driver that opens a TCP socket via `WskRegister`/`WskCaptureProviderNPI` and serves remote read/write requests against arbitrary process memory using `MmCopyVirtualMemory`. Designed for game-hacking external cheats that don't want a user-mode helper attaching to the target.

```cpp
// Read N bytes from a target process VA into the local kernel buffer.
NTSTATUS RemoteRead(HANDLE pid, PVOID remoteVa, PVOID localBuf, SIZE_T n) {
    PEPROCESS proc; NTSTATUS s = PsLookupProcessByProcessId(pid, &proc);
    if (!NT_SUCCESS(s)) return s;
    SIZE_T got = 0;
    s = MmCopyVirtualMemory(proc, remoteVa, PsGetCurrentProcess(), localBuf, n, KernelMode, &got);
    ObDereferenceObject(proc);
    return s;
}
```

## References
- <https://github.com/adrianyy/rw_socket_driver>
