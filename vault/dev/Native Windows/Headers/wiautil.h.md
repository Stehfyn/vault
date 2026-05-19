# wiautil.h

Utility helpers layered on top of the Windows Image Acquisition (WIA) 2.0 COM stack (`wia.h`, `wiadef.h`, `sti.h`). WIA itself dates to Windows Me/2000 and is the supported driver model for flatbed scanners, multifunction printers' scan side, still-image cameras, and video-frame grabbers that aren't WDM-streaming; for cameras you almost always use WIA Imaging or MTP today rather than WIA, but for scanners WIA is still the only first-party path other than vendor TWAIN drivers. `wiautil.h` is part of the SDK samples lineage -- it adds convenience wrappers around `IWiaDevMgr2::EnumDeviceInfo`, item-tree walking, and property-bag access.

## References
- <https://learn.microsoft.com/en-us/windows/win32/wia/-wia-startpage>
