# createprocess-survey

Survey of the Windows process-creation surface, from the modern syscall
`NtCreateUserProcess` down to the legacy `NtCreateProcessEx` path you
have to wire by hand, plus things `CreateProcess` cannot do at all:
fork, threadless processes, image-name spoofing, skipping the loader,
patching the IAT before any user code runs, and the launch-cursor.

Every parent in `src/NN_*.c` launches `test_target.exe`, which dumps
the entire `RTL_USER_PROCESS_PARAMETERS` block it received into a
`.marker` file. The build is flat (`build.ps1` globs `src\*.c`), so the
numbered prefix is the only organization. Targets (`test_target`,
`tiny_target`, `gui_target`, `gui_no_cursor`) are built from the same
folder and treated specially in `build.ps1:103-131`.

Vendored `phnt` headers under `vendor/phnt/` provide the undocumented
NT prototypes. `src/common.h` carries the shared helpers
(`Cps_DosToNtPath`, `Cps_BuildEnvBlock`, `Cps_MakeParamsFull`, the
`CPS_EXTRAS` fill that populates every optional STARTUPINFO-equivalent
field, and the `EXPECTED_CHILD_EXIT = 0x4D` sentinel that
`runtests.ps1` looks for).

---

## API ladder — the four ways to start a process

### `src/01_rtl_create_user_process.c` — `RtlCreateUserProcess`
The ten-argument flat NTDLL wrapper. Exercises every parameter:
NT image path, `ExtendedParameters` with NUMA node packed into the
HIWORD, a fully-populated `RTL_USER_PROCESS_PARAMETERS`, NULL-DACL
process/thread SDs, explicit parent = `NtCurrentProcess()`,
`InheritHandles = FALSE`, NULL DebugPort/TokenHandle. Builds the
parameters with `Cps_MakeParamsFull` so `WindowTitle`, `DesktopInfo`,
`ShellInfo`, position/size/fill, std handles, console flags, and the
post-19H1 `ProcessGroupId`/`DefaultThreadpoolThreadMaximum` fields are
all set — the marker proves which of them actually round-trip. Resumes
the suspended thread, waits, reads `ProcessBasicInformation.ExitStatus`
and asserts `== 0x4D`.

### `src/02_rtl_create_user_process_ex.c` — `RtlCreateUserProcessEx`
The Win10 RS2+ replacement. Same `RTL_USER_PROCESS_PARAMETERS`, but
the trailing four arguments of `RtlCreateUserProcess` are folded into
`RTL_USER_PROCESS_EXTENDED_PARAMETERS` and a `JobHandle` slot is added.
Creates a fresh job object with
`JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE`, passes it via `extp.JobHandle`,
then verifies with `QueryInformationJobObject(JobObjectBasicProcessIdList)`
that the child landed in the job (`NumberOfAssignedProcesses` should be
1).

### `src/03_nt_create_user_process.c` — `NtCreateUserProcess`
The actual syscall. Builds a 9-entry `PS_ATTRIBUTE_LIST`:
`PsAttributeImageName` (in, NT path bytes), `PsAttributeParentProcess`
(HANDLE inline in `Value`), `PsAttributeClientId` /
`PsAttributeImageInfo` / `PsAttributeTebAddress` (out receivers),
`PsAttributeMitigationOptions` (DEP_ENABLE bit set in `ULONG64`),
`PsAttributeChildProcessPolicy`, `PsAttributePriorityClass = 2`,
`PsAttributeErrorMode = SEM_NOGPFAULTERRORBOX`. Initializes a
`PS_CREATE_INFO` to `PsCreateInitialState` and decodes the
`PsCreateFailOn*` states on error (file-open, section-create,
EXE-format, IFEO-debugger rejection). Prints back the kernel-filled
TEB pointer, machine type, transfer address, `ProtectedProcess`, and
`ManifestAddress`.

### `src/04_nt_create_process_ex.c` — `NtCreateProcessEx`
The pre-Vista path. The kernel does almost nothing for you; you do
every step `NtCreateUserProcess` would have done:
`NtCreateFile(image)` → `NtCreateSection(SEC_IMAGE)` → `NtCreateProcessEx`
(creates an EPROCESS with no thread, empty PEB) →
`NtQuerySection(SectionImageInformation)` for the entry point →
`NtQueryInformationProcess(ProcessBasicInformation)` for the child PEB
→ build params + env in our address space → `RtlDeNormalizeProcessParams`
(turn string pointers into offsets so they survive the cross-process
copy) → `NtAllocateVirtualMemory` two regions in the child for the env
and the params block, `NtWriteVirtualMemory` both, patch the local
`params->Environment` to the remote env address before writing →
`NtWriteVirtualMemory` the params pointer into
`child.PEB->ProcessParameters` (`FIELD_OFFSET(PEB, ProcessParameters)`)
→ `NtCreateThreadEx(SUSPENDED)` with `StartRoutine = sii.TransferAddress`
(kernel automatically routes the first thread through
`LdrInitializeThunk`) → resume.

