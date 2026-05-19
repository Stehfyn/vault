# System Command Processing (syscmd.c)

`syscmd.c` routes `WM_SYSCOMMAND` into the window-manager actions behind close, move, size, minimize, maximize, restore, menu tracking, screensaver, and monitor-power commands. The low bits of `wParam` are not part of the command identity, which is why correct code masks with `0xFFF0` before comparing.

The file matters because system commands bridge UI decoration and window state. Caption buttons, Alt+Space menus, keyboard accelerators, and non-client hit tests all converge here. Custom chrome that intercepts `WM_NCHITTEST` or `WM_NCPAINT` still has to preserve the system-command contract or it will break keyboard access, move/size loops, and default close/minimize behavior.

## Connections
- `Caption Rendering` emits the visual affordances that generate many system commands.
- `MinMax Size Computation` constrains commands such as size, maximize, and restore.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/syscmd.c
