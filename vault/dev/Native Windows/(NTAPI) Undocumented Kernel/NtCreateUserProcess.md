# NtCreateUserProcess

`NtCreateUserProcess` is the native user-process creation syscall behind the modern Win32 process stack. It accepts native object attributes, process/thread access masks, creation flags, process parameters, creation state, and attribute lists that describe image name, parent process, mitigation policy, handle inheritance, and related metadata. Most code should call `CreateProcessW`; this entry is for understanding what the wrapper prepares.

The Capt. Meelo write-up matters because it maps the undocumented structures and attributes that are otherwise scattered across phnt, ReactOS, and reverse-engineering notes. The important caution is structural correctness: a call can fail for reasons that look mysterious unless `PS_CREATE_INFO.State`, NT path normalization, process parameters, and attribute sizes are exactly what the kernel expects.

## Native Call Shape

This is the compact boundary that `CreateProcessW` normally hides. The hard inputs are not the handles; they are the pre-normalized NT path, `RTL_USER_PROCESS_PARAMETERS`, `PS_CREATE_INFO`, and correctly-sized attribute list.

```c
NTSTATUS st = NtCreateUserProcess(&process, &thread,
    PROCESS_ALL_ACCESS, THREAD_ALL_ACCESS,
    NULL, NULL,
    PROCESS_CREATE_FLAGS_INHERIT_HANDLES,
    THREAD_CREATE_FLAGS_CREATE_SUSPENDED,
    params, &createInfo, attrList);
```

Route: `RtlCreateProcessParametersEx` -> `RTL_USER_PROCESS_PARAMETERS` -> `PS_CREATE_INFO` / `PS_ATTRIBUTE_LIST` -> `NtCreateUserProcess` -> returned process/thread handles. Failures should be decoded as `NTSTATUS`, not `GetLastError`.

## Source Code Reading

The practical declarations come from `phnt/ntpsapi.h` and `phnt/ntrtl.h`.

Files read:
- `phnt/ntpsapi.h`
- `phnt/ntrtl.h`
- `phnt/ntstatus.h`
- Capt. Meelo's `NtCreateUserProcess` write-up linked below.

`ntpsapi.h` makes the function's shape precise:

```text
NtCreateUserProcess(
  out process handle,
  out thread handle,
  process desired access,
  thread desired access,
  optional process/thread OBJECT_ATTRIBUTES,
  PROCESS_CREATE_FLAGS_*,
  THREAD_CREATE_FLAGS_*,
  RTL_USER_PROCESS_PARAMETERS*,
  PS_CREATE_INFO*,
  PS_ATTRIBUTE_LIST*
)
```

The creation state is a structure protocol, not a bag of arguments. `PS_CREATE_INFO.Size` and `State` must be initialized correctly; `PS_ATTRIBUTE_LIST.TotalLength` must match the number of attributes actually supplied; image path attributes must agree with the process parameters. The most productive code to write is a differential launcher, not a one-off syscall demo.

Claim -> source/probe -> interpretation:
- Claim: "Calling `NtCreateUserProcess` is just lower-level `CreateProcessW`."
- Source/probe: launch the same child via `CreateProcessW` and via `RtlCreateProcessParametersEx` + `NtCreateUserProcess`; compare child command line, environment, current directory, inherited handles, parent PID, and raw `NTSTATUS`.
- Interpretation: the native call is the lower layer, but `CreateProcessW` performs path normalization, parameter construction, attribute setup, handle policy, and Win32 error translation. Skipping it moves that code into your program.

## Experiment Harness

Keep the native call harness differential: one `CreateProcessW` launch and one `NtCreateUserProcess` launch with the same image, command line, current directory, and environment. The child prints its own launch context; the parent logs raw `NTSTATUS`.

```text
control: CreateProcessW(commandLine, env, cwd)
native:  RtlCreateProcessParametersEx -> NtCreateUserProcess
measure: child GetCommandLineW/env/cwd + parent process/thread handles + NTSTATUS
```

Signal: matching child context and live process/thread handles. Failure interpretation: `STATUS_OBJECT_NAME_NOT_FOUND` points at NT path normalization; parameter-related failures point at `RTL_USER_PROCESS_PARAMETERS`; attribute-list failures point at size/count/layout. Undocumented/inferred area: `PS_CREATE_INFO`, `PS_ATTRIBUTE_LIST`, and many flags are not first-party stable contracts; phnt/ReactOS/blog samples are implementation guides, not compatibility guarantees.

## Discussion Claim Verification

Claim: "`NtCreateUserProcess` is a cleaner `CreateProcessW` for advanced callers."

Why it matters for new code: the native call is not cleaner unless the program needs native-only attributes and is prepared to own every wrapper responsibility. Most bugs are not in the syscall; they are in path normalization, parameter construction, attribute sizing, status decoding, and handle inheritance assumptions.

How to verify:

```powershell
dumpbin /imports native_launcher.exe | findstr /i "ntdll kernel32"
windbg -o native_launcher.exe
!handle
```

Minimal code/pseudocode:

```text
control:
  CreateProcessW(exe, cmd, inheritHandles, env, cwd)
native:
  RtlInitUnicodeString(ntImage)
  RtlCreateProcessParametersEx(...)
  init PS_CREATE_INFO.Size/State
  init PS_ATTRIBUTE_LIST.TotalLength
  NtCreateUserProcess(...)
child:
  print GetCommandLineW, cwd, selected env, inherited handle test
```

Interpretation: the Capt. Meelo/native-header material is verified when the native path matches the Win32 control for launch context and produces expected `NTSTATUS` values on deliberate failure. Unsupported claim nullified: "calling the syscall avoids complexity." It moves complexity from `kernel32` into your code.

## Connections
- `RTL_USER_PROCESS_PARAMETERS` explains the command line, image path, environment, current directory, and standard handles supplied to the new process.
- `phnt` is the practical source for declarations; `ntstatus.h` is needed for reliable diagnostics.
- `HandleApi.h` covers the Win32-supported handle duplication path when process startup needs selected inherited handles.
- `Process Hollowing (RunPE)` is the PE/process-state contrast: it starts with process creation and then mutates the image assumptions.

## References
- https://captmeelo.com/redteam/maldev/2022/05/10/ntcreateuserprocess.html
