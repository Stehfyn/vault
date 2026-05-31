# VxKex - Win7 API Extension Shim

VxKex is a per-process compatibility layer for running applications that import APIs newer than Windows 7. Its strength is containment: instead of replacing system DLLs globally, it uses shim registration/loader indirection so selected executables see compatibility implementations for missing functions.

This is the clean middle ground between `YY-Thunks` and `OneCoreAPI`. Static thunks require rebuilding the application, OneCoreAPI changes the OS surface globally, and VxKex tries to make the loader lie only for marked processes. The hard part is not adding one export; it is matching enough behavior that modern Electron, UCRT, or .NET-era applications get past startup and keep working.

## Source Code Reading

The `i486/VxKex` repository is organized around setup/registration, common headers, extended DLLs, and tests.

Files and areas read:
- `00-Documentation/VxKex Registry Keys (Legacy).txt`
- `00-Documentation/Notes on IFEO.txt`
- `00-Common Headers/KexComm.h`
- `00-Common Headers/KxBase.h`
- `00-Common Headers/KxUser.h`
- `KexSetup/prereq.c`
- `KexSetup/perform.c`
- `KexSetup/util.c`
- `01-Extended DLLs/KxBase/*.c`
- `01-Extended DLLs/KxUser/*.c`
- `01-Extended DLLs/KxCrt/forwards.c`
- `CpiwBypa/dllmain.c`

The source shape is not "one magic DLL." It is:

```text
setup/configuration
  -> registry/IFEO-style process selection
  -> install extended DLLs and helper components
  -> scheduled-task/helper elevation for configuration

selected process startup
  -> compatibility loader path brings VxKex components into process
  -> extended DLLs expose missing exports
  -> some APIs forward to native Windows 7 functions
  -> some APIs are behavioral reimplementations or explicit stubs
```

Concrete examples from source:
- `KexSetup/prereq.c` probes required host functions with `GetProcAddress` and tests DXGI availability with `LoadLibrary(L"dxgi.dll")`.
- `01-Extended DLLs/KxCrt/forwards.c` is generated forwarding glue against `msvcrt.dll`; it is export-surface work, not application logic.
- `01-Extended DLLs/KxDx/dcmpstub.c` logs unsupported DirectComposition/DXGI-style functions rather than pretending full behavior exists.
- `CpiwBypa/dllmain.c` loads `KexDll.dll` from the system directory and resolves `KexPatchCpiwSubsystemVersionCheck`, showing that some compatibility work happens at process-load time.

Claim -> source/probe -> interpretation:
- Claim: "VxKex makes Windows 7 support newer apps."
- Source/probe: inspect the target app's imports with `dumpbin /imports`, map missing exports to VxKex extended DLL exports, then run a behavioral probe for each API.
- Interpretation: import satisfaction is only the first gate. A stub or partial implementation can move failure from loader time to runtime.

## Compatibility Boundary

The failure often happens before user code runs: the PE import table names a DLL/export that Windows 7 cannot resolve. VxKex-style shimming changes that per-process loader/runtime surface; it is not equivalent to setting `_WIN32_WINNT` lower or adding a manifest.

```text
source target     -> sdkddkver.h gates declarations
binary imports    -> PE loader resolves DLL/export/API-set names
runtime behavior  -> shim implements missing call semantics closely enough
```

## Experiment Harness

Build a tiny binary that hard-imports one API absent on the target OS, then test three variants: hard import, dynamic probe, shimmed process.

```c
// hard-import variant: proves loader-time failure.
int main(void) {
    return CompareObjectHandles(GetCurrentProcess(), GetCurrentProcess()) ? 0 : 1;
}
```

```powershell
dumpbin /imports probe.exe
.\probe.exe
.\probe_dynamic.exe
```

Signal: hard-import binary fails before `main` on an OS missing the export; dynamic probe reaches fallback code; shimmed process starts only if the layer supplies both the export and compatible behavior. Failure interpretation: "process starts" only proves import satisfaction. Add a behavioral assertion for every shimmed API before calling the compatibility layer correct.

## Discussion Claim Verification

Claim: "VxKex makes a newer app compatible with Windows 7."

Why it matters for new code: compatibility has at least three gates: the PE loader must find every import, the shim must implement behavior closely enough, and the rest of the app must not rely on newer system side effects. Import satisfaction alone is a weak success signal.

How to verify:

```powershell
dumpbin /imports target.exe > imports.txt
dumpbin /dependents target.exe
where target.exe
.\api_behavior_probe.exe
```

Minimal code/pseudocode:

```text
for each missing import:
  Does the shim export the name/ordinal?
  Does a minimal behavioral probe pass?
  Does the real target exercise only the supported subset?
```

Interpretation: VxKex source verifies a per-process export/behavior strategy. Unsupported claim nullified: "if the app launches, compatibility is solved." Launch proves only that the first loader gate was crossed. Runtime probes decide whether the shimmed API is functionally adequate.

## Connections

- `sdkddkver.h` is the compile-time version gate; VxKex is a deployment-time answer when the binary already imports newer APIs.
- `ntdll.lib` and PE import notes explain why hard imports fail before `main` or `WinMain`.
- `App Compat Cache` is a testing route when shim registration changes appear stale.
- `OneCoreAPI` is the system-wide contrast; `MSIX Package Support Framework` is the packaged-process compatibility contrast.

## References
- <https://github.com/i486/VxKex>
