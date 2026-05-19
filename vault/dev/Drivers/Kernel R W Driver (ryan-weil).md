<!-- generated-from-dump2 -->
# Kernel R W Driver (ryan-weil)

A kernel driver for reading and writing memory

```cpp
NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING reg) {
    drv->DriverUnload = Unload;
    return STATUS_SUCCESS;
}
```

## References
- <https://github.com/ryan-weil/ReadWriteDriver>
