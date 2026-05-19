# SyscallHook - Win10 20H1 Syscall Interceptor

SyscallHook is a version-specific syscall-interception experiment. Its value is as a warning label: syscall tables, stubs, mitigations, PatchGuard expectations, and kernel layout details are build-sensitive, and what works on Windows 10 20H1 should not be generalized casually to other releases.

The research question is where interception occurs. User-mode hooks catch callers that use a hooked import or ntdll stub; ETW observes provider-emitted behavior; kernel syscall interception attempts to sit below both and therefore collides with platform integrity assumptions. Treat this as an example of the stability/security tradeoff around very low-level hooks.

## Connections
- NtTrace observes native calls without claiming to be a kernel syscall hook.
- HookLib and Kernel-Bridge provide adjacent infrastructure for native/kernel experiments.

Code contribution: analyze build-specific syscall stubs, `ntdll` call sites, SSDT/syscall-number assumptions, PatchGuard-sensitive state, and ETW alternatives.

## References
- <https://github.com/anzelesnik/SyscallHook>
