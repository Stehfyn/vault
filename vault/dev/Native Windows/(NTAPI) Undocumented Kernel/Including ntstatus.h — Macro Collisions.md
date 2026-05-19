# Including ntstatus.h - Macro Collisions

`ntstatus.h` is the authoritative status-code header, but `windows.h` commonly pulls in `winerror.h` and may define overlapping status names through `WIN32_NO_STATUS` conventions. The practical rule is to control include order deliberately: suppress status definitions while including broad Win32 headers, then include `ntstatus.h` when NTSTATUS constants are actually needed.

This matters because native calls return `NTSTATUS`, not `GetLastError` values. Treating the two as interchangeable hides failures and breaks diagnostics. Convert only at the boundary, usually with `RtlNtStatusToDosError`, and keep native code paths speaking native status codes internally.

## Connections
- `ntstatus.h - NTSTATUS Value Definitions` covers the meaning of the codes.
- `NtCreateUserProcess` and `Process Dump Tools` both need correct NTSTATUS handling when using native APIs underneath Win32 wrappers.

## References
- Windows SDK/WDK `ntstatus.h`
