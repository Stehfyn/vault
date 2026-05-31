# ntdll.lib

Import library for `ntdll.dll`, the lowest stable user-mode DLL in the Windows process: system-call stubs (`Nt*`), runtime support (`Rtl*`), loader internals (`Ldr*`), heap helpers, exception/unwind machinery, and activation-context plumbing. Linking directly against `ntdll.lib` is different from dynamically probing `GetProcAddress`: it bakes an import-table dependency and assumes the target routine is exported by name on the target OS. That is fine for documented `Rtl*` helpers and WDK-level code, much riskier for undocumented `Nt*` or `Ldr*` routines whose structure contracts drift between builds.

## Import Boundary

Hard-linking a native export changes the PE import table; probing keeps the binary loadable when the export is missing. That distinction is the same deployment boundary discussed in `sdkddkver.h`, appcompat shims, and PE loader notes.

```c
HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
typedef LONG (NTAPI *RtlGetVersionFn)(PRTL_OSVERSIONINFOW);
RtlGetVersionFn RtlGetVersion_ =
    (RtlGetVersionFn)GetProcAddress(ntdll, "RtlGetVersion");
```

## Source Code Reading

The linked `DissectMalware/WinNativeIO` repository is a reminder that the source decision is not only "which function do I call?" but "do I encode the dependency in the PE import table?"

For defensive/runtime notes, read native-I/O code in three layers:
- declarations: SDK `winternl.h`, phnt headers, or local typedefs;
- binding: import library versus `GetProcAddress`;
- call contract: `NTSTATUS`, object attributes, counted strings, and handle rights.

Claim -> source/probe -> interpretation:
- Claim: "If a native export exists on my development machine, linking `ntdll.lib` is fine."
- Source/probe: build `hard.exe` with a hard native import and `dynamic.exe` with `GetProcAddress`; compare `dumpbin /imports`, then run both on the oldest supported VM.
- Interpretation: hard imports are loader obligations. Missing export means process load failure before your fallback code can run; dynamic binding lets the program report unsupported functionality.

## Experiment Harness

Build two probes for the same native routine: one linked against `ntdll.lib`, one resolved dynamically. Inspect imports and run on the oldest target VM.

```powershell
cl /nologo hard.c ntdll.lib
cl /nologo dynamic.c
dumpbin /imports hard.exe | findstr /i ntdll
dumpbin /imports dynamic.exe | findstr /i ntdll
```

Signal: the hard-linked binary has an import-table obligation; the dynamic binary reaches fallback code if the export is absent. Failure interpretation: a loader error before `main` is not a runtime bug in your code; it is a deployment contract encoded in the PE import table.

## Discussion Claim Verification

Claim: "Using `ntdll.lib` is equivalent to resolving the same routine with `GetProcAddress`."

Why it matters for new code: hard imports make the loader enforce availability before any fallback can run. Dynamic resolution lets a diagnostic tool start, report the missing function, and choose a documented path.

How to verify:

```powershell
cl /nologo hard.c ntdll.lib /link /MAP:hard.map
cl /nologo dynamic.c /link /MAP:dynamic.map
dumpbin /imports hard.exe | findstr /i ntdll
dumpbin /imports dynamic.exe | findstr /i ntdll
dumpbin /disasm hard.exe > hard.disasm.txt
```

Minimal code/pseudocode:

```c
HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
RtlGetVersionFn p = (RtlGetVersionFn)GetProcAddress(ntdll, "RtlGetVersion");
if (!p) {
    /* unsupported on this target; keep process alive */
}
```

Interpretation: the verified artifact is the import table. Nullify any forum claim that "the DLL is already loaded so linking is harmless." Already loaded is irrelevant; a missing named import still prevents process initialization.

Connections: `winternl.h` is the sanitized public view, `phnt` is the broader community header set, and `(NTAPI) Undocumented Kernel/NtCreateUserProcess.md` shows why skipping the Win32 wrapper means you inherit all the parameter-building work `kernel32` normally hides.

## References

- <https://github.com/DissectMalware/WinNativeIO>
- <https://learn.microsoft.com/en-us/windows/win32/api/winternl/>
