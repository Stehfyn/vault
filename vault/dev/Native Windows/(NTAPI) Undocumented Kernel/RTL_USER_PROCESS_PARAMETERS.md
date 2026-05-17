# RTL_USER_PROCESS_PARAMETERS

Selected fields (from NTInternals):
```c
typedef struct _RTL_USER_PROCESS_PARAMETERS {
  ULONG MaximumLength;
  ULONG Length;
  ULONG Flags;
  ULONG DebugFlags;
  PVOID ConsoleHandle;
  HANDLE StdInputHandle;
  HANDLE StdOutputHandle;
  HANDLE StdErrorHandle;
  UNICODE_STRING CurrentDirectoryPath;
  UNICODE_STRING ImagePathName;
  UNICODE_STRING CommandLine;
  PVOID Environment;
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;
```

Notes: `MaximumLength` should be set before `RtlCreateProcessParameters`. `Flags` may include `PPF_NORMALIZED` (set by `RtlNormalizeProcessParams`). Documentation also notes the structure is located at address `0x20000` for processes created by `CreateProcess` (undocumented behavior).

Reference: http://undocumented.ntinternals.net/UserMode/Structures/RTL_USER_PROCESS_PARAMETERS.html

https://undocumented.ntinternals.net/
ntinternals.net catalogs undocumented NT APIs, structures, and their fields. Essential reference when working below the Win32 layer. Cross-reference with ReactOS and the Windows Research Kernel for field offsets.
```cpp
// Pattern for loading undocumented functions from ntdll
typedef NTSTATUS (NTAPI *NtQuerySystemInformation_t)(
    ULONG SystemInformationClass,
    PVOID SystemInformation,
    ULONG SystemInformationLength,
    PULONG ReturnLength);

static NtQuerySystemInformation_t pNtQSI = nullptr;
void InitNtApis() {
  HMODULE ntdll = GetModuleHandleA("ntdll.dll");
  pNtQSI = (NtQuerySystemInformation_t)
      GetProcAddress(ntdll, "NtQuerySystemInformation");
}
```

https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlisnameinexpression
FsRtlIsNameInExpression is the kernel-mode wildcard matcher used in file system drivers for path matching. Useful context for understanding how filesystem filters and redirectors match paths.
```cpp
// User-mode equivalent pattern for path matching reference
// (FsRtlIsNameInExpression is kernel-only — this shows the concept)
static bool WildMatch(const wchar_t* pat, const wchar_t* str) {
  if (*pat == L'\0') return *str == L'\0';
  if (*pat == L'*')  return WildMatch(pat+1, str) ||
                             (*str && WildMatch(pat, str+1));
  if (*pat == L'?')  return *str && WildMatch(pat+1, str+1);
  return towupper(*pat) == towupper(*str) && WildMatch(pat+1, str+1);
}
```
