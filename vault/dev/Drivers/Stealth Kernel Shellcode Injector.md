<!-- generated-from-dump2 -->
# Stealth Kernel Shellcode Injector

Kernel-mode shellcode injector designed to evade module-list and thread-creation based detection. Avoids the giveaways of mainstream user-mode injection: doesn't `CreateRemoteThread`, doesn't `LoadLibraryA`, doesn't appear in `PEB->Ldr` of the target. The technique walks the target process's threads from a kernel driver, picks one in a wait state, swaps its `Rip` (or the trap-frame return address) to an attacker-allocated RWX page inside the target — so the shellcode just executes when the thread wakes, without the target gaining a new thread or module. Pure educational artifact for understanding which kernel objects user-mode AV looks at.

```cpp
// Conceptual kernel-side flow (real impl walks ETHREAD lists):
//   1. ObReferenceObjectByName / PsLookupProcessByProcessId  -> EPROCESS
//   2. KeStackAttachProcess(target)                          -> we're "in" it
//   3. ZwAllocateVirtualMemory(.., PAGE_EXECUTE_READWRITE)   -> shellcode page
//   4. memcpy shellcode in user-space VA
//   5. Find a sleeping thread; suspend it
//   6. PsGetContextThread / KeSetContextThread -> patch Rip to shellcode
//   7. Resume thread; KeUnstackDetachProcess
//
NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING reg) {
    drv->DriverUnload = Unload;
    // IoCreateDevice + IoCreateSymbolicLink so user-mode can IOCTL us.
    return STATUS_SUCCESS;
}
```

## References
- <https://github.com/ccdescipline/CInject>
