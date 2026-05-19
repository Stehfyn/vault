# cbClsExtra and cbWndExtra

`cbWndExtra` reserves bytes on every instance of a window class; `cbClsExtra` reserves bytes on the class object shared by all instances. Access is through `GetWindowLongPtr` / `SetWindowLongPtr` or `GetClassLongPtr` / `SetClassLongPtr`, and the offsets are byte offsets even though each accessor reads or writes a `LONG_PTR`. On x64 that means pointer-sized alignment is not optional.

Use `GWLP_USERDATA` for one per-window pointer. Use `cbWndExtra` when a custom control wants several fixed slots without a separate map, or when compatibility with dialog/control frameworks makes property storage unattractive. Use `cbClsExtra` sparingly for immutable or shared class state; per-instance control data belongs in window extra bytes or a heap object referenced by them.

## References
- <https://stackoverflow.com/questions/13330225/cbclsextra-and-cbwndextra> - clarifies per-class versus per-window storage and byte-offset access.

## Connections
- `Atoms.md` sits at the same `RegisterClassEx` layer.
- `Custom Controls.md` is where `cbWndExtra` becomes useful for storing a control's state pointer.
