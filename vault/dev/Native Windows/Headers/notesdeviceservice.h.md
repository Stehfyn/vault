# notesdeviceservice.h

WinRT activation header for `Windows.Devices.Sms.Notes` / OneNote-related device-service contracts on Windows Phone-era / mobile-style endpoints. Defines `INoteDeviceService` (and the matching activation factory) used to issue OneNote-page-capture commands to a peripheral or sensor cluster that advertises a OneNote device service. Functionally dead on modern desktop Windows; you only see this header pulled in when building against very old phone SDKs or when investigating leftover surfaces inside `Windows.Devices.winmd`. Nothing in the modern Win32 / WinUI app stack uses it.

## References
- notesdeviceservice.h
