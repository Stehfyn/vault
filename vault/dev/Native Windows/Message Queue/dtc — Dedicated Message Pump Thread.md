# dtc - Dedicated Message Pump Thread

`dtc` is a focused demonstration of separating the Win32 window-owning thread from the render or simulation loop. The reason this is not just "use another thread" is that USER32 can enter modal subloops while dispatching messages: moving a window, resizing it, tracking menus, or dragging system chrome can keep execution inside USER32 until the interaction ends. If the same thread is responsible for rendering, the app appears frozen even though the OS is doing exactly what the message model permits.

The pattern is useful but narrow. The thread that creates a window owns its queue, timers, hooks, clipboard viewer participation, and synchronous `SendMessage` obligations; cross-thread control must be marshaled deliberately, usually through posted messages or a small command queue. `dtc` belongs next to the hook and NTUSER queue notes because it exposes the practical consequence of per-thread message queues rather than reducing the pump to a ceremonial loop.

## Source Shape

The route is to create the HWND on a dedicated GUI thread, keep that thread pumping, and marshal render/simulation commands across the boundary instead of touching the window directly from the worker.

```cpp
DWORD WINAPI GuiThread(void *param) {
    HWND hwnd = CreateMainWindow(param);

    MSG msg;
    while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}

PostThreadMessageW(gui_thread_id, WM_APP_RENDER_COMMAND,
                   command_id, reinterpret_cast<LPARAM>(payload));
```

If the render thread needs a response, use an explicit synchronization object or command queue; do not turn arbitrary `SendMessage` calls into hidden cross-thread RPC.

## Source Code Reading

`dtc.cpp` is intentionally sharp-edged because it demonstrates thread affinity, not a general GUI architecture.

There are two window procedures:

- `ServiceWndProc` belongs to a hidden service window on the GUI/message thread. It handles custom messages `CREATE_DANGEROUS_WINDOW` and `DESTROY_DANGEROUS_WINDOW`.
- `DisplayWndProc` belongs to visible display windows. It forwards selected messages to the main/app thread with `PostThreadMessageW(MainThreadID, ...)`.

The cross-thread create path is the whole lesson:

```cpp
struct the_baby { DWORD exStyle; LPCWSTR cls; LPCWSTR title; DWORD style; ... };

MainThread:
    fill the_baby with CreateWindowExW arguments
    hwnd = (HWND)SendMessageW(serviceWindow, CREATE_DANGEROUS_WINDOW, &baby, 0)

ServiceWndProc:
    case CREATE_DANGEROUS_WINDOW:
        return (LRESULT)CreateWindowExW(baby->...)
```

The visible window still belongs to the service/message thread. `DisplayWndProc` chooses which messages become app-thread messages: `WM_CLOSE` posts the HWND in `wParam`, while `WM_MOUSEMOVE`, button events, `WM_DESTROY`, and `WM_CHAR` post their original payloads. Everything else goes to `DefWindowProcW` on the owner thread.

The GUI thread pump in `WinMain` is not a ceremonial loop. It calls `GetMessageW`, translates, and either forwards selected thread messages to the app thread or dispatches them to HWND procedures. The app thread separately drains its own queue with `PeekMessage` and runs rendering over all windows found by class name.

Observable probes:

- Start resizing or moving the visible window. The GUI thread can be inside USER32 modal tracking while the app thread continues its own loop.
- Replace `PostThreadMessageW` with direct app-state mutation in `DisplayWndProc`; races become possible because the window procedure is running on the GUI owner thread.
- Destroy every visible window and the app thread exits once its `FindWindowExW` scan returns none.

## Connections
- `System-Defined Messages` covers the message taxonomy this pump receives.
- `Message Queue Implementation` explains the NTUSER queue machinery behind `GetMessage`, `PeekMessage`, and sent-message wakeups.
- `Injected DLL Unload` depends on target threads returning to their pumps.

## References
- <https://github.com/cmuratori/dtc>
