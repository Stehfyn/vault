# Virtual-Display-Driver - Virtual Monitor

`VirtualDrivers/Virtual-Display-Driver` is an indirect display driver that creates synthetic monitors on Windows 10/11 for capture, streaming, VR, and headless workflows. Its value is that it moves beyond a skeleton: it is packaged as a usable virtual display device rather than a one-file `DriverEntry` demonstration. The relevant design surface is IDDCX monitor creation, mode reporting, frame delivery, and installer/signing behavior.

Once the virtual monitor exists, user-mode code treats it like any other display target. Use DisplayConfig to place it in clone/extend layouts, DEVMODE only for old-style mode tweaks, and DDC/CI APIs only for physical panels; a virtual monitor generally will not have meaningful VCP brightness or input controls.

## References
- <https://github.com/VirtualDrivers/Virtual-Display-Driver> - maintained virtual monitor driver for Windows 10/11 style desktop sharing use cases.
