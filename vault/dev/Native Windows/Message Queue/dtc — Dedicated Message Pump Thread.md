# dtc - Dedicated Message Pump Thread

`dtc` is a focused demonstration of separating the Win32 window-owning thread from the render or simulation loop. The reason this is not just "use another thread" is that USER32 can enter modal subloops while dispatching messages: moving a window, resizing it, tracking menus, or dragging system chrome can keep execution inside USER32 until the interaction ends. If the same thread is responsible for rendering, the app appears frozen even though the OS is doing exactly what the message model permits.

The pattern is useful but narrow. The thread that creates a window owns its queue, timers, hooks, clipboard viewer participation, and synchronous `SendMessage` obligations; cross-thread control must be marshaled deliberately, usually through posted messages or a small command queue. `dtc` belongs next to the hook and NTUSER queue notes because it exposes the practical consequence of per-thread message queues rather than reducing the pump to a ceremonial loop.

## Connections
- `System-Defined Messages` covers the message taxonomy this pump receives.
- `Message Queue Implementation` explains the NTUSER queue machinery behind `GetMessage`, `PeekMessage`, and sent-message wakeups.
- `Injected DLL Unload` depends on target threads returning to their pumps.

## References
- <https://github.com/cmuratori/dtc>
