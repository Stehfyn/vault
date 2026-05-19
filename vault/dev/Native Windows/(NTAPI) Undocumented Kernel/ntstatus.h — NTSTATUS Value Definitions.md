# ntstatus.h - NTSTATUS Value Definitions

`ntstatus.h` is the canonical list of `STATUS_*` values returned by native APIs and many kernel-mode routines. The important distinction is semantic: `NT_SUCCESS(status)` is not equivalent to `status == STATUS_SUCCESS`, because informational and warning values can have different high-bit meanings.

Native-code diagnostics are much cleaner when status values stay native until the Win32 boundary. Convert with `RtlNtStatusToDosError` only when reporting through APIs that expect `GetLastError` semantics. This is especially important in notes around `NtCreateUserProcess`, process enumeration, and driver IOCTLs, where a single collapsed failure message destroys the useful signal.

## Connections
- `Including ntstatus.h` covers header-order pitfalls.
- `phnt` and System Informer use NTSTATUS-heavy APIs throughout.

## References
- Windows SDK/WDK `ntstatus.h`
