# lamp.h

Kernel-mode driver-side contract for the HID LampArray usage page (`HID_USAGE_PAGE_LAMP_ARRAY = 0x59`), the standard introduced in Windows 10 21H2 that finally let RGB keyboards, mice, fan controllers, and case lighting be driven by Windows without a vendor SDK. From user-mode you almost never touch `lamp.h` directly -- you go through `Windows.Devices.Lights.LampArray` (WinRT) which talks HID to any device that exposes a Lamp Array top-level collection. `lamp.h` itself defines the IOCTL surface (`IOCTL_HID_LAMP_ARRAY_*`), the `LAMP_ATTRIBUTES` / `LAMP_ARRAY_ATTRIBUTES` report structures, and the report IDs a driver must emit to satisfy the HID usage table. Neighbouring headers: `hidsdi.h` (HID API), `hidpi.h` (HID parser), `hidusage.h` (usage page constants).

## References
- <https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/lamparray>
- <https://learn.microsoft.com/en-us/uwp/api/windows.devices.lights.lamparray>
