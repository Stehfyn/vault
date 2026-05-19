# HookLib - Pure C User/Kernel Hooking

HookLib is a C-oriented interception library that spans user-mode and kernel-mode use cases. Its value is not that hooking is inherently good architecture; it is that the project exposes the shared low-level problems: resolving target addresses, preserving original execution, synchronizing patch/unpatch operations, and separating architecture-specific mechanics from the public hook interface.

For research, read it as a library-design contrast with one-off demos. User-mode inline hooks, kernel callbacks, SSDT/syscall experiments, and driver-mediated interception have different stability and safety boundaries even when they are all called "hooks." Good notes should name the boundary rather than flattening them together.

## Connections
- MinHook and Detour cover the focused user-mode function-hook branch.
- Kernel-Bridge covers the broader kernel experimentation environment adjacent to HookLib.

Code contribution: use it to distinguish user-mode patching APIs, driver IOCTL boundaries, callback registration, `SSDT`/syscall experiments, and architecture-specific hook structs.

## References
- <https://github.com/HoShiMin/HookLib>
