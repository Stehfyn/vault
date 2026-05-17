# SetWindowsHookEx

## Summary
- Hooks intercept system events (messages, mouse, keyboard) via a hook procedure installed with `SetWindowsHookEx`.  
- Hook procedures should call `CallNextHookEx` to pass events down the chain.  
- Global hooks run in other processes and require the hook procedure to live in a DLL; remove hooks as soon as possible to avoid system slowdowns.  

## Minimal example
```c
static HHOOK g_hook = NULL;

LRESULT CALLBACK HookProc(int code, WPARAM wParam, LPARAM lParam)
{
    if (code < 0)
        return CallNextHookEx(g_hook, code, wParam, lParam);

    // TODO: handle event
    return CallNextHookEx(g_hook, code, wParam, lParam);
}

void InstallHook(HINSTANCE module, DWORD threadId)
{
    g_hook = SetWindowsHookEx(WH_KEYBOARD, HookProc, module, threadId);
}

void RemoveHook(void)
{
    if (g_hook)
    {
        UnhookWindowsHookEx(g_hook);
        g_hook = NULL;
    }
}
```

## References
- Microsoft Docs: About Hooks (hook procedure signature, call chain, global vs. thread-specific)  
  https://learn.microsoft.com/en-us/windows/win32/winmsg/about-hooks
