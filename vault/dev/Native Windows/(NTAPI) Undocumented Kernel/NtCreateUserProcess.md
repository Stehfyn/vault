# NtCreateUserProcess

`NtCreateUserProcess` is the native user-process creation syscall behind the modern Win32 process stack. It accepts native object attributes, process/thread access masks, creation flags, process parameters, creation state, and attribute lists that describe image name, parent process, mitigation policy, handle inheritance, and related metadata. Most code should call `CreateProcessW`; this entry is for understanding what the wrapper prepares.

The Capt. Meelo write-up matters because it maps the undocumented structures and attributes that are otherwise scattered across phnt, ReactOS, and reverse-engineering notes. The important caution is structural correctness: a call can fail for reasons that look mysterious unless `PS_CREATE_INFO.State`, NT path normalization, process parameters, and attribute sizes are exactly what the kernel expects.

## Connections
- `RTL_USER_PROCESS_PARAMETERS` explains the command line, image path, environment, current directory, and standard handles supplied to the new process.
- `phnt` is the practical source for declarations; `ntstatus.h` is needed for reliable diagnostics.

## References
- https://captmeelo.com/redteam/maldev/2022/05/10/ntcreateuserprocess.html
