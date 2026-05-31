# WMI C++ Usage

Native WMI code is COM code with a query language bolted on: initialize COM security, create `IWbemLocator`, connect to a namespace such as `ROOT\CIMV2`, then issue WQL through `IWbemServices::ExecQuery` and enumerate `IWbemClassObject` results. Most failures in real programs come from COM security being initialized too late, using the wrong impersonation level, or assuming a provider is cheap because the query syntax looks like SQL.

The Twinkle Tray bridge link matters because it shows WMI used as a practical subsystem bridge rather than a toy OS-caption query: monitor/brightness utilities often have to combine WMI provider data with display-control APIs and vendor behavior. Keep WMI entries tied to their namespace/provider and latency profile; polling WMI from a UI thread is a common Native Windows footgun.

## Query Skeleton

The source-shaped path is fixed: COM apartment, COM security, locator, namespace connection, proxy blanket, WQL, enumerator, `VARIANT` extraction.

```cpp
#define _WIN32_DCOM
#include <Wbemidl.h>
#include <comdef.h>
#pragma comment(lib, "wbemuuid.lib")

HRESULT QueryServices() {
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (FAILED(hr)) return hr;

    hr = CoInitializeSecurity(nullptr, -1, nullptr, nullptr,
        RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE,
        nullptr, EOAC_NONE, nullptr);
    if (FAILED(hr)) return hr;

    IWbemLocator* locator = nullptr;
    hr = CoCreateInstance(CLSID_WbemLocator, nullptr,
        CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&locator));
    if (FAILED(hr)) return hr;

    IWbemServices* svc = nullptr;
    hr = locator->ConnectServer(_bstr_t(L"ROOT\\CIMV2"),
        nullptr, nullptr, nullptr, 0, nullptr, nullptr, &svc);
    if (FAILED(hr)) return hr;

    hr = CoSetProxyBlanket(svc, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE,
        nullptr, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE,
        nullptr, EOAC_NONE);
    if (FAILED(hr)) return hr;

    IEnumWbemClassObject* rows = nullptr;
    hr = svc->ExecQuery(_bstr_t(L"WQL"),
        _bstr_t(L"SELECT Name, State, ProcessId FROM Win32_Service"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        nullptr, &rows);
    if (FAILED(hr)) return hr;

    for (;;) {
        IWbemClassObject* row = nullptr;
        ULONG returned = 0;
        hr = rows->Next(5000, 1, &row, &returned);
        if (hr == WBEM_S_FALSE || returned == 0) break;

        VARIANT name;
        VariantInit(&name);
        if (SUCCEEDED(row->Get(L"Name", 0, &name, nullptr, nullptr)) && name.vt == VT_BSTR) {
            wprintf(L"%s\n", name.bstrVal);
        }
        VariantClear(&name);
        row->Release();
    }
    return S_OK;
}
```

Twinkle Tray's `root\\WMI` monitor path contributes the other important shape: provider namespaces matter. `WmiMonitorBrightness` and `WmiMonitorBrightnessMethods` are not in `ROOT\\CIMV2`; service inventory is.

## Source Code Reading

The Twinkle Tray bridge is a practical source because it uses WMI as a hardware-provider bridge from a Node/Electron app. The source file is `src/modules/wmi-bridge/wmi-bridge.cc`.

`wmiConnect` handles process-wide COM setup:

```text
wmiConnect()
  -> CoInitializeEx(NULL, COINIT_MULTITHREADED)
  -> CoInitializeSecurity(... RPC_C_AUTHN_LEVEL_CONNECT, RPC_C_IMP_LEVEL_IMPERSONATE ...)
  -> set global `wmiConnected`
```

`getWMIBrightness` creates an `IWbemLocator`, connects to `root\WMI`, executes `SELECT * FROM WmiMonitorBrightness`, and extracts `InstanceName` plus `CurrentBrightness` from each `IWbemClassObject`. The code detail readers need is namespace selection: monitor brightness is not in `ROOT\CIMV2`.

```cpp
ConnectServer(L"root\\WMI", ..., &pService);
ExecQuery(L"WQL", L"SELECT * FROM WmiMonitorBrightness", WBEM_FLAG_FORWARD_ONLY, ..., &pEnumerator);
clsObj->Get(L"InstanceName", ...);
clsObj->Get(L"CurrentBrightness", ...);
```

`setWMIBrightness` is the method-call body: connect to `ROOT\WMI`, call `CoSetProxyBlanket`, query `WmiMonitorBrightnessMethods`, get the class object, call `GetMethod("WmiSetBrightness")`, spawn an input-parameter instance, fill `Timeout` and `Brightness`, read the target object's `__PATH`, then call `ExecMethod`.

