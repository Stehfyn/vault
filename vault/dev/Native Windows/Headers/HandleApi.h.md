# HandleApi.h

The handle-lifetime corner of `kernel32`: `CloseHandle`, `DuplicateHandle`, `GetHandleInformation`, `SetHandleInformation`, `CompareObjectHandles` (Win10+). `DuplicateHandle` is more interesting than it looks -- it can target a different process (you must have `PROCESS_DUP_HANDLE` on both ends), can drop or add access rights, and is the supported way to give a child process a specific handle without making every inheritable handle inheritable. `CompareObjectHandles` is the one and only way to ask "do these two HANDLEs refer to the same kernel object?" -- every other approach (kernel-object-pointer comparison via NtQuerySystemInformation, etc.) is unsupported. `HANDLE_FLAG_PROTECT_FROM_CLOSE` is a trap door: turn it on with `SetHandleInformation` and `CloseHandle` will succeed but the handle stays open, which produces some delightfully confusing leak hunts in production code that flips it accidentally.

## Duplication Shape

Use this when process creation, installer helpers, or diagnostics need one specific inherited object instead of ambient inheritable-handle leakage.

```c
HANDLE target = OpenProcess(PROCESS_DUP_HANDLE, FALSE, pid);
HANDLE copy = NULL;
BOOL ok = DuplicateHandle(GetCurrentProcess(), source,
                          target, &copy,
                          0, FALSE, DUPLICATE_SAME_ACCESS);
```

## Experiment Harness

Create a child with no inheritable handles, then pass exactly one event handle by duplication. The child calls `SetEvent`; the parent waits.

```text
parent: CreateEvent -> DuplicateHandle(... child process ...)
child:  receives numeric handle value -> SetEvent(handle)
measure: WaitForSingleObject(parentEvent, 1000)
```

Signal: wait succeeds only when the duplicated handle has `SYNCHRONIZE`/event rights and the child receives the correct value. Failure interpretation: inherited-handle bugs are usually ambient leakage, wrong target process, missing `PROCESS_DUP_HANDLE`, or treating a handle value as meaningful outside the process that owns it.

Connections: `NtCreateUserProcess` and `RTL_USER_PROCESS_PARAMETERS` are the lower-level process-start side; `AccessMask Decoder` explains why `PROCESS_DUP_HANDLE` is an object-specific right inside a generic `ACCESS_MASK`; `ProcessSnapshot.h` uses process handles as the authority boundary for capture.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/handleapi/>
