# Kernel DLL Injector (Rhydon1337)

This repository is another small example of kernel-to-user DLL injection. Its research value is the separation of authority: the driver may have kernel visibility and privileges, but the loaded module becomes a user-mode artifact subject to loader state, PEB/module lists, thread context, and normal process telemetry.

That separation is exactly what defenders can reason about. Kernel components leave service/driver and callback artifacts; user-mode DLL presence leaves image-load, memory-map, thread, and module-list artifacts. The combination matters more than any single API name.

## Connections
- Compare with `KernelBhop` for a driver that exposes memory access rather than loader manipulation.
- Compare with `ManualMap` and reflective loaders for approaches that avoid normal DLL load state.

## References
- <https://github.com/Rhydon1337/windows-kernel-dll-injector>
