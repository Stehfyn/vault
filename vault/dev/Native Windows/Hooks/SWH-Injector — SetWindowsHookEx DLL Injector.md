# SWH-Injector - SetWindowsHookEx DLL Injector

SWH-Injector is a focused example of using the global-hook mechanism to cause a DLL to load in a GUI target process. The useful point is not the injector itself; it is the constraint profile of this method. It depends on GUI threads, desktops, bitness compatibility, hookable event categories, DLL export shape, and the target returning through USER32 dispatch.

From a defensive perspective, SetWindowsHookEx-based loading has a different signature from remote-thread or manual-map approaches: a hook registration, USER32-mediated DLL mapping, message-pump dependency, and eventual unload behavior tied to hook teardown. That is why it belongs in Hooks as much as in PE injection.

## Source Shape

The injector side is short because USER32 does the mapping. The DLL still has to export a hook procedure with the hook type's signature.

```cpp
HMODULE dll = LoadLibraryW(L"HookPayload.dll");
HOOKPROC proc = reinterpret_cast<HOOKPROC>(
    GetProcAddress(dll, "HookProc"));

HHOOK hook = SetWindowsHookExW(WH_CBT, proc, dll, target_thread_id);
PostThreadMessageW(target_thread_id, WM_NULL, 0, 0);
```

The target thread must pump messages for the hook procedure to run and later return through USER32 teardown.

## Connections
- `SetWindowsHookEx` defines the underlying contract.
- `Injected DLL Unload` explains why cleanup may lag after unhooking.
- PE injection notes cover the broader injection taxonomy.
- `../Message Queue/dtc - Dedicated Message Pump Thread.md` explains why GUI-thread liveness controls delivery.

## References
- <https://github.com/M-r-J-o-h-n/SWH-Injector>
