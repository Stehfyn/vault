# WinRT is Fundamentally COM

WinRT activation uses COM-style factories and `IInspectable` interfaces. Use `RoGetActivationFactory` after `RoInitialize`.

```cpp
#include <windows.h>
#include <roapi.h>
#include <windows.foundation.h>
#pragma comment(lib, "runtimeobject.lib")

RoInitialize(RO_INIT_MULTITHREADED);

HSTRING classId = nullptr;
WindowsCreateString(L"Windows.Foundation.Uri",
                    static_cast<UINT32>(wcslen(L"Windows.Foundation.Uri")),
                    &classId);

IActivationFactory* factory = nullptr;
RoGetActivationFactory(classId, IID_PPV_ARGS(&factory));

if (factory) {
    factory->Release();
}

WindowsDeleteString(classId);
RoUninitialize();
```

## References
- https://stackoverflow.com/questions/7436144/using-winrt-from-c/7437006#7437006
