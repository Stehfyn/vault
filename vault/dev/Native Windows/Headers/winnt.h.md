# winnt.h

The foundational NT contract pulled in by `<windows.h>`, but not just a bag of typedefs. `winnt.h` defines the ABI vocabulary that user mode, kernel mode, COM, RPC, PE loading, security descriptors, and exception handling all share: primitive aliases (`DWORD`, `HANDLE`, `WCHAR`), calling conventions, access masks, SIDs/ACLs, `NTSTATUS`, `UNICODE_STRING`, `LIST_ENTRY`, `RTL_CRITICAL_SECTION`, PE headers, unwind metadata, and architecture feature macros. Because it sits below almost every other SDK header, small preprocessor choices made before including it (`UNICODE`, `_WIN32_WINNT`, `STRICT`, packing) leak everywhere.

Connections: `ntdef.h`, `ntstatus.h`, `rtlsupportapi.h`, and the NTAPI notes are the sharper low-level slices; `sdkddkver.h` controls which declarations `winnt.h` and its dependents expose.

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/winnt/>
