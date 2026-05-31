# SetWindowsHookEx

`SetWindowsHookEx` installs hook procedures into USER32-defined event paths: keyboard, mouse, CBT, shell, call-window-proc, get-message, and related categories. The key distinction is thread-specific versus global. Thread hooks can live in the installing process when the target thread is local; global hooks that must run in other processes require a DLL that USER32 can map into those processes.

Hooks are synchronous enough to be dangerous. A slow or reentrant hook can stall input or window dispatch, and hook procedures must preserve the chain contract by passing unhandled events onward. Bitness, desktop/session isolation, integrity levels, and UIAccess rules also affect which processes can be hooked. This is a message-system facility first and an injection primitive only as a consequence of how global hooks are implemented.

## Source Shape

The minimum safe pattern is: install a hook procedure with the correct module/thread boundary, do little work in the callback, preserve the chain, and unhook once.

```cpp
LRESULT CALLBACK GetMsgProc(int code, WPARAM wParam, LPARAM lParam) {
    if (code >= 0) {
        const MSG *msg = reinterpret_cast<const MSG *>(lParam);
        ObserveMessage(msg->hwnd, msg->message, msg->wParam, msg->lParam);
    }
    return CallNextHookEx(nullptr, code, wParam, lParam);
}

HHOOK hook = SetWindowsHookExW(WH_GETMESSAGE, GetMsgProc,
                               module_with_proc, target_thread_id);
// ...
if (hook) {
    UnhookWindowsHookEx(hook);
    hook = nullptr;
}
```

Low-level keyboard/mouse hooks (`WH_KEYBOARD_LL`, `WH_MOUSE_LL`) are global but run in the installing process; many other global hooks require the procedure to live in a DLL mapped into target processes.

## Source Code Reading

Two benign source families show the contract from different sides:

- `kwhat/libuiohook/src/windows/input_hook.c` uses low-level keyboard/mouse hooks in the installing process.
- `strobejb/winspy/src/FindTool.c` uses a temporary keyboard hook to observe Escape/Shift/Control while a finder tool has mouse capture.

The low-level hook path in `libuiohook`:

```cpp
hook_run:
    hook_thread_id = GetCurrentThreadId()
    keyboard_event_hhook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboard_hook_event_proc, hInst, 0)
    mouse_event_hhook = SetWindowsHookEx(WH_MOUSE_LL, mouse_hook_event_proc, hInst, 0)
    while (GetMessage(&message, NULL, 0, 0) > 0) DispatchMessage(&message)

keyboard_hook_event_proc:
    KBDLLHOOKSTRUCT* k = (KBDLLHOOKSTRUCT*)lParam
    switch wParam: WM_KEYDOWN / WM_SYSKEYDOWN / WM_KEYUP / WM_SYSKEYUP
    return CallNextHookEx(...) unless the normalized event was consumed

hook_stop:
    PostThreadMessage(hook_thread_id, WM_QUIT, 0, 0)
```

That decomposes "install keyboard hook" into module handle, hook type, callback signature, pump lifetime, event normalization, chain preservation, and shutdown signal.

The WinSpy++ finder tool shows a narrower UI-instrumentation use. `FindTool.c` subclasses a `STATIC` control with `StaticProc`. On `WM_LBUTTONDOWN`, it calls `SetCapture`, changes the bitmap, shows a selection overlay, and installs `WH_KEYBOARD` so Escape can cancel without stealing focus. On drag end or cancel, `EndFindToolDrag` calls `ReleaseCapture`, restores the cursor, and `UnhookWindowsHookEx(draghook)`.

```cpp
WM_LBUTTONDOWN:
    SetCapture(hwnd)
    draghook = SetWindowsHookEx(WH_KEYBOARD, draghookproc, module, 0)

draghookproc:
    if VK_ESCAPE down -> PostMessage(hwnd, WM_CANCELMODE, 0, 0); return -1
    otherwise CallNextHookEx

WM_LBUTTONUP / WM_CANCELMODE:
    UnhookWindowsHookEx(draghook)
```

The falsifiable behavior: while dragging, Escape cancels the finder selection even though focus remains in the inspected app. If the hook is removed too early, Escape stops canceling; if `CallNextHookEx` is skipped for ordinary keys, the rest of the desktop sees broken keyboard behavior.

## Verification Route

Claim: the important distinction is not "hooks inject code" but which hook contract runs where. Low-level keyboard/mouse hooks run callbacks in the installing process and require that process to pump; many thread/global UI hooks run in the target thread context and therefore inherit target message lifetime and bitness constraints.

Why it matters for new code: a hotkey recorder, Spy++-style inspector, menu observer, and CBT window lifecycle monitor should not share one vague "install hook" helper. Each needs explicit answers for module handle, thread id, callback residence, pump ownership, and teardown.

How to verify:

- Log `GetCurrentProcessId()` and `GetCurrentThreadId()` inside a `WH_KEYBOARD_LL` callback and inside a same-thread `WH_GETMESSAGE` callback.
- Use Spy++ or your own message log to confirm the target thread must pump for `WH_GETMESSAGE` observation to continue.
- Deliberately return without `CallNextHookEx` only in a private test app and watch downstream input/message behavior break; then restore chain preservation.

Minimal code/pseudocode:

```cpp
LRESULT CALLBACK ProbeHook(int code, WPARAM w, LPARAM l) {
    if (code >= 0) {
        Log(GetCurrentProcessId(), GetCurrentThreadId(), w);
    }
    return CallNextHookEx(nullptr, code, w, l);
}

InstallLowLevel():
    SetWindowsHookExW(WH_KEYBOARD_LL, ProbeHook, hModule, 0)
    PumpMessagesUntilStop()

InstallThreadMessageProbe(tid):
    SetWindowsHookExW(WH_GETMESSAGE, ProbeHook, hModule, tid)
```

Interpretation: if the low-level callback reports the installing process while the message hook follows the target thread, the design must split these code paths. If the hook stops firing when the pump stops, the missing dependency is not "permissions"; it is message-loop lifetime.

## Connections
- WinSpy++ is a legitimate inspection use case for message hooks.
- `Injected DLL Unload` covers teardown behavior after a global hook has mapped a DLL elsewhere.
- `System-Defined Messages` and `Message Queue Implementation` explain what the hooks are observing.
- `../Input/libuiohook - Cross-Platform Input Hook.md` is the portable low-level-input wrapper branch.
- `../Custom Frame/Acrylic Popup Menus.md` shows `WH_CBT` used for menu-window discovery instead of keylogging.

## References
- Microsoft Docs: About Hooks (hook procedure signature, call chain, global vs. thread-specific)
  https://learn.microsoft.com/en-us/windows/win32/winmsg/about-hooks
