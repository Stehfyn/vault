# pwm.h

PWM (Pulse-Width Modulation) IOCTL contract between user-mode and `pwm.sys`, the Windows 10 IoT Core / Windows on ARM PWM class driver. Defines `IOCTL_PWM_CONTROLLER_GET_INFO`, `IOCTL_PWM_PIN_SET_ACTIVE_DUTY_CYCLE`, `IOCTL_PWM_PIN_START`, the `PWM_CONTROLLER_INFO` / `PWM_PIN_SET_*_INPUT` structures, and the `{60824B4C-...}` device interface GUID. The user-mode entry point is plain `DeviceIoControl` on `\\.\PWM<N>` -- no COM, no WinRT -- though IoT C++/WinRT apps usually go through `Windows.Devices.Pwm` which wraps these IOCTLs. Relevant only on boards with onboard PWM controllers exposed by the ACPI / DT firmware (Raspberry Pi via the Windows IoT BSP, MinnowBoard, etc.).

## References
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/pwm/>
