# SWH-Injector - SetWindowsHookEx DLL Injector

SWH-Injector is a focused example of using the global-hook mechanism to cause a DLL to load in a GUI target process. The useful point is not the injector itself; it is the constraint profile of this method. It depends on GUI threads, desktops, bitness compatibility, hookable event categories, DLL export shape, and the target returning through USER32 dispatch.

From a defensive perspective, SetWindowsHookEx-based loading has a different signature from remote-thread or manual-map approaches: a hook registration, USER32-mediated DLL mapping, message-pump dependency, and eventual unload behavior tied to hook teardown. That is why it belongs in Hooks as much as in PE injection.

## Connections
- `SetWindowsHookEx` defines the underlying contract.
- `Injected DLL Unload` explains why cleanup may lag after unhooking.
- PE injection notes cover the broader injection taxonomy.

## References
- <https://github.com/M-r-J-o-h-n/SWH-Injector>
