# Virtual-Display-Driver - Virtual Monitor

`VirtualDrivers/Virtual-Display-Driver` is an indirect display driver that creates synthetic monitors on Windows 10/11 for capture, streaming, VR, and headless workflows. Its value is that it moves beyond a skeleton: it is packaged as a usable virtual display device rather than a one-file `DriverEntry` demonstration. The relevant design surface is IDDCX monitor creation, mode reporting, frame delivery, and installer/signing behavior.

Once the virtual monitor exists, user-mode code treats it like any other display target. Use DisplayConfig to place it in clone/extend layouts, DEVMODE only for old-style mode tweaks, and DDC/CI APIs only for physical panels; a virtual monitor generally will not have meaningful VCP brightness or input controls.

## Source Code Reading

`VirtualDrivers/Virtual-Display-Driver` follows the same IDDCX shape as the sample but is packaged as a practical virtual display. Read `Virtual Display Driver (HDR)/MttVDD/Driver.cpp`, `Driver.h`, and `MttVDD.inf`; the source surface to inspect is adapter/monitor declaration, EDID/mode data, swap-chain assignment, and HDR-specific metadata. Treat the bundled WDF headers as build dependencies, not as the design center.

Use the same probe categories as the IDD sample:

```cpp
AdapterInit: log MaxMonitorsSupported, endpoint strings, gamma/HDR flags.
MonitorArrival: log EDID bytes, target modes, preferred mode.
AssignSwapChain: log adapter LUID, DXGI format, buffer size, frame event.
FrameLoop: acquire surface -> bounded copy/encode -> finish frame.
Topology: QueryDisplayConfig before/after install, enable, mode change.
```

The actionable split: driver code creates a target and consumes frames; user-mode DisplayConfig code places that target in the desktop; capture/streaming code decides what to do with the frames. Mixing those responsibilities makes debugging impossible because a black remote frame, a missing virtual target, and a wrong desktop topology are three different failures.

## References
- <https://github.com/VirtualDrivers/Virtual-Display-Driver> - maintained virtual monitor driver for Windows 10/11 style desktop sharing use cases.
