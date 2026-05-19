<!-- generated-from-dump2 -->
# Kernel R W Driver (Zer0Mem0ry)

Simple code to manipulate the memory of a usermode process from kernel.

```cpp
NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING reg) {
    drv->DriverUnload = Unload;
    return STATUS_SUCCESS;
}
```

## References
- <https://github.com/Zer0Mem0ry/KernelReadWriteMemory>
