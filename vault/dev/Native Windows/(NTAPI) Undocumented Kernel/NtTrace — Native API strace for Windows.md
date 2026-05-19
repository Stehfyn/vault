# NtTrace - Native API strace for Windows

NtTrace is closest to `strace` in spirit, but its implementation follows Windows realities: native calls are issued through `ntdll` stubs, argument layouts vary by call and build, and the result has to be decoded with a maintained signature database. Its value is seeing the `Nt*`/`Zw*` layer that high-level Win32 APIs collapse or hide.

The contrast with ETW tools is important. wtrace reconstructs behavior from providers; NtTrace observes calls made by a debuggee/instrumented process. ETW is usually better for system-wide, lower-overhead observation; NtTrace is better when the exact native call sequence and return statuses matter.

## Connections
- Pair with `phnt` for structure and syscall declarations.
- Pair with `wtrace` to compare call tracing against provider-based behavior tracing.

## References
- <https://github.com/rogerorr/NtTrace>