---

## Things `CreateProcess` simply cannot do

### `src/05_no_thread.c` — a fully-mapped process with zero threads
`NtCreateProcessEx` without ever calling `NtCreateThreadEx`. Result is
a real EPROCESS with ntdll mapped, image mapped, PEB allocated by the
kernel, but `ETHREAD count == 0`. Headlines:
`NtGetNextThread` immediately returns `STATUS_NO_MORE_ENTRIES`,
`NtQueryInformationProcess(ProcessHandleCount)` returns 0, and a walk
over `NtQueryVirtualMemory` (first 12 non-free regions) proves the
address space is genuinely populated. `NtTerminateProcess(STATUS_CANCELLED)`
to tear down. Always returns 0 — informational.

### `src/06_fork.c` — Unix-style `fork()` via `RtlCloneUserProcess`
A single ntdll call that returns *twice*: `STATUS_SUCCESS` in the
parent with `ProcessInformation` filled, `STATUS_PROCESS_CLONED (0x129)`
in the child where `ProcessInformation` contains the *parent's* identity.
The child confirms it saw the pre-fork sentinel
`0xDEADBEEF11223344` at the same virtual address, writes
`06_fork.child.marker` (note: absolute path computed *before* the
fork — `RtlCloneUserProcess` does not arrange a working cwd handle for
the child), and exits via `NtTerminateProcess(0x5A)` to skip DLL
detach handlers that would otherwise touch state still owned by the
parent. Marker path is computed pre-fork because cwd-relative opens
do not work post-clone.

### `src/07_image_name_spoof.c` — kernel maps A, PEB reports B
`NtCreateUserProcess` is the only path that decouples the *real* image
(`PsAttributeImageName` in the attribute list) from the *advertised*
image (`params->ImagePathName` and `params->CommandLine`). Maps
`test_target.exe` while telling user code it is
`C:\Windows\System32\notepad.exe`. The child marker shows both:
`ImagePathName` and `GetModuleFileNameW` agree on the lie (the loader
copies its main-module name from `PEB->ProcessParameters->ImagePathName`),
but `NtQueryInformationProcess(ProcessImageFileName)` and
`ProcessImageFileNameWin32` return the kernel's view from
`EPROCESS->SectionObject` — that one cannot be spoofed and is the
fingerprint of the trick.

### `src/08_skip_loader_init.c` — run a thread that bypasses `LdrInitializeThunk`
The only escape is `THREAD_CREATE_FLAGS_SKIP_LOADER_INIT (0x20)` on
`NtCreateThreadEx`. Spawns `tiny_target.exe` via
`NtCreateProcessEx`/`NtCreateSection(SEC_IMAGE)`, creates the thread
suspended at `sii.TransferAddress` with both `CREATE_SUSPENDED` and
`SKIP_LOADER_INIT`, resumes, sleeps 100 ms, suspends, then
`NtReadVirtualMemory` of the child's PEB to confirm:
`PEB->Ldr == NULL` (loader did not run),
`PEB->ProcessHeap == NULL` (no heap created),
`PEB->ImageBaseAddress != NULL` (kernel sets this during section map).
Also `NtGetContextThread` to show `RIP` sits at/near the image entry.
`tiny_target.exe` is `void my_entry(void) { for(;;) __nop(); }` —
`/NODEFAULTLIB`, no imports — so there is nothing for the loader to
do, which is the point.

---

## Fork patterns

### `src/09_fork_fanout.c` — 4-worker fan-out from one parent
Allocates a `WORK_ITEM[4]` on the parent heap with inputs 10, 20, 30,
40. Loops 4 times calling `RtlCloneUserProcess`; each child takes its
loop-variable-captured `worker_id`, dereferences the same parent-heap
pointer (proving COW copy of the address space), computes
`x*x + 17`, writes `09_fork.worker<i>.marker` and exits with the
result as exit code. Parent waits for all four, sums the exit codes,
asserts they equal `compute(10)+compute(20)+compute(30)+compute(40)`.