```text
namespace connection
  -> proxy blanket
  -> query instances
  -> GetObject(class)
  -> GetMethod(method)
  -> SpawnInstance(input params)
  -> Put("Timeout")
  -> Put("Brightness")
  -> instance.Get("__PATH")
  -> ExecMethod(instance path, method, params)
```

Verifiable assertions to drive:

```text
claim: WMI success depends on namespace, not just class name
probe: query `WmiMonitorBrightness` under `ROOT\CIMV2` and `ROOT\WMI`; compare HRESULT/row count

claim: method calls need instance paths
probe: log the `__PATH` used for `ExecMethod`; empty path means the target instance was not selected

claim: proxy security changes failure mode
probe: run with and without `CoSetProxyBlanket`; compare HRESULTs for query vs method call
```

Source files read:
- `twinkle-tray/src/modules/wmi-bridge/wmi-bridge.cc`
- `twinkle-tray/src/modules/wmi-bridge/index.js`

```powershell
Get-CimInstance -Namespace root/cimv2 -ClassName Win32_Service |
  Select-Object Name, State, StartMode, ProcessId

Get-CimInstance -Namespace root/wmi -ClassName WmiMonitorBrightness |
  Select-Object InstanceName, CurrentBrightness
```

## Experiment Harness

Goal: compare WMI inventory against SCM authority for the same service and measure staleness, privilege, and provider failure.

```powershell
$name = 'MyService'
1..10 | ForEach-Object {
  $t = Get-Date
  $scm = sc.exe queryex $name
  $wmi = Get-CimInstance Win32_Service -Filter "Name='$name'" |
    Select-Object Name, State, ProcessId, StartMode, PathName
  [pscustomobject]@{ Time=$t; WmiState=$wmi.State; WmiPid=$wmi.ProcessId; ScmText=($scm -join ' | ') }
  Start-Sleep -Milliseconds 500
}
```

Procedure:
1. Start, stop, and restart the service while the loop runs.
2. Record the first timestamp where SCM reports the new state.
3. Record the first timestamp where WMI reports the same state/PID.
4. Repeat from elevated and non-elevated shells.

Failure interpretation:
- SCM sees the state and WMI lags: provider/inventory latency, not service failure.
- WMI query fails but `sc.exe` works: COM security, namespace, provider, firewall/DCOM, or privilege problem.
- WMI `ProcessId` is `0` while SCM has a PID: service is stopped/pending or the WMI snapshot is stale.
- Both disagree with Event Log: you are sampling state after the failure; use ETW/Event Log for history.

## Connections
- `HWID Composition Reference` uses WMI classes for machine identifiers.
- Display-control and monitor entries often need WMI only as one piece of an inventory path.
- `Win32 Service Template` is relevant when WMI polling/eventing is moved out of an interactive process.
- `windows-defender-remover` should be studied through WMI/SCM inventory first: compare `Win32_Service`, `sc.exe query`, and event logs before assuming a script succeeded.
- ETW answers "what happened"; WMI usually answers "what state is visible now." Use both when debugging services.

## Discussion Claim Verification

Claim: "A WMI query is an authoritative diagnostic answer."

Why it matters for new diagnostic code: WMI is often a provider-backed snapshot, not the state-transition ledger. For services and devices, the correct diagnostic code usually pairs WMI with SCM/Event Log/ETW or a device-specific API.

How to verify:
1. Query a service through `Win32_Service`.
2. Query the same service through `sc.exe queryex` or `OpenService`/`QueryServiceStatusEx`.
3. Capture System log rows from Service Control Manager.
4. During rapid start/stop, record the first timestamp where each plane changes.

Minimal code/pseudocode:

```powershell
$name = "Spooler"
1..20 | ForEach-Object {
  [pscustomobject]@{
    T = Get-Date
    Wmi = (Get-CimInstance Win32_Service -Filter "Name='$name'").State
    Scm = (sc.exe queryex $name | Select-String "STATE").ToString()
  }
  Start-Sleep -Milliseconds 250
}
```

Interpretation: the Microsoft WMI examples and `Win32_Service` links support the query contract. The Twinkle Tray link supports a specific hardware/provider bridge under `root\WMI`; it does not support generic service-inventory claims. If service state disagrees, treat WMI as a sampled provider path until SCM and Event Log evidence corroborate it.

## References
- <https://learn.microsoft.com/en-us/windows/win32/wmisdk/wmi-c---application-examples>
- <https://learn.microsoft.com/en-us/windows/win32/cimwin32prov/win32-service>
- <https://github.com/xanderfrangos/twinkle-tray/blob/674039980ad5a7331dfd6b3d060204f377b89550/src/modules/wmi-bridge/wmi-bridge.cc#L4>
