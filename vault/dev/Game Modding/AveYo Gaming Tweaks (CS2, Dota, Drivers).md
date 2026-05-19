<!-- generated-from-dump2 -->
# AveYo Gaming Tweaks (CS2, Dota, Drivers)

Counter-Strike 2, Dota 2, Steam, Windows and drivers stuff

```cpp
NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING reg) {
    drv->DriverUnload = Unload;
    return STATUS_SUCCESS;
}
```

## References
- <https://github.com/AveYo/Gaming>
