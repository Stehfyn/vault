# winnt.h

The foundational NT contract pulled in by `<windows.h>`, but not just a bag of typedefs. `winnt.h` defines the ABI vocabulary that user mode, kernel mode, COM, RPC, PE loading, security descriptors, and exception handling all share: primitive aliases (`DWORD`, `HANDLE`, `WCHAR`), calling conventions, access masks, SIDs/ACLs, `NTSTATUS`, `UNICODE_STRING`, `LIST_ENTRY`, `RTL_CRITICAL_SECTION`, PE headers, unwind metadata, and architecture feature macros. Because it sits below almost every other SDK header, small preprocessor choices made before including it (`UNICODE`, `_WIN32_WINNT`, `STRICT`, packing) leak everywhere.

## ABI Vocabulary

The file is the connective tissue between headers, runtime, loader, and native APIs. These shapes recur throughout the assigned topics: `UNICODE_STRING` feeds `RtlCreateProcessParametersEx`; `ACCESS_MASK` drives registry/process/section handles; `IMAGE_NT_HEADERS` is the PE loader contract; calling-convention macros decide the binary call boundary.

```c
typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef DWORD ACCESS_MASK;

typedef struct _IMAGE_DOS_HEADER { WORD e_magic; LONG e_lfanew; } IMAGE_DOS_HEADER;
```

Connections: `ntdef.h`, `ntstatus.h`, `rtlsupportapi.h`, and the NTAPI notes are the sharper low-level slices; `sdkddkver.h` controls which declarations `winnt.h` and its dependents expose.

## Experiment Harness

Catch ABI drift at compile time. Add static assertions for structure sizes, packing-sensitive offsets, and character-mode assumptions in every low-level probe project.

```c
#include <windows.h>
#include <winternl.h>
static_assert(sizeof(void*) == sizeof(HANDLE), "unexpected handle size");
static_assert(FIELD_OFFSET(UNICODE_STRING, Buffer) % sizeof(void*) == 0, "bad packing");
#ifdef UNICODE
static_assert(sizeof(TCHAR) == sizeof(wchar_t), "UNICODE mismatch");
#endif
```

Signal: the harness fails at build time when `/Zp`, `UNICODE`, architecture, or SDK include order changes the ABI assumptions. Failure interpretation: do not patch the assertion away; find the compiler flag or preprocessor definition that changed the Windows contract your code is compiling against.

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/winnt/>
