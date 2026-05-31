# phnt - Process Hacker Native API Headers

phnt is the practical header set for user-mode native Windows work. It fills the gap between the public SDK's deliberately thin `winternl.h` and the real structures used by tools such as System Informer: process/thread information classes, system-information records, object-manager types, PEB/TEB layouts, loader structures, handle tables, and many `Nt*` declarations.

The reason it matters is maintenance. Native structures drift across Windows releases, and one-off typedefs copied from old articles are a common source of subtle bugs. phnt is not an official ABI guarantee, but it is one of the best maintained public maps of the territory.

## Source Code Reading

The `winsiderss/phnt` repository should be read by header domain, not alphabetically.

Files read:
- `ntpsapi.h`
- `ntpebteb.h`
- `ntrtl.h`
- `ntldr.h`
- `ntmmapi.h`
- `ntobapi.h`
- `ntimage.h`
- `ntstatus.h`

Concrete composition examples:
- `ntpsapi.h` declares `NtCreateUserProcess`, `PS_CREATE_INFO`, `PS_ATTRIBUTE_LIST`, `PROCESS_CREATE_FLAGS_*`, and `THREAD_CREATE_FLAGS_*`.
- `ntpebteb.h` defines modern `PEB` / `TEB` layouts, including `PEB.ProcessParameters`, `PEB.Ldr`, `PEB.ApiSetMap`, appcompat flags, and static assertions for selected Windows 11 offsets/sizes.
- `ntrtl.h` declares helpers such as `RtlInitUnicodeString`, `RtlCreateProcessParametersEx`, and `RtlDestroyProcessParameters`.
- `ntimage.h` mirrors loader-facing image structures used by PE parsing and native loader code.

Claim -> source/probe -> interpretation:
- Claim: "phnt makes undocumented APIs stable."
- Source/probe: compile the same native probe against phnt, then verify field offsets with public symbols or debugger inspection on the target Windows build.
- Interpretation: phnt improves declaration quality; it does not turn private structure layout into a Microsoft compatibility contract.

Actionable include rule: define the phnt mode/version intentionally before including the headers, keep SDK `winternl.h` collisions isolated, and treat every native structure access as build-targeted code, not generic Win32 API use.

## Discussion Claim Verification

Claim: "phnt definitions are authoritative enough to use like SDK headers."

Why it matters for new code: phnt is a high-quality map of private territory, not a Microsoft compatibility promise. Code that ships against native fields needs a version strategy and a debugger/symbol check, especially when accessing `PEB`, `TEB`, loader entries, process parameters, or native process attributes.

How to verify:

```powershell
cl /nologo /D_WIN32_WINNT=0x0A00 native_probe.c
dumpbin /imports native_probe.exe
windbg -o native_probe.exe
x ntdll!*RtlCreateProcessParametersEx*
dt ntdll!_PEB
dt ntdll!_RTL_USER_PROCESS_PARAMETERS
```

Minimal code/pseudocode:

```c
#include <phnt_windows.h>
#include <phnt.h>

static_assert(sizeof(UNICODE_STRING) == sizeof(USHORT) * 2 + sizeof(PWSTR),
              "unexpected packing");
```

Interpretation: a phnt-based compile verifies declaration consistency in your build. Public symbols or live debugger inspection verify the target build. Unsupported claim nullified: "phnt makes undocumented APIs stable." It makes them easier to call and audit.

## Connections
- System Informer is the main consumer and validation source for phnt.
- `NtCreateUserProcess`, `RTL_USER_PROCESS_PARAMETERS`, and process dump notes all become less fragile when based on phnt declarations.

## References
- <https://github.com/winsiderss/phnt>
