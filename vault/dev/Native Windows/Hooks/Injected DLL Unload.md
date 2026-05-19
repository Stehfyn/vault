# Injected DLL Unload

Global USER32 hooks do not unload merely because the installer called `UnhookWindowsHookEx`. The hook procedure can be mapped into multiple target processes, and each target thread has to return to a point where USER32 can observe the removal and release the module. Threads stuck outside their message loop, inside modal loops, or blocked in long work can keep the DLL resident longer than expected.

## Unhook and Wake Queues

The unload discussions contribute the teardown shape: remove the hook, then give target queues an opportunity to return through USER32. This is not guaranteed cleanup; it is a way to stop confusing "unhook requested" with "every mapped DLL image is gone."

```cpp
HHOOK old_hook = std::exchange(global_hook, nullptr);
if (old_hook) {
    UnhookWindowsHookEx(old_hook);
}

PostThreadMessageW(target_thread_id, WM_NULL, 0, 0);
```

## Idempotent Teardown

The repeated-unhook crash link contributes the simplest rule: own the hook handle exactly once and clear it before callbacks can race the shutdown path.

```cpp
void StopHook() {
    HHOOK hook = InterlockedExchangePointer(reinterpret_cast<PVOID volatile*>(&g_hook), nullptr);
    if (hook) {
        UnhookWindowsHookEx(hook);
    }
}
```

## Connections

- `SetWindowsHookEx` explains why global hook procedures live in DLLs.
- `dtc` and `Message Queue Implementation` explain why target-thread pumping controls when cleanup can complete.

## References

- <https://stackoverflow.com/questions/3164190/unloading-dll-from-all-processes-after-unhooking-global-cbt-hook/3165286#3165286>
- <https://stackoverflow.com/questions/25577117/unloading-an-injected-dll>
- <https://stackoverflow.com/questions/54059846/unhooking-a-hook-set-with-setwindowshookex-more-than-once-crashes-the-hooked-pro/54060384#54060384>
