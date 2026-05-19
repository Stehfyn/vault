# KernelGDIDraw - Ring-0 Desktop Overlay

`KernelGDIDraw` explores drawing on the desktop from kernel mode by attaching to a GUI process/session and calling into win32k/GDI paths while coordinating with graphics-kernel submission. The important lesson is that GDI state is session/thread/process sensitive; a random system thread does not magically own a desktop DC. Attaching to a GUI process is part of the technique, not incidental boilerplate.

This is drivers-adjacent research rather than an application overlay pattern. It bypasses user-mode overlay hooks precisely because it is below them, which also means version fragility, crash risk, and security boundaries dominate the engineering problem. For normal overlays, use documented user-mode composition paths.

## References
- <https://github.com/BadPlayer555/KernelGDIDraw> - kernel-mode GDI desktop drawing experiment.

## Connections
- `dxgkernel Overview.md` gives the low-level graphics boundary.
- DWM/DirectComposition entries elsewhere in Native Windows cover user-mode overlay/composition approaches.
