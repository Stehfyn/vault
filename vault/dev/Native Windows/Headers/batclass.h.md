# batclass.h

Battery class driver contract -- the `IOCTL_BATTERY_*` interface that `battc.sys` exposes and that `Power\Battery\<n>` device instances implement. From user-mode you open the battery device with the `GUID_DEVCLASS_BATTERY` interface (or `BATTERY_CLASS_DEVICE_INTERFACE_GUID`), issue `IOCTL_BATTERY_QUERY_TAG` to get the current tag (battery removal/insertion bumps it, so you re-query if the tag changes), then ask for typed information via `IOCTL_BATTERY_QUERY_INFORMATION` (`BatteryInformation`, `BatteryGranularityInformation`, `BatteryDeviceName`, `BatteryManufactureName`, ...) and live status via `IOCTL_BATTERY_QUERY_STATUS`. This is the underlying engine for `GetSystemPowerStatus` / `SYSTEM_BATTERY_STATE` and Settings -> Battery. Used by `powercfg`, `battery-historian`-style tools, and any laptop diagnostic that wants per-cell detail Windows doesn't otherwise expose.

## References
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/batclass/>
- <https://learn.microsoft.com/en-us/windows/win32/power/enumerating-battery-devices>
