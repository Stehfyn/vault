# Win32k Kernel Structures (userk.h)

`userk.h` exposes the NT5 kernel-mode shape behind USER objects: windows, menus, queues, thread state, desktops, and server-side flags. Public APIs reveal selected fields as styles, rectangles, thread IDs, class names, or handles; the internal structures explain how those views are cached, synchronized, and tied to win32k-owned lifetime.

The warning is versioning. Structure names and field order are not stable ABI, and modern Windows added mitigations and layout changes. The value here is conceptual: a window handle is an index to a server-side object with client-side mirrors and validation, not a pointer to a C++ object an app owns.

## Connections
- `WND Internal Structure` covers user-mode reverse-engineered views of the same object family.
- `Message Queue Implementation` and `Window Manager Internals` show these structures in motion.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/userk.h#L3580
