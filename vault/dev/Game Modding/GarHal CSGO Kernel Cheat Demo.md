<!-- generated-from-dump2 -->
# GarHal CSGO Kernel Cheat Demo

A project that demonstrates how to screw with CSGO from Kernel Space. (CSGO Kernel Cheat/Hack) All cleaned up, and with updated offsets.

```cpp
NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING reg) {
    drv->DriverUnload = Unload;
    return STATUS_SUCCESS;
}
```

## References
- <https://github.com/dretax/GarHal_CSGO>
