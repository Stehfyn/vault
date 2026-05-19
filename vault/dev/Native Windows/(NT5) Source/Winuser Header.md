# Winuser Header (public SDK)

`winuser.h` is the public contract for USER32: window classes, windows, messages, hooks, cursors, menus, accelerators, dialogs, system metrics, raw input, clipboard, and a large set of macros that encode message payloads. It is the first file to read when deciding whether behavior is a documented Win32 contract or an internal NTUSER implementation detail.

The NT5 copy and Wine's copy are useful together. The NT5 header shows the Microsoft SDK surface at a specific historical point; Wine's header shows the compatibility community's accumulated interpretation of the same ABI. When a constant or structure exists in both, it is often part of the durable public surface even if the surrounding implementation moved.

## Connections
- `NT User Message Definitions` covers private/internal message traffic outside the public SDK contract.
- `SetWindowsHookEx`, message queue notes, and WinSpy++ all sit on top of `winuser.h` declarations.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/public/sdk/inc/winuser.h#L11456C1-L11456C62
- https://github.com/wine-mirror/wine/blob/master/include/winuser.h
