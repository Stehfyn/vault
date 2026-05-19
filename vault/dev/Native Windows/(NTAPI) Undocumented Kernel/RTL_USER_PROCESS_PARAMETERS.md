# RTL_USER_PROCESS_PARAMETERS

`RTL_USER_PROCESS_PARAMETERS` is the native structure that carries a process's user-mode launch context: image path, command line, current directory, DLL search path, environment block, window flags, standard handles, console state, and related process-start metadata. It lives under the PEB and is normally built by `RtlCreateProcessParametersEx` for `CreateProcessW` or `NtCreateUserProcess`.

The fields are deceptively simple because they are mostly counted strings and pointers, but correctness depends on normalization, allocation layout, environment encoding, and whether pointers are valid in the address space where the parameters will be consumed. That is why hand-built examples often fail while wrapper-created parameters work. NTInternals is useful as a historical field guide; phnt and live debugger inspection are better for modern layouts.

The unrelated `FsRtlIsNameInExpression` reference that had been parked here belongs to filesystem-filter pattern matching, not process parameters. If retained, it should become its own file under a filesystem or kernel-driver section because it does not explain `RTL_USER_PROCESS_PARAMETERS`.

## Connections
- `NtCreateUserProcess` consumes this structure during native process creation.
- `phnt` supplies current public definitions for the PEB, process parameters, and related native structures.

## References
- http://undocumented.ntinternals.net/UserMode/Structures/RTL_USER_PROCESS_PARAMETERS.html
- https://undocumented.ntinternals.net/
