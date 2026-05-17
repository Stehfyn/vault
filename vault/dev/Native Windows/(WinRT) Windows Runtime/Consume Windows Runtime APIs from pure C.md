# Consume Windows Runtime APIs from Pure C

Pure C callers can use the ABI interfaces directly with `RoGetActivationFactory` and vtable calls.

```c
#include <windows.h>
#include <roapi.h>
#include <inspectable.h>
#pragma comment(lib, "runtimeobject.lib")

HSTRING classId = NULL;
WindowsCreateString(L"Windows.Foundation.Uri",
                    (UINT32)wcslen(L"Windows.Foundation.Uri"),
                    &classId);

IActivationFactory* factory = NULL;
RoGetActivationFactory(classId, &IID_IActivationFactory, (void**)&factory);

IInspectable* obj = NULL;
if (factory) {
    factory->lpVtbl->ActivateInstance(factory, &obj);
}

if (obj) obj->lpVtbl->Release(obj);
if (factory) factory->lpVtbl->Release(factory);
WindowsDeleteString(classId);
```

## References
- https://stackoverflow.com/questions/65387849/consume-windows-runtime-apis-from-pure-c
- https://stackoverflow.com/questions/7436144/using-winrt-from-c
