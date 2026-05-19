# wim-backup — WinPE WIM Capture Frontend

`wim-backup` is interesting as a WinPE application more than as a UI: it wraps DISM/WIMGAPI-style image capture in the constrained recovery environment where Explorer, MSI, UWP, and much of normal desktop infrastructure are absent. That makes it a practical reference for OEM recovery media and bare-metal backup flows.

The native-Windows lesson is environment selection. In WinPE, deployment work is file systems, volumes, WIM images, drivers, and a small Win32 surface. Installer technologies such as MSI/MSIX are mostly irrelevant there; the durable artifact is the image, not a product registration.

## Connections
- `SetupAPI.h` is adjacent when recovery media needs driver injection or device enumeration.
- `DLL Build Config` matters because WinPE apps often need explicit architecture and dependency control.

## References
- <https://github.com/cregx/wim-backup>
