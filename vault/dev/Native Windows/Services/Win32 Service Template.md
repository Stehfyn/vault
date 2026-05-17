# Win32 Service Template

## References
- https://learn.microsoft.com/en-us/windows/win32/api/winsvc/ns-winsvc-sc_action
- https://learn.microsoft.com/en-us/windows/win32/api/winsvc/
- https://github.com/kazaamjt/Win32_Service-CPP-Template/blob/master/Win32_Service.h

## SC_ACTION usage (failure actions)
```cpp
SC_ACTION actions[] = {
  { SC_ACTION_RESTART, 60000 },
  { SC_ACTION_NONE, 0 }
};

SERVICE_FAILURE_ACTIONS sfa = {};
sfa.dwResetPeriod = 24 * 60 * 60;
sfa.cActions = ARRAYSIZE(actions);
sfa.lpsaActions = actions;

ChangeServiceConfig2(serviceHandle, SERVICE_CONFIG_FAILURE_ACTIONS, &sfa);
```

## Minimal service entrypoints
```cpp
SERVICE_STATUS_HANDLE g_statusHandle = nullptr;
SERVICE_STATUS g_status = {};

void WINAPI ServiceMain(DWORD, LPSTR*);
DWORD WINAPI ServiceCtrlHandler(DWORD control, DWORD eventType, LPVOID eventData, LPVOID context);

int wmain() {
  SERVICE_TABLE_ENTRYA table[] = {
    { const_cast<LPSTR>("MyService"), ServiceMain },
    { nullptr, nullptr }
  };
  StartServiceCtrlDispatcherA(table);
  return 0;
}

void WINAPI ServiceMain(DWORD, LPSTR*) {
  g_statusHandle = RegisterServiceCtrlHandlerExA("MyService", ServiceCtrlHandler, nullptr);
  g_status.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
  g_status.dwCurrentState = SERVICE_START_PENDING;
  SetServiceStatus(g_statusHandle, &g_status);

  // TODO: start worker thread, create stop event, etc.

  g_status.dwCurrentState = SERVICE_RUNNING;
  SetServiceStatus(g_statusHandle, &g_status);
}

DWORD WINAPI ServiceCtrlHandler(DWORD control, DWORD, LPVOID, LPVOID) {
  if (control == SERVICE_CONTROL_STOP) {
    g_status.dwCurrentState = SERVICE_STOP_PENDING;
    SetServiceStatus(g_statusHandle, &g_status);
    // TODO: signal stop event.
    g_status.dwCurrentState = SERVICE_STOPPED;
    SetServiceStatus(g_statusHandle, &g_status);
  }
  return NO_ERROR;
}
```
