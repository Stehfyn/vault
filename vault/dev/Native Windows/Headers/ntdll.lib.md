`ntdll.lib` is the import library for `ntdll.dll`, which exposes the NT native API — the lowest user-mode layer of Windows, sitting below the Win32 subsystem. Functions are prefixed `Nt`/`Zw` (kernel-mode synonyms) or `Rtl` (runtime library helpers). Linking against `ntdll.lib` (with matching headers from the WDK or phnt) allows direct native API calls without going through `kernel32.dll`, useful for malware analysis, sandboxing, or low-level tooling.

```c
#include <windows.h>
#include <winternl.h>   // SYSTEM_INFORMATION_CLASS, NTSTATUS, etc.

// ntdll exports not declared in the public SDK — declare manually
typedef NTSTATUS (NTAPI *PNtQuerySystemInformation)(
    SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID                    SystemInformation,
    ULONG                    SystemInformationLength,
    PULONG                   ReturnLength);

// Resolve at runtime to avoid a hard ntdll.lib dependency
HMODULE hNtdll = GetModuleHandleW(L"ntdll.dll");
PNtQuerySystemInformation NtQuerySystemInformation =
    (PNtQuerySystemInformation)GetProcAddress(hNtdll,
                                              "NtQuerySystemInformation");

// Query basic system information (class 0)
SYSTEM_BASIC_INFORMATION sbi = {0};
ULONG retLen = 0;
NTSTATUS st = NtQuerySystemInformation(SystemBasicInformation,
                                       &sbi, sizeof(sbi), &retLen);
if (NT_SUCCESS(st))
    printf("Number of processors: %u\n", sbi.NumberOfProcessors);
```

## References

- <https://github.com/DissectMalware/WinNativeIO>
- <https://learn.microsoft.com/en-us/windows/win32/api/winternl/>
