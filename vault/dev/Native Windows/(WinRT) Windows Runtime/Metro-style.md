# Metro-style App Activation

Packaged (Store/UWP) apps can be launched via `IApplicationActivationManager` using their AppUserModelID.

```cpp
#include <windows.h>
#include <shobjidl.h>

CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

IApplicationActivationManager* aam = nullptr;
CoCreateInstance(CLSID_ApplicationActivationManager, nullptr, CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&aam));

DWORD pid = 0;
if (aam) {
    aam->ActivateApplication(L"AppUserModelID", nullptr, AO_NONE, &pid);
    aam->Release();
}

CoUninitialize();
```

## References
- https://gist.github.com/fincs/2732608
