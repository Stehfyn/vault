# poclass.h

Power-management class definitions exposed by `poclass.sys` / the WDK power class driver: the device-interface GUIDs that other components subscribe to (`GUID_DEVICE_BATTERY`, `GUID_DEVICE_LID`, `GUID_DEVICE_THERMAL_ZONE`, `GUID_DEVICE_PROCESSOR`, `GUID_DEVICE_MEMORY`, `GUID_DEVICE_SYS_BUTTON`), plus structures like `SYS_BUTTON_EVENT`, `LID_SWITCH_STATE`, `THERMAL_INFORMATION`. Combine with `RegisterDeviceNotificationW` (passing one of these GUIDs in a `DEV_BROADCAST_DEVICEINTERFACE`) and you get `WM_DEVICECHANGE` events when the lid opens / closes, when a sysbutton (power, sleep, hotkey) fires, when a thermal zone crosses a trip point, when a battery is hot-swapped, etc. Used by `powercfg` and almost every laptop OEM utility ever shipped. Pair with `batclass.h` (battery specifically) and `power.h` (power-state notifications).

## References
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/poclass/>
