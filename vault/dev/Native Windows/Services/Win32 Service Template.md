# Win32 Service Template

A correct Win32 service has two contracts: the Service Control Manager contract (`StartServiceCtrlDispatcher`, `ServiceMain`, status transitions, control handler) and the workload contract (worker lifetime, stop signaling, cleanup, logging). Most broken service samples fail by treating `ServiceMain` like `main`, never reporting pending/running/stopped state accurately, or blocking the control handler.

## SCM Skeleton

The winsvc reference and service template link contribute the required control flow: process entry registers with the SCM, `ServiceMain` registers a control handler, status is reported during transitions, and stop is signaled to worker code rather than executed inside the handler.

```cpp
SERVICE_TABLE_ENTRYW table[] = {
    { const_cast<LPWSTR>(L"MyService"), ServiceMain },
    { nullptr, nullptr }
};
StartServiceCtrlDispatcherW(table);
```

```cpp
void WINAPI ControlHandler(DWORD control) {
    if (control == SERVICE_CONTROL_STOP) {
        ReportStatus(SERVICE_STOP_PENDING, NO_ERROR, 3000);
        SetEvent(g_stop_event);
    }
}
```

## Failure Actions

`SC_ACTION` contributes the operational nuance: restart policy is SCM metadata, not a loop inside the service.

```cpp
SC_ACTION actions[] = {
    { SC_ACTION_RESTART, 5000 },
    { SC_ACTION_NONE, 0 }
};
SERVICE_FAILURE_ACTIONSW failure = {};
failure.dwResetPeriod = 86400;
failure.cActions = ARRAYSIZE(actions);
failure.lpsaActions = actions;

ChangeServiceConfig2W(service, SERVICE_CONFIG_FAILURE_ACTIONS, &failure);
```

## Source Code Reading

The linked `kazaamjt/Win32_Service-CPP-Template` source is a compact service wrapper. Files read:
- `Win32_Service.h`
- `example.cpp`
- `Win32_Service-CPP-Template.vcxproj`

`Win32_Service.h` composes the service out of a stored `SERVICE_STATUS`, a `SERVICE_STATUS_HANDLE`, worker pause/continue events, and wrapper methods around SCM transitions. The important entry path is:

```text
WindowsService::run
  -> StartServiceCtrlDispatcher(service table)
  -> service_main
     -> RegisterServiceCtrlHandler(name, control_handler)
     -> set status fields
     -> SetServiceStatus(...)
     -> start worker path

control_handler
  -> switch(SERVICE_CONTROL_STOP / PAUSE / CONTINUE / INTERROGATE)
  -> update SERVICE_STATUS
  -> signal worker-facing event
  -> SetServiceStatus(...)
```

The template also exposes the common failure mode: `SetServiceStatus` appears repeatedly, which means status reporting is not decoration. A service that starts work without first publishing `SERVICE_START_PENDING` / `SERVICE_RUNNING`, or stops work without a `STOP_PENDING` path, is not merely under-instrumented; it is violating the SCM protocol.

Minimal code to extract into your own service wrapper:

```cpp
SERVICE_STATUS status = {};
SERVICE_STATUS_HANDLE h = RegisterServiceCtrlHandlerW(name, Handler);

status.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
status.dwControlsAccepted = SERVICE_ACCEPT_STOP;
status.dwCurrentState = SERVICE_START_PENDING;
SetServiceStatus(h, &status);

// create stop event, start worker
status.dwCurrentState = SERVICE_RUNNING;
SetServiceStatus(h, &status);
```

Steps to verify:
1. Add logging around every `SetServiceStatus` call.
2. Start with `sc.exe start` and poll `sc.exe queryex`.
3. Stop with `sc.exe stop` and confirm the handler signals the worker instead of doing long cleanup inline.
4. Add one injected failure before `RUNNING`; the SCM should see a failed start, not a hung service.

## Install and Observe

Keep service installation, runtime state, and diagnostics separate. SCM APIs create and control the service; WMI/CIM inventories it; ETW/Event Log explain what it did.

```cpp
SC_HANDLE scm = OpenSCManagerW(nullptr, nullptr, SC_MANAGER_CREATE_SERVICE);
SC_HANDLE svc = CreateServiceW(
    scm, L"MyService", L"My Service",
    SERVICE_START | SERVICE_STOP | SERVICE_QUERY_STATUS | DELETE,
    SERVICE_WIN32_OWN_PROCESS,
    SERVICE_AUTO_START,
    SERVICE_ERROR_NORMAL,
    L"C:\\Program Files\\MyService\\MyService.exe",
    nullptr, nullptr, nullptr, nullptr, nullptr);
```

```powershell
sc.exe create MyService binPath= "C:\Program Files\MyService\MyService.exe" start= auto
sc.exe failure MyService reset= 86400 actions= restart/5000/none/0
sc.exe queryex MyService

Get-CimInstance Win32_Service -Filter "Name='MyService'" |
  Select-Object Name, State, StartMode, ProcessId, PathName

Get-WinEvent -LogName System -FilterXPath "*[System[Provider[@Name='Service Control Manager']]]" |
  Select-Object -First 20 TimeCreated, Id, ProviderName, Message
```

If the service owns a diagnostics loop, add an ETW provider or TraceLogging provider inside the worker. Do not overload SCM status text as telemetry; SCM is for lifecycle, not high-volume observability.

## Experiment Harness

Goal: verify the service lifecycle contract independently from the worker's real job.

Procedure:
1. Build a service that only reports `START_PENDING`, `RUNNING`, `STOP_PENDING`, and `STOPPED`, then waits on a stop event.
2. Add one `EventWrite` or TraceLogging event at each transition.
3. Drive it with `sc.exe` and compare four planes: SCM state, WMI state, System log, ETW events.

```powershell
sc.exe start MyService
sc.exe queryex MyService
Get-CimInstance Win32_Service -Filter "Name='MyService'" |
  Select Name,State,ProcessId,Started
Get-WinEvent -LogName System -MaxEvents 20 |
  Where-Object ProviderName -eq 'Service Control Manager'
```

Measurable signals:
- `dwCurrentState`, `dwCheckPoint`, `dwWaitHint` during pending states.
- SCM PID from `QueryServiceStatusEx`/`sc.exe queryex`.
- WMI `State`, `Started`, `ProcessId`.
- One ETW event per lifecycle transition.

Failure interpretation:
- `sc.exe start` times out: pending states/checkpoints/wait hints are wrong or `ServiceMain` blocked.
- WMI says stopped while SCM says running: WMI sample latency or provider issue; re-query before blaming SCM.
- System log has SCM errors but no ETW worker events: failure occurred before worker instrumentation.
- ETW events exist but SCM reports failure: worker ran, but lifecycle reporting/control-handler contract is wrong.

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/winsvc/>
- <https://learn.microsoft.com/en-us/windows/win32/api/winsvc/ns-winsvc-sc_action>
- <https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-queryservicestatusex>
- <https://github.com/kazaamjt/Win32_Service-CPP-Template/blob/master/Win32_Service.h>

## Connections

- `NanaRun` covers service identity and token context.
- `Ghost Window Prevention` covers what goes wrong when service-hosted helpers depend on interactive desktop behavior.
- `WMI C++ Usage` gives the inventory plane for services that should be queried without attaching a debugger.
- `EventWrite`, `krabsetw`, and `UIforETW` give the telemetry planes for occurrence logging, live consumers, and full ETL capture.
