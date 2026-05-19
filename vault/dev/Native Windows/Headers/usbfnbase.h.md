# usbfnbase.h

USB Function-mode base definitions -- for code that runs on a device that *is* a USB peripheral rather than a host. Windows IoT Core / Windows Phone / certain HoloLens-class devices can act as USB devices to a host PC (file transfer to a phone, MTP, charging+ADB-style scenarios) and the function-side driver stack uses `UFX` (USB Function Extension). `usbfnbase.h` defines the function-side endpoint descriptors, transfer types, and IOCTL surface (`IOCTL_INTERNAL_USBFN_*`) consumed by class function drivers (MTP, RNDIS, generic). Wholly irrelevant on a desktop SKU acting only as a host. Cluster: `ufxclient.h` (UFX class driver API), `usbfn.h`, `usbioctl.h` (host-side counterpart).

## References
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/usbfnbase/>
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/developing-windows-drivers-for-usb-function-controllers>
