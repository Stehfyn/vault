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

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/winsvc/>
- <https://learn.microsoft.com/en-us/windows/win32/api/winsvc/ns-winsvc-sc_action>
- <https://github.com/kazaamjt/Win32_Service-CPP-Template/blob/master/Win32_Service.h>

## Connections

- `NanaRun` covers service identity and token context.
- `Ghost Window Prevention` covers what goes wrong when service-hosted helpers depend on interactive desktop behavior.
