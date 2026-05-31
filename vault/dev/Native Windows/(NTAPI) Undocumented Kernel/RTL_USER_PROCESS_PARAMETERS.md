# RTL_USER_PROCESS_PARAMETERS

`RTL_USER_PROCESS_PARAMETERS` is the native structure that carries a process's user-mode launch context: image path, command line, current directory, DLL search path, environment block, window flags, standard handles, console state, and related process-start metadata. It lives under the PEB and is normally built by `RtlCreateProcessParametersEx` for `CreateProcessW` or `NtCreateUserProcess`.

The fields are deceptively simple because they are mostly counted strings and pointers, but correctness depends on normalization, allocation layout, environment encoding, and whether pointers are valid in the address space where the parameters will be consumed. That is why hand-built examples often fail while wrapper-created parameters work. NTInternals is useful as a historical field guide; phnt and live debugger inspection are better for modern layouts.

The unrelated `FsRtlIsNameInExpression` reference that had been parked here belongs to filesystem-filter pattern matching, not process parameters. If retained, it should become its own file under a filesystem or kernel-driver section because it does not explain `RTL_USER_PROCESS_PARAMETERS`.

## Builder Shape

The structure is normally created by `RtlCreateProcessParametersEx`, not stack-initialized. The process image path is a native counted string, while the command line remains the user-visible command line that later CRT startup may parse into `argv`.

```c
UNICODE_STRING image;
RtlInitUnicodeString(&image, L"\\??\\C:\\Tools\\app.exe");

PRTL_USER_PROCESS_PARAMETERS params = NULL;
NTSTATUS st = RtlCreateProcessParametersEx(&params,
    &image, NULL, NULL,
    &commandLine, environment,
    NULL, NULL, NULL, NULL,
    RTL_USER_PROCESS_PARAMETERS_NORMALIZED);
```

Route: `processenv.h` exposes the Win32 view (`GetCommandLineW`, environment strings, current directory); this structure is the PEB-native storage backing that launch context.

## Source Code Reading

The phnt headers turn this from a folklore structure into a source-auditable launch object.

Files read:
- `phnt/ntpebteb.h`
- `phnt/ntrtl.h`
- Microsoft `winternl.h` documentation for the public subset.

The useful field route is:

```text
TEB -> ProcessEnvironmentBlock
PEB -> ProcessParameters
RTL_USER_PROCESS_PARAMETERS
  -> ImagePathName
  -> CommandLine
  -> CurrentDirectory
  -> DllPath
  -> Environment
  -> standard handles / window flags / console metadata
```

`ntrtl.h` shows the supported construction/destruction route in native terms: initialize counted strings with `RtlInitUnicodeString`, create the block with `RtlCreateProcessParametersEx`, pass the resulting pointer to native process creation, and destroy it with `RtlDestroyProcessParameters` when the creator owns it.

Claim -> source/probe -> interpretation:
- Claim: "The command line is just `argv`."
- Source/probe: child prints `GetCommandLineW`; CRT child prints `argv`; native launcher varies quotes, current directory, and environment block.
- Interpretation: `RTL_USER_PROCESS_PARAMETERS.CommandLine` stores the raw counted command line. `argv` is a CRT interpretation layered on top, so no-CRT and native-launch code must own quoting and parsing explicitly.

## Experiment Harness

Use `CreateProcessW` as the control, then inspect the child process's self-reported values. Do not start with remote PEB parsing; first prove which launch inputs survive the documented wrapper.

```powershell
.\param_echo.exe --sentinel "two words"
set X_PARAM_PROBE=abc
.\launcher.exe ".\param_echo.exe --sentinel `"two words`""
```

Probe output should include `GetCommandLineW()`, current directory, selected environment variables, and inherited standard-handle validity. Signal: byte-for-byte command line, expected current directory, and environment presence. Failure interpretation: if `CreateProcessW` control differs from the native path, the bug is usually quoting, environment-block termination, current-directory normalization, or handle inheritance, not the syscall itself.

Undocumented/inferred extension: remote PEB walking and full `RTL_USER_PROCESS_PARAMETERS` layout beyond Microsoft-documented `ImagePathName` and `CommandLine` depend on internal fields. Verify with symbols/debugger on the target build before treating offsets as stable.

## Discussion Claim Verification

Claim: "`RTL_USER_PROCESS_PARAMETERS` is just where Windows stores argv."

Why it matters for new code: `argv` is not a Windows kernel or loader concept. It is a CRT parse of the raw command line. Native launchers, no-CRT tools, and process-inspection code must distinguish raw counted strings from C runtime interpretation.

How to verify:

```powershell
cl /nologo param_echo.c
.\param_echo.exe a "b c" "\"quoted\""
windbg -o .\param_echo.exe
dt ntdll!_PEB @$peb
dt ntdll!_RTL_USER_PROCESS_PARAMETERS poi(@$peb+0x20)
```

Minimal code/pseudocode:

```c
wprintf(L"raw: %ls\n", GetCommandLineW());
int argc = 0;
LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
for (int i = 0; i != argc; ++i) wprintf(L"argv[%d]=%ls\n", i, argv[i]);
```

Interpretation: Microsoft documents only a subset; phnt and debugger symbols fill in the practical layout. Unsupported claim nullified: "the process parameters structure gives you argv." It gives the raw command line and launch context; `argv` is an interpretation layered above it.

## Connections
- `NtCreateUserProcess` consumes this structure during native process creation.
- `phnt` supplies current public definitions for the PEB, process parameters, and related native structures.
- `No-CRT Win32` uses this route indirectly: without CRT startup, command-line and environment parsing are your responsibility.

## References
- http://undocumented.ntinternals.net/UserMode/Structures/RTL_USER_PROCESS_PARAMETERS.html
- https://undocumented.ntinternals.net/
- <https://learn.microsoft.com/en-us/windows/win32/api/Winternl/ns-winternl-rtl_user_process_parameters>
