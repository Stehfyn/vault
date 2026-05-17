# NtCreateUserProcess

`NtCreateUserProcess` is the native API for creating processes, called internally by `CreateProcessW`. It takes `OBJECT_ATTRIBUTES` for the image path and `PS_CREATE_INFO` / `PS_ATTRIBUTE_LIST` for process attributes. Useful for creating processes that bypass some `CreateProcess` hooks, or for studying process creation internals.

```cpp
// Minimal process attribute list setup for NtCreateUserProcess
// (simplified — real usage requires correct PS_CREATE_INFO fields)
typedef NTSTATUS (NTAPI *NtCreateUserProcess_t)(
    PHANDLE hProcess, PHANDLE hThread,
    ACCESS_MASK processAccess, ACCESS_MASK threadAccess,
    POBJECT_ATTRIBUTES procAttr, POBJECT_ATTRIBUTES threadAttr,
    ULONG processFlags, ULONG threadFlags,
    PRTL_USER_PROCESS_PARAMETERS procParams,
    PVOID createInfo, PVOID attrList);

// Load at runtime — not in import lib
HMODULE ntdll = GetModuleHandleA("ntdll.dll");
auto NtCreateUserProcess = (NtCreateUserProcess_t)
    GetProcAddress(ntdll, "NtCreateUserProcess");
```

Key differences from CreateProcessW:
- `PS_ATTRIBUTE_PS_COMMAND_LINE` (0x60002) passes the command line
- `PS_ATTRIBUTE_IMAGE_NAME` (0x60000) specifies the NT path (`\\??\\C:\...`)
- `PS_CREATE_INFO.State` reflects creation outcome
- Process and thread handles must be closed manually

## References
- https://captmeelo.com/redteam/maldev/2022/05/10/ntcreateuserprocess.html
