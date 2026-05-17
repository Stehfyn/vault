# DLL Load Notification

Per-link reference with a focused snippet.

## LdrRegisterDllNotification
Link: https://learn.microsoft.com/en-us/windows/win32/devnotes/ldrregisterdllnotification
Brief: Dynamically resolve and register a DLL load callback.
```cpp
VOID CALLBACK MyDllNotify(ULONG reason, const LDR_DLL_NOTIFICATION_DATA* data, PVOID ctx) { }
auto fn = (decltype(&LdrRegisterDllNotification))GetProcAddress(
    GetModuleHandleW(L"ntdll.dll"), "LdrRegisterDllNotification");
PVOID cookie = NULL;
if (fn) {
  fn(0, MyDllNotify, NULL, &cookie);
}
```

