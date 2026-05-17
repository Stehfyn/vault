# Injected DLL Unload

Global hooks unload only after target threads return to their message loops. A common mitigation is to unhook and broadcast `WM_NULL` to wake loops so `FreeLibrary` can complete.

```cpp
// Unhook, then wake message loops so the hook DLL can unload.
UnhookWindowsHookEx(hHook);

DWORD_PTR result = 0;
SendMessageTimeoutW(HWND_BROADCAST, WM_NULL, 0, 0,
                    SMTO_ABORTIFHUNG, 100, &result);
```

## References
- https://stackoverflow.com/questions/3164190/unloading-dll-from-all-processes-after-unhooking-global-cbt-hook/3165286#3165286
- https://stackoverflow.com/questions/25577117/unloading-an-injected-dll
- https://stackoverflow.com/questions/54059846/unhooking-a-hook-set-with-setwindowshookex-more-than-once-crashes-the-hooked-pro/54060384#54060384
