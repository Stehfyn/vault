# ntdll.lib

Import library for `ntdll.dll`, the lowest stable user-mode DLL in the Windows process: system-call stubs (`Nt*`), runtime support (`Rtl*`), loader internals (`Ldr*`), heap helpers, exception/unwind machinery, and activation-context plumbing. Linking directly against `ntdll.lib` is different from dynamically probing `GetProcAddress`: it bakes an import-table dependency and assumes the target routine is exported by name on the target OS. That is fine for documented `Rtl*` helpers and WDK-level code, much riskier for undocumented `Nt*` or `Ldr*` routines whose structure contracts drift between builds.

Connections: `winternl.h` is the sanitized public view, `phnt` is the broader community header set, and `(NTAPI) Undocumented Kernel/NtCreateUserProcess.md` shows why skipping the Win32 wrapper means you inherit all the parameter-building work `kernel32` normally hides.

## References

- <https://github.com/DissectMalware/WinNativeIO>
- <https://learn.microsoft.com/en-us/windows/win32/api/winternl/>
