# Hook Examples

This note is a triage map for hook examples rather than a code bucket. EventGhost demonstrates a practical USER32 message-hook lifecycle: create a hook thread, install keyboard/mouse or task hooks, keep a message loop alive, and tear down only after the hook chain has drained. That belongs with `SetWindowsHookEx`, `Injected DLL Unload`, and message-queue notes because hook lifetime is inseparable from target threads pumping messages.

DxWnd and UniversalHookX sit in the graphics/window-management branch of hooking: intercept presentation, input, cursor, or window APIs so old games and graphical apps can be wrapped, resized, overlaid, or corrected. Capnhook and Detour/MinHook sit in the inline/IAT branch: patch a call boundary inside the process and preserve an original path. CBTHooker is the window-manager branch: CBT hooks observe creation, activation, min/max, and destruction events before normal dispatch completes.

Injection collections are different from hook libraries. They are taxonomies of ways to get code into another process so a hook can exist there. Keep the distinction clear: SetWindowsHookEx, remote thread loading, APC delivery, manual mapping, and proxy DLL loading create different artifacts and require different defensive reasoning.

## USER32 Hook Shape

The EventGhost and CBT examples contribute the same lifetime rule: the installing thread and target thread must both be compatible with the hook contract, and hooks that depend on messages die when the pump dies.

```cpp
LRESULT CALLBACK CbtProc(int code, WPARAM wparam, LPARAM lparam) {
    if (code == HCBT_CREATEWND) {
        auto* created = reinterpret_cast<CBT_CREATEWNDW*>(lparam);
        // Inspect window creation before normal dispatch completes.
    }
    return CallNextHookEx(nullptr, code, wparam, lparam);
}

HHOOK hook = SetWindowsHookExW(WH_CBT, CbtProc, module, target_thread_id);

MSG msg;
while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
}

UnhookWindowsHookEx(hook);
```

## Inline/IAT Hook Shape

DxWnd, UniversalHookX, capnhook, Detours, and MinHook contribute a different boundary: preserve the original callable path and make the replacement behave like the intercepted ABI. The hard parts are not the jump instruction itself; they are calling convention, reentrancy, thread safety while patching, and device/window lifetime once the hook crosses graphics APIs.

```cpp
using PresentFn = HRESULT (STDMETHODCALLTYPE*)(IDXGISwapChain*, UINT, UINT);
PresentFn real_present = nullptr;

HRESULT STDMETHODCALLTYPE HookPresent(IDXGISwapChain* swap_chain,
                                      UINT sync_interval,
                                      UINT flags) {
    // Overlay, capture, or policy work must tolerate device loss and resizing.
    return real_present(swap_chain, sync_interval, flags);
}
```

## Injection Boundary

Injection collections contribute vocabulary, not a license to blur categories. A USER32 hook, a proxy DLL, a remote-thread `LoadLibrary`, and a manual map create different loader artifacts. Notes in this vault should name which boundary they cross before discussing a hook.

```cpp
struct HookArtifact {
    DWORD process_id;
    DWORD thread_id;
    const wchar_t* boundary;  // "SetWindowsHookEx", "proxy DLL", "IAT", "inline"
    const wchar_t* module_path;
};
```

## Source Code Reading

EventGhost's `_build/extensions/cFunctions/hooks.c` is a good lifecycle source. `StartHooks` creates a wait thread and a hook thread, waits for each to signal startup, and stores their thread IDs. `HookThreadProc` calls `CoInitialize`, creates a mutex, raises thread priority, loads the module that owns the hook procedures, calls `SetKeyboardHook` and `SetMouseHook`, primes the message queue with `PeekMessage`, signals startup, then runs `GetMessage` until `WM_QUIT`. On exit it calls `UnsetKeyboardHook`, `UnsetMouseHook`, closes the mutex, and `CoUninitialize`.

The architectural detail is `WaitThreadProc`: it uses `MsgWaitForMultipleObjects` instead of a blind wait. That lets the idle detector wake on either a kernel event or queued messages. If a GUI/hook support thread waits without message awareness, it can miss the very activity it is meant to observe.

EventGhost's `_build/extensions/TaskHook.dll/hook.cpp` is the compact window-event example. It stores hook handles in a shared data segment, finds EventGhost's hidden message receiver with `FindWindow`, installs `WH_CBT` and `WH_SHELL`, posts compact notifications such as `WM_APP+1`, `WM_APP+2`, and `WM_APP+3` back to the receiver, then unhooks both handles in `StopHook`. This is benign instrumentation: hooks observe focus/window create/destroy and forward metadata to an owner HWND.

`katahiromz/CBTHooker/dll/dll.cpp` shows a more explicit CBT monitor. `DoStartWatch` creates a named file mapping for `CBTDATA`, copies filter/action settings into it, installs `SetWindowsHookEx(WH_CBT, CBTProc, s_hinstDLL, 0)`, and writes the hook handle into the shared struct. `CBTProc` maps the shared data, switches on `HCBT_ACTIVATE`, `HCBT_CREATEWND`, `HCBT_DESTROYWND`, `HCBT_MINMAX`, `HCBT_MOVESIZE`, `HCBT_SETFOCUS`, and related codes, calls `DoTarget` for matching events, posts `WM_MYNOTIFY`, unmaps, and always calls `CallNextHookEx`.

The testable hook rules:

- If the hook thread exits its pump, hook callbacks stop.
- If the callback does not call `CallNextHookEx` for unhandled cases, unrelated UI behavior can break.
- If teardown does not call `UnhookWindowsHookEx` and wait for the hook-owning thread to settle, shutdown races and stale DLL references become likely.

## Connections
- `SetWindowsHookEx` covers USER32 hook contracts.
- PE injection notes cover loader and memory artifacts once code is introduced into a target.
- WinSpy++ is the clean GUI-inspection use case for message hooks.

## References
- EventGhost hooks.c: https://raw.githubusercontent.com/EventGhost/EventGhost/177be516849e74970d2e13cda82244be09f277ce/_build/extensions/cFunctions/hooks.c
- EventGhost TaskHook: https://raw.githubusercontent.com/EventGhost/EventGhost/177be516849e74970d2e13cda82244be09f277ce/_build/extensions/TaskHook.dll/hook.cpp
- DxWnd: https://github.com/DxWnd/DxWnd.reloaded/tree/7235efb7388b25a5dd1192b74df3c4860435ff65
- CBTHooker: https://github.com/katahiromz/CBTHooker
- capnhook: https://github.com/decafcode/capnhook
- InjectCollection: https://github.com/AzureGreen/InjectCollection
