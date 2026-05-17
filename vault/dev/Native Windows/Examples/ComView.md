Open-source COM object viewer and inspector for Windows, similar to the classic OleView tool. Enumerates registered COM servers from the registry, displays their CLSIDs, ProgIDs, threading models, and interface lists. Useful for auditing COM exposure or exploring unfamiliar COM APIs. The core pattern is `CoCreateInstance` followed by `IUnknown::QueryInterface` to probe supported interfaces.

```cpp
#include <objbase.h>
#pragma comment(lib, "ole32.lib")

CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

// Instantiate a COM object by CLSID
IUnknown* pUnk = nullptr;
HRESULT hr = CoCreateInstance(CLSID_MyObject, nullptr,
                              CLSCTX_INPROC_SERVER,
                              IID_IUnknown, (void**)&pUnk);
if (SUCCEEDED(hr)) {
    // Probe for a specific interface
    IMyInterface* pMy = nullptr;
    hr = pUnk->QueryInterface(IID_IMyInterface, (void**)&pMy);
    if (SUCCEEDED(hr)) {
        pMy->DoSomething();
        pMy->Release();
    }
    pUnk->Release();
}

CoUninitialize();
```

## References

- <https://github.com/Baron-von-Riedesel/ComView>
