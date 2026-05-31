# NtTrace - Native API strace for Windows

NtTrace is closest to `strace` in spirit, but its implementation follows Windows realities: native calls are issued through `ntdll` stubs, argument layouts vary by call and build, and the result has to be decoded with a maintained signature database. Its value is seeing the `Nt*`/`Zw*` layer that high-level Win32 APIs collapse or hide.

The contrast with ETW tools is important. wtrace reconstructs behavior from providers; NtTrace observes calls made by a debuggee/instrumented process. ETW is usually better for system-wide, lower-overhead observation; NtTrace is better when the exact native call sequence and return statuses matter.

## Source Code Reading

The `rogerorr/NtTrace` codebase is a debugger-driven tracer, not an ETW consumer.

Files read:
- `src/NtTrace.cpp`
- `src/EntryPoint.cpp`
- `src/DebugDriver.cpp`
- `include/EntryPoint.h`
- `include/NtDllStruct.h`
- `include/SymbolEngine.h`
- `include/ReadPartialMemory.h`

`src/NtTrace.cpp` composes tracing around `TrapNtDebugger`:

```text
initialise:
  LoadLibrary("NTDLL")
  read NtTrace.cfg through EntryPoint::readEntryPoints
  load target DLL symbols if tracing a DLL other than ntdll
  build entry-point map

debug loop:
  wait for debug events
  on breakpoint:
    GetThreadContext
    if pre-save trap: read arguments before call
    if return trap: read NTSTATUS from EAX/RAX
    print decoded arguments/return status
    adjust EIP/RIP/ESP/RSP when simulating return/jump traps
    SetThreadContext
```

This explains the tool's unique value: it can report the exact native call and return code for a debugged process because it is manipulating breakpoints and thread context. It also explains the limitation: it needs debugger authority over the target and a maintained signature/config database.

Claim -> source/probe -> interpretation:
- Claim: "NtTrace is Windows strace."
- Source/probe: run NtTrace on a tiny program that calls `CreateFileW`, then compare observed `NtCreateFile` entries against an ETW file I/O trace.
- Interpretation: useful analogy, not implementation identity. NtTrace sees trapped entry points in a debuggee; ETW sees provider events system-wide with different payloads and overhead.

## Connections
- Pair with `phnt` for structure and syscall declarations.
- Pair with `wtrace` to compare call tracing against provider-based behavior tracing.

## References
- <https://github.com/rogerorr/NtTrace>
