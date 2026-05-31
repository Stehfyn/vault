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

## Discussion Claim To Verify

Claim: the useful forum claim is not "force unload the DLL"; it is "unhook requests are observed when target GUI threads next pass through USER message retrieval." For UI instrumentation hooks, teardown is therefore a message-pump/lifetime problem.

Why it matters for new code: hook code must treat `UnhookWindowsHookEx` as the end of the callback contract, not as proof that every mapped image has vanished instantly. Timers, worker threads, subclass state, and shared memory owned by the hook DLL need explicit shutdown before the unhook path makes the code unavailable.

How to verify:

- Use a benign test hook against your own GUI test process. Load symbols if available, then watch module unload notifications or break on `user32!__ClientFreeLibrary` where present.
- After `UnhookWindowsHookEx`, post `WM_NULL` to the target GUI thread and observe whether the module unload occurs after `GetMessage` / `PeekMessage` resumes.
- Repeat while the target thread is stuck in a long handler or modal loop. The delayed case proves that teardown depends on target message progress.

Minimal code/pseudocode:

```cpp
StopInstrumentation():
    HHOOK h = exchange(g_hook, nullptr)
    if h:
        UnhookWindowsHookEx(h)
        PostThreadMessageW(target_tid, WM_NULL, 0, 0) // wake, not magic unload
```

```text
WinDbg:
  sxe ud hookdll.dll
  bp user32!__ClientFreeLibrary
  g
```

Interpretation: if unload happens only after the target pumps again, the forum claim is verified for that build/path. If a timer thread crashes after detach, the bug is not "UnhookWindowsHookEx crashed"; it is code continuing to execute from a DLL whose hook lifetime has ended.

## Connections

- `SetWindowsHookEx` explains why global hook procedures live in DLLs.
- `dtc` and `Message Queue Implementation` explain why target-thread pumping controls when cleanup can complete.

## References

- <https://stackoverflow.com/questions/3164190/unloading-dll-from-all-processes-after-unhooking-global-cbt-hook/3165286#3165286>
- <https://stackoverflow.com/questions/25577117/unloading-an-injected-dll>
- <https://stackoverflow.com/questions/54059846/unhooking-a-hook-set-with-setwindowshookex-more-than-once-crashes-the-hooked-pro/54060384#54060384>
