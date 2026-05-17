# WMI C++ Usage

Typical flow: initialize COM, connect to a namespace with IWbemLocator::ConnectServer, then run a WQL query with ExecQuery.

## Snippet
```cpp
#define _WIN32_DCOM
#include <windows.h>
#include <wbemidl.h>
#include <comdef.h>
#pragma comment(lib, "wbemuuid.lib")

HRESULT QueryOsCaption()
{
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (FAILED(hr)) return hr;

    hr = CoInitializeSecurity(nullptr, -1, nullptr, nullptr,
                              RPC_C_AUTHN_LEVEL_CONNECT, RPC_C_IMP_LEVEL_IMPERSONATE,
                              nullptr, EOAC_NONE, nullptr);
    if (FAILED(hr) && hr != RPC_E_TOO_LATE) return hr;

    IWbemLocator* locator = nullptr;
    hr = CoCreateInstance(CLSID_WbemLocator, nullptr, CLSCTX_INPROC_SERVER,
                          IID_IWbemLocator, reinterpret_cast<void**>(&locator));
    if (FAILED(hr)) return hr;

    IWbemServices* services = nullptr;
    BSTR ns = SysAllocString(L"ROOT\\CIMV2");
    hr = locator->ConnectServer(ns, nullptr, nullptr, nullptr, 0, nullptr, nullptr, &services);
    SysFreeString(ns);
    if (FAILED(hr)) { locator->Release(); return hr; }

    IEnumWbemClassObject* enumerator = nullptr;
    BSTR lang = SysAllocString(L"WQL");
    BSTR query = SysAllocString(L"SELECT Caption FROM Win32_OperatingSystem");
    hr = services->ExecQuery(lang, query,
                             WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
                             nullptr, &enumerator);
    SysFreeString(lang);
    SysFreeString(query);

    if (enumerator) enumerator->Release();
    services->Release();
    locator->Release();
    return hr;
}
```

## References
- https://learn.microsoft.com/en-us/windows/win32/wmisdk/wmi-c---application-examples
- https://github.com/xanderfrangos/twinkle-tray/blob/674039980ad5a7331dfd6b3d060204f377b89550/src/modules/wmi-bridge/wmi-bridge.cc#L4
