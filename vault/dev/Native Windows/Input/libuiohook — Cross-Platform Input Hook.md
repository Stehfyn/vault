# libuiohook - Cross-Platform Global Input Hook

`libuiohook` wraps global keyboard and mouse capture behind one C API across Windows, macOS, and X11. On Windows that means low-level hook procedures rather than Raw Input, so it is convenient for hotkey daemons, accessibility tooling, and telemetry prototypes, but it inherits the latency, trust, and desktop-session limits of `SetWindowsHookEx`.

The repo is worth keeping because it gives a portable abstraction while still exposing the native compromise: hooks observe translated input after the OS has already interpreted device packets. Compare it with `InputEventFlags.h` and `Mouse Input` when deciding between raw device state, foreground window messages, and global observation.

## Source Shape

On Windows the shape is the low-level hook contract: install, inspect the `KBDLLHOOKSTRUCT`/`MSLLHOOKSTRUCT`, forward, then keep the installing thread alive with a pump.

```cpp
LRESULT CALLBACK LowKeyboard(int code, WPARAM wParam, LPARAM lParam) {
    if (code == HC_ACTION) {
        const KBDLLHOOKSTRUCT *kbd =
            reinterpret_cast<const KBDLLHOOKSTRUCT *>(lParam);
        PublishKeyEvent(wParam, kbd->vkCode, kbd->scanCode, kbd->flags);
    }
    return CallNextHookEx(nullptr, code, wParam, lParam);
}

HHOOK hook = SetWindowsHookExW(WH_KEYBOARD_LL, LowKeyboard, nullptr, 0);
MSG msg;
while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
    DispatchMessageW(&msg);
}
```

## Source Code Reading

The Windows backend is `src/windows/input_hook.c`. It is much richer than the minimal hook snippet: it owns hook handles, modifier state, click-count state, a dispatcher callback, and a message pump.

Global state at the top of the file tells the real lifetime story:

```cpp
static DWORD hook_thread_id;
static HHOOK keyboard_event_hhook;
static HHOOK mouse_event_hhook;
static HWINEVENTHOOK win_event_hhook;
static unsigned short current_modifiers;
static uiohook_event event;
static dispatcher_t dispatcher;
```

`hook_run` is the entry point. It stores `GetCurrentThreadId`, resolves `hInst` if `DllMain` did not, installs `WH_KEYBOARD_LL` and `WH_MOUSE_LL`, installs a `SetWinEventHook(EVENT_OBJECT_NAMECHANGE, ...)` restart hook, initializes modifier state from `GetKeyState`, sends a synthetic `EVENT_HOOK_ENABLED`, and then blocks in `GetMessage`.

```cpp
keyboard_event_hhook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboard_hook_event_proc, hInst, 0);
mouse_event_hhook = SetWindowsHookEx(WH_MOUSE_LL, mouse_hook_event_proc, hInst, 0);
while (GetMessage(&message, NULL, 0, 0) > 0) {
    TranslateMessage(&message);
    DispatchMessage(&message);
}
```

`keyboard_hook_event_proc` casts `lParam` to `KBDLLHOOKSTRUCT`, switches on `WM_KEYDOWN`, `WM_SYSKEYDOWN`, `WM_KEYUP`, and `WM_SYSKEYUP`, and delegates to `process_key_pressed` or `process_key_released`. Those functions update modifier masks, translate virtual keys to library keycodes, optionally emit typed Unicode via `keycode_to_unicode`, and dispatch a `uiohook_event`.

`mouse_hook_event_proc` casts `lParam` to `MSLLHOOKSTRUCT`, switches on button, move, and wheel messages, updates button masks, computes click counts from timestamp and previous click point, reads wheel line/page policy through `SystemParametersInfo`, and dispatches the normalized event.

Teardown is just as important as installation. `unregister_running_hooks` calls `UnhookWinEvent` and `UnhookWindowsHookEx` for every live handle, then nulls the globals. `hook_stop` posts `WM_QUIT` to the hook thread. The observable contract: a low-level hook is not "installed and forgotten"; it is a thread-owned pump plus callback state plus explicit shutdown.

## References
- <https://github.com/kwhat/libuiohook>

## Connections
- `../Hooks/SetWindowsHookEx.md` is the native contract hidden behind the portable API.
- `InputEventFlags.h - Raw Input Bitfields.md` is the lower-level device-classification branch.
- `../Message Queue/dtc - Dedicated Message Pump Thread.md` explains why the hook thread still needs a live message pump.
