# DLL Load Notification

`LdrRegisterDllNotification` is an NTDLL loader callback, not a shell extension point and not a general instrumentation API. Its value is timing: it observes a module after the loader has mapped it and before arbitrary higher-level code necessarily notices. That makes it useful for diagnostics, plugin hosts, and defensive inventory, but it also means the callback must stay loader-safe.

The function is exported by `ntdll.dll` but lives in the devnotes layer, so production code usually resolves it dynamically and degrades cleanly on platforms where it is absent.

```cpp
using LdrRegisterDllNotificationFn =
    NTSTATUS (NTAPI*)(ULONG, PLDR_DLL_NOTIFICATION_FUNCTION, PVOID, PVOID*);
using LdrUnregisterDllNotificationFn = NTSTATUS (NTAPI*)(PVOID);

auto ntdll = GetModuleHandleW(L"ntdll.dll");
auto register_notification = reinterpret_cast<LdrRegisterDllNotificationFn>(
    GetProcAddress(ntdll, "LdrRegisterDllNotification"));
auto unregister_notification = reinterpret_cast<LdrUnregisterDllNotificationFn>(
    GetProcAddress(ntdll, "LdrUnregisterDllNotification"));

PVOID cookie = nullptr;
if (register_notification) {
    register_notification(0, OnDllNotification, nullptr, &cookie);
}
```

The callback should copy only the facts it needs and hand work to another thread. Calling `LoadLibrary`, COM activation, shell APIs, or anything that can recursively enter the loader turns a useful observer into a deadlock risk.

```cpp
void NTAPI OnDllNotification(ULONG reason,
                             const LDR_DLL_NOTIFICATION_DATA* data,
                             void* context) {
    if (reason != LDR_DLL_NOTIFICATION_REASON_LOADED) {
        return;
    }

    const auto* name = data->Loaded.FullDllName;
    if (name && name->Buffer && name->Length) {
        // Copy the UNICODE_STRING contents into an owned queue item.
        // Do logging, symbol loading, COM, or shell work outside the callback.
    }
}
```

## Connections

- `DLL Load Notification Shell.md` is the shell-oriented use case: observing shell/plugin load boundaries.
- `Injected DLL Unload.md` explains why unload ordering and callback teardown matter.
- `Native API.md` supplies the `UNICODE_STRING` boundary used by loader notifications.

## Reference

- <https://learn.microsoft.com/en-us/windows/win32/devnotes/ldrregisterdllnotification>
