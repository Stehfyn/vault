# OneCoreAPI - Vista API Backport to XP

OneCoreAPI is the aggressive end of Windows compatibility backporting: it adds large chunks of Vista-and-later API surface to XP/Server 2003 by replacing or extending system DLL behavior. That is more powerful than a per-process shim, and correspondingly more fragile because every process now sees the altered surface.

The editorial value is the export-compatibility problem. Modern applications fail on old Windows before main executes because imports such as condition variables, SRW locks, newer locale/string APIs, and shell helpers are missing. Compare OneCoreAPI with VxKex-style per-process forwarding and YY-Thunks static fallbacks to decide where the compatibility boundary lives.

Code contribution: study export forwarding/stubbing for APIs such as `InitializeConditionVariable`, `AcquireSRWLockExclusive`, newer NLS functions, and shell/kernel32 imports missing on XP.

## Source Code Reading

The `shorthorn-project/One-Core-API-Source` repository is large because it is closer to an OS-surface fork/backport than a small shim.

Files and areas read:
- `oca/wrappers/*_wrapper/*.c`
- `oca/wrappers/*_wrapper/*.spec`
- `oca/api-sets/*.spec`
- `dll/win32/kernel32_vista/sync.c`
- `dll/win32/kernel32/client/vista.c`
- `dll/win32/ntdll_vista/srw.c`
- `dll/win32/kernel32/client/version.c`
- `dll/ntdll/rtl/version.c`

The source illustrates three compatibility strategies:
1. API-set/spec surface: `.spec` files name exports so the loader can resolve imports.
2. Thin wrappers: `kernel32_vista/sync.c` maps Vista-era public functions such as `InitializeConditionVariable`, `AcquireSRWLockExclusive`, and `WakeConditionVariable` down to `Rtl*` primitives.
3. Behavioral implementations: `ntdll_vista/srw.c` implements SRW lock state with owned/contended/shared bits, wait blocks, and wake chains.

```text
InitializeConditionVariable
  -> RtlInitializeConditionVariable

AcquireSRWLockExclusive
  -> RtlAcquireSRWLockExclusive
     -> manipulate RTL_SRWLOCK bit state
     -> wait/wake through internal wait-block machinery when contended
```

Claim -> source/probe -> interpretation:
- Claim: "OneCoreAPI adds missing Vista+ functions to XP."
- Source/probe: check `.spec` exports, then run a concurrency stress test for condition variables/SRW locks, not just `GetProcAddress`.
- Interpretation: export presence proves loader compatibility. Correctness requires matching blocking, wake, timeout, fairness, and memory-order behavior closely enough for real apps.

## Import Compatibility Route

Use this note to separate three problems that get blurred together: satisfying the loader's import lookup, matching the API's observable side effects, and preserving old-OS invariants for every other process on the machine.

```text
missing export       -> loader failure before entry point
stubbed export       -> process starts, may fail on behavior
system DLL extension -> every process sees the changed surface
```

## Experiment Harness

Use the same missing-export probe as the VxKex test, but run it as a system-surface experiment: before install, after install, and after rollback.

```powershell
dumpbin /imports probe.exe
.\probe.exe
# install/backport layer in a VM snapshot only
.\probe.exe
```

Signal: loader failure becomes process start. The second signal must be behavioral: the API returns values compatible with Microsoft's contract, not merely a success code. Failure interpretation: if unrelated processes change behavior, the backport boundary is global and the test has escaped the original app.

## Discussion Claim Verification

Claim: "OneCoreAPI adds Vista+ APIs to XP."

Why it matters for new code: the phrase compresses two different claims. Export presence is a loader claim; correct synchronization, filesystem, NLS, shell, and runtime behavior is a semantic claim. The latter is what decides whether an application is safe to run.

How to verify:

```powershell
dumpbin /exports kernel32.dll | findstr /i "ConditionVariable SRW"
dumpbin /imports target.exe > target.imports.txt
.\sync_semantics_probe.exe
```

Minimal code/pseudocode:

```c
// Behavioral probe, not just GetProcAddress:
InitializeConditionVariable(&cv);
InitializeSRWLock(&lock);
AcquireSRWLockExclusive(&lock);
/* start waiter, release, WakeConditionVariable, assert exactly expected progress */
ReleaseSRWLockExclusive(&lock);
```

Interpretation: OneCoreAPI source can verify that an export is named and routed. It cannot by itself verify full Windows behavior for every caller. Unsupported claim nullified: "missing export fixed equals app compatibility fixed." Every backported API needs at least one behavioral probe matching the app's use.

Connections: `VxKex` scopes this problem per process; `sdkddkver.h` controls what source can name; PE import notes show what the binary demands at load time.

## References
- <https://github.com/shorthorn-project/One-Core-API-Source>
