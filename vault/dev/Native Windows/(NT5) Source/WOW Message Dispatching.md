# WOW Message Dispatching

The NT5 WOW client code shows how Win16 compatibility survived inside the Win32 message path. Old-format messages, handles, pointers, and calling conventions had to be translated so 16-bit applications could participate in the same desktop, queues, and USER objects as native Win32 processes.

The point is not to emulate WOW today; it is to understand why USER32 contains so many compatibility seams. Message dispatch is a boundary where ABI details become visible: thunking, structure packing, pointer width, handle translation, and default procedure behavior all have to preserve old application expectations.

## Connections
- `Windows 1.0 Hello World` shows the source-era model WOW had to preserve.
- `SendMessage Path` and `Message Queue Implementation` show the modern dispatch machinery that compatibility code plugs into.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/client/wow.c#L763