### `src/10_fork_snapshot.c` — suspended clone as a memory snapshot
`RtlCloneUserProcess(RTL_CLONE_PROCESS_FLAGS_CREATE_SUSPENDED)`. The
parent stuffs `0xCAFED00D ^ i` patterns into a 4096-byte heap blob,
clones suspended, then from the parent reads the child's memory at the
same virtual address via `NtReadVirtualMemory` and `memcmp`s — must be
byte-identical. Also dumps the suspended thread's `CONTEXT` (`Rip`,
`Rsp`, `Rbp`, `Rax`) and walks the first 10 non-free regions of the
child VM. Never resumes the child; `NtTerminateProcess(0)` to clean
up. Exit code 0 iff the bytes matched.

### `src/11_fork_survival.c` — what survives the clone
Surveys six categories of state across the fork boundary:
(1) CRT static `g_counter = 0xABCDEF` — should survive;
(2) heap allocation containing `"I-was-allocated-by-the-parent"` — should
survive;
(3) `TlsAlloc`/`TlsSetValue(0xDEADC0DE)` — should survive (the cloning
thread's TEB.TlsSlots is part of the cloned address space);
(4) `CRITICAL_SECTION` deliberately held by the parent across the fork
with no call to `RtlUpdateClonedCriticalSection` — child does
`TryEnterCriticalSection` with timeout 0 and reports `FALSE`, the
classic fork-with-locks deadlock fingerprint (a phantom owner that
never exists in the child);
(5) `CreateEventW(manual, signaled)` marked inheritable — child
`WaitForSingleObject(ev, 0)` returns `WAIT_OBJECT_0`;
(6) `PEB->NumberOfHeaps` (offset 0xE8) and `PEB->ProcessHeap` (0x30)
should match parent values exactly.
Child writes a report to `11_fork_survival.child.marker` and exits
0x77.

---

## The launch-feedback cursor (kernelbase's mouse hourglass)

### `src/12_no_cursor_compare.c` — three launches, side by side
Launches `gui_target.exe` three ways back-to-back, deleting the
shared `gui_target.marker` between each so you can read which dwFlags
the child saw:
**A.** `CreateProcessW` default — kernelbase!CreateProcessInternalW
arms `IDC_APPSTARTING` on the *launcher's* UI thread because the
child's subsystem is `WINDOWS_GUI` and dwFlags lacks
`STARTF_FORCEOFFFEEDBACK`. Cursor visible for up to 5s or until
`WaitForInputIdle` returns.
**B.** Same `CreateProcessW` but `si.dwFlags = STARTF_FORCEOFFFEEDBACK`.
No cursor.
**C.** `NtCreateUserProcess` — kernelbase never runs, so its
cursor-arm code path is unreachable. CSRSS still gets a `BasepCreateProcess`
notification, but the cursor lives in the launcher only. No cursor.
The summary at the end spells out which suppression paths exist
(STARTF flag, Nt* APIs, services with no UI thread, AppX/MSIX
activation via `IApplicationActivationManager`) and what is *not* a
solution (no PE bit, no manifest entry from the EXE side).

### `src/gui_no_cursor.c` — a COM-activation shim that turns the cursor off in *all* cases (including Explorer double-click)
NoCRT, custom-entry, ~448 LOC. Registers itself under HKCU as a
`LocalServer32` COM class and rewires `exefile\shell\open\command\DelegateExecute`
to its CLSID, so every `.exe` activation on the user account routes
through `rpcss` invoking `IExecuteCommand::Execute` on this process
instead of through `CreateProcessInternalW` on the launcher.
`ec_Execute` (the hot path) compares the selection's full path against
its own cached `g_my_path` with one `CompareStringOrdinal`: match →
own GUI; miss → forward via `CreateProcessW` with no STARTUPINFO
flags. Because `rpcss` is not a UI process, the feedback cursor is
never armed on the forwarded launch. Three modes parsed from
`GetCommandLineW`: `/unregister` (tear down HKCU keys),
`-Embedding` / `/Embedding` (rpcss launched us → `run_com_server` →
STA pump), anything else (first-run self-install + show GUI). Imports
limited to `kernel32`, `user32`, `ole32`, `advapi32`; supplies its own
`memcmp` via `#pragma function(memcmp)`. **Side effect: while
registered it hijacks every `.exe` double-click on the user account —
the `/unregister` mode and a `cmd /c "<exe>" /unregister` recovery
line are documented in the header.**

### `src/13_patch_iat.c` — IAT patch before any user code runs in the child
The race-free version of the classic
`CreateProcess(CREATE_SUSPENDED)+patch` trick. Spawns
`gui_target.exe` via `NtCreateUserProcess` with
`THREAD_CREATE_FLAGS_CREATE_SUSPENDED`, then:
1. read `PEB->ImageBaseAddress` from the child via `NtReadVirtualMemory`;
2. parse `IMAGE_DOS_HEADER` and `IMAGE_NT_HEADERS64` out of the child
to find `DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT]`;
3. walk import descriptors, match `USER32.dll` case-insensitively;
4. walk that descriptor's `OriginalFirstThunk` (Import Name Table) to
find `MessageBoxW` by string, record its slot index in the IAT;
5. `NtAllocateVirtualMemory` a page in the child, write the 6-byte
shellcode `B8 01 00 00 00 C3` (`mov eax,1 ; ret` — returns `IDOK`),
`NtProtectVirtualMemory` it to `PAGE_EXECUTE_READ`;
6. `NtProtectVirtualMemory` the IAT slot to RW,
`NtWriteVirtualMemory` the stub address into it, restore old protection;
7. resume.
The point of doing this through the Nt path rather than
`CreateProcess(CREATE_SUSPENDED)` is timing: by the time
`CreateProcess` returns, the kernel has already run loader init for
the main image's static imports and the IAT is bound. Here the image
is mapped but no user-mode code (loader or TLS callback) has executed
yet, so the patch is race-free. Verification: `gui_target` writes
`MessageBoxW returned=<n>` into its marker; success means `=1` with no
dialog drawn.

---

## Targets (launched by the experiments above)

### `src/test_target.c` — universal exit-code-`0x4D` audit child
The marker file `<CPS_TARGET_TAG>.marker` is what `runtests.ps1`
checks. Reads `PEB->ProcessParameters` directly via a manually-written
`CPS_PROCESS_PARAMETERS` layout (the `winternl.h` one is truncated)
and dumps every field as `key=value` lines so each parent can prove
what round-tripped. Includes both views of the image name — loader
view (`GetModuleFileNameW`) and kernel view
(`NtQueryInformationProcess(ProcessImageFileName=27,
ProcessImageFileNameWin32=43)`) — so `07_image_name_spoof`'s marker
can show the divergence. Mirrors the post-19H1 fields
(`EnvironmentSize`, `ProcessGroupId`, `LoaderThreads`,
`RedirectionDllName`, `HeapPartitionName`,
`DefaultThreadpoolThreadMaximum`, `HeapMemoryTypeMask`). Tag comes
from the `CPS_TARGET_TAG` env var the parent sets; falls back to
`untagged`. Exit code `0x4D`.

### `src/tiny_target.c` — a PE with no CRT, no imports, no anything
`/ENTRY:my_entry /NODEFAULTLIB /SUBSYSTEM:CONSOLE`. Entry is `for(;;)
__nop();`. Used exclusively by `08_skip_loader_init` because there is
nothing for the loader to do — if the SKIP_LOADER_INIT flag works,
the child sits in this loop with `PEB->Ldr == NULL` until the parent
suspends and terminates it.

### `src/gui_target.c` — `Subsystem = WINDOWS_GUI` test child for the cursor + IAT-patch experiments
`/SUBSYSTEM:WINDOWS`. Writes `gui_target.marker` with the
`STARTUPINFO.dwFlags` it received (so `12_no_cursor_compare` can show
which `STARTF_*` bits the launcher set), creates one visible window,
calls `MessageBoxW` exactly once (the IAT-patch target for `13`),
appends `MessageBoxW returned=<n>` to the marker, then pumps messages
for 3s — long enough for a human to observe whether the launch cursor
appeared next to the pointer — and exits.

---

## Build & run

```powershell
.\build.ps1            # cl every src\*.c into build\<name>.exe via vcvars64
.\build.ps1 -Clean     # wipe build/ first
.\runtests.ps1         # runs 01..04 only, checks exit==0 and marker exists
.\runtests.ps1 -Verbose
```

`runtests.ps1` automates exactly the four API-ladder experiments
because they share the `EXPECTED_CHILD_EXIT 0x4D` contract; the rest
(`05`+) are interactive / observational and must be eyeballed via
their markers or via watching the mouse pointer.

Per-source build quirks live in `build.ps1:103-131`:
- `tiny_target` → `/ENTRY:my_entry`, `-NoCRT`, `/NODEFAULTLIB`
- `gui_target` → `gdi32.lib`, `/SUBSYSTEM:WINDOWS`
- `gui_no_cursor` → `ole32+user32+advapi32+kernel32`, `/SUBSYSTEM:WINDOWS`,
  custom entry, fully `-NoCRT -NoDebug`, MERGE/OPT/LTCG/FIXED to keep
  it tight
- everything else → defaults (`ntdll`/`kernel32`/`user32`/`advapi32`,
  `/MT`, `/Zi`)
