# ntdef.h - Core NT Types Header

`ntdef.h` defines the vocabulary that native Windows APIs speak: counted Unicode strings, object attributes, client IDs, IO status blocks, access masks, NTSTATUS types, and alignment/annotation helpers. These types reveal the object-manager shape beneath Win32's friendlier strings, handles, and BOOL/error-code conventions.

The header is foundational but intentionally incomplete for undocumented work. For serious NTAPI exploration, pair it with phnt or WDK headers rather than inventing partial structure definitions from old blog posts. The cost of a wrong length field or packing assumption is often a misleading `STATUS_INVALID_PARAMETER`.

## Connections
- `Including ntdef.h` covers user-mode include strategy.
- `RTL_USER_PROCESS_PARAMETERS` and `NtCreateUserProcess` are concrete users of these native types.

## References
- Windows SDK/WDK `ntdef.h`
