# EventWrite

## References
- https://learn.microsoft.com/en-us/windows/win32/api/evntprov/nf-evntprov-eventwrite

## EventWrite snippet
```cpp
#include <windows.h>
#include <evntprov.h>

const GUID ProviderGuid =
  { 0x12345678, 0x9abc, 0x4def, { 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11 } };

REGHANDLE regHandle = 0;
EventRegister(&ProviderGuid, nullptr, nullptr, &regHandle);

EVENT_DESCRIPTOR desc = {};
EventDescriptorCreate(&desc, 1, 0, TRACE_LEVEL_INFORMATION, 0, 0, 0, 0);

const wchar_t* message = L"hello";
EVENT_DATA_DESCRIPTOR data = {};
EventDataDescCreate(&data, (PVOID)message, (ULONG)((wcslen(message) + 1) * sizeof(wchar_t)));

EventWrite(regHandle, &desc, 1, &data);
EventUnregister(regHandle);
```
