# ntddbeep.h

The IOCTL contract for `beep.sys`, the PC-speaker driver that has been part of NT since 3.1. Defines `IOCTL_BEEP_SET` and the `BEEP_SET_PARAMETERS` struct (`Frequency`, `Duration`). The user-mode `Beep(freq, ms)` from `kernel32.dll` is a thin wrapper that opens `\Device\Beep`, fills in a `BEEP_SET_PARAMETERS`, and issues this IOCTL. The famous mid-2010s twist: `beep.sys` originally drove the actual PC speaker via the i8253 PIT -- once motherboards stopped wiring speakers to the PIT, Microsoft rewrote it to synthesize the tone through the regular audio device. So `Beep()` now goes through your sound card and respects volume / DND, but the IOCTL surface is identical. Legacy, but still present on every Windows install, and still useful when you specifically want a programmatic beep that bypasses the application audio mixer (with the older versions of the driver).

## References
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddbeep/>
- <https://learn.microsoft.com/en-us/windows/win32/api/utilapiset/nf-utilapiset-beep>
