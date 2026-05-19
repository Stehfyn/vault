<!-- generated-from-dump2 -->
# Official Windows Driver Samples (WDK)

Microsoft's official corpus of Windows driver samples built against the WDK in Visual Studio. Covers KMDF/UMDF, WDM, NDIS, storage, USB, audio, print, and HID stacks. The repo is the canonical starting point for skeletons (driver entry, dispatch routines, INF authoring) before reaching for third-party scaffolding.

```cpp
// Minimal KMDF driver entry from the canonical sample shape.
#include <ntddk.h>
#include <wdf.h>

EVT_WDF_DRIVER_DEVICE_ADD EvtDeviceAdd;

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    WDF_DRIVER_CONFIG config;
    WDF_DRIVER_CONFIG_INIT(&config, EvtDeviceAdd);
    return WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);
}
```

## References
- <https://github.com/microsoft/Windows-driver-samples>
