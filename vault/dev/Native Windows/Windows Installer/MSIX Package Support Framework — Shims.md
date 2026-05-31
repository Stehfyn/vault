# MSIX Package Support Framework — Compatibility Shims

Microsoft's Package Support Framework is a compatibility shim layer for Win32 desktop apps repackaged as MSIX. It injects fixup DLLs into selected packaged processes and intercepts APIs such as file and registry access so code that expects writable install directories or HKLM state can survive inside the package/container model.

The `config.json` matters because PSF is precise only when scoped precisely. Broad redirection can hide real packaging bugs, while narrow redirection can let a legacy app fail only after deployment. This entry belongs beside installer topics because PSF is a packaging-time compatibility decision, not a general application architecture.

## Fixup Boundary

PSF is most useful when the old app's ABI is acceptable but its deployment assumptions are wrong: writes beside the EXE, HKLM mutation, fixed relative paths, or child-process launch assumptions. The fixup DLL must match the packaged process architecture and loader constraints.

```json
{
  "applications": [
    { "id": "App", "executable": "VFS/ProgramFilesX64/App/app.exe" }
  ],
  "processes": [
    { "executable": "app", "fixups": [ { "dll": "FileRedirectionFixup.dll" } ] }
  ]
}
```

## Source Code Reading

The `microsoft/MSIX-PackageSupportFramework` repository shows exactly what a phrase like "apply a fixup" expands into.

Files read:
- `PsfLauncher/main.cpp`
- `PsfRuntime/main.cpp`
- `PsfRuntime/Config.cpp`
- `PsfRuntime/CreateProcessHook.cpp`
- `PsfRuntime/PsfRuntime.def`
- `Detours/detours.cpp`

Runtime composition:

```text
PsfLauncher/main.cpp
  -> wWinMain
  -> PSFQueryCurrentAppLaunchConfig(true)
  -> read executable / arguments / workingDirectory / monitor config
  -> StartProcess(target app)

PsfRuntime/main.cpp
  -> load_json / PSFQueryCurrentExeConfig
  -> for each configured fixup:
       PackageRootPath / dll name
       LoadLibraryW(fixup dll)
       GetProcAddress("PSFInitialize")
       call PSFInitialize(config)
  -> remember PSFUninitialize for teardown
```

`PsfRuntime/CreateProcessHook.cpp` is where child-process behavior stops being hand-wavy. It detours `CreateProcessA/W`, starts the child suspended, asks Windows what executable actually launched, checks whether it is inside the package root or configured `inPackageContext`, then uses Detours update logic to inject `PsfRuntime` into the child when appropriate. It also has a special path for `rundll32.exe` through `PsfRunDll32.exe` / `PsfRunDll64.exe` so bitness and package visibility remain coherent.

```c
// Pseudocode from CreateProcessHook.cpp
CreateProcessFixup(args):
  convert configured command-line paths
  CreateProcessW(... CREATE_SUSPENDED ...)
  exePath = query child image path
  if exePath under PackageRootPath or inPackageContext:
      bitness = ProcessBitness(child)
      DetourUpdateProcessWithDll(child, psfRuntime32/64)
  ResumeThread(childMainThread)
```

Actionable PSF review checklist:
1. Does `config.json` match the process base name the runtime will query?
2. Is the fixup DLL name architecture-neutral or correctly suffixed as `32.dll` / `64.dll`?
3. Does the fixup export `PSFInitialize` and, if needed, `PSFUninitialize`?
4. For child processes, is the launched image actually inside the package path or explicitly allowed by `inPackageContext`?
5. Are failures visible through the PSF TraceLogging provider instead of only through app symptoms?

## Experiment Harness

Start with an app that writes beside its EXE. Package it without PSF, capture the failure, then add only file redirection and repeat.

```json
{
  "applications": [
    { "id": "App", "executable": "VFS/ProgramFilesX64/App/app.exe", "workingDirectory": "VFS/ProgramFilesX64/App/" }
  ],
  "processes": [
    {
      "executable": "app",
      "fixups": [
        { "dll": "FileRedirectionFixup.dll",
          "config": { "redirectedPaths": { "packageRelative": [ { "base": "VFS/ProgramFilesX64/App/", "patterns": [ ".*\\.log" ] } ] } } }
      ]
    }
  ]
}
```

Signal: ProcMon `ACCESS DENIED` before PSF; successful redirected write after PSF; package local-state file appears where the fixup sends it. Failure interpretation: unchanged denial means the process name, architecture, launcher ID, or pattern did not match; broad success with broad patterns may be masking a packaging bug rather than fixing it.

## Discussion Claim Verification

Claim: "PSF fixes legacy Win32 apps for MSIX."

Why it matters for new code: PSF is not a generic compatibility blanket. It is a configured runtime shim loaded into selected packaged processes. The code still needs exact process matching, bitness-correct fixup DLLs, exported initialization functions, and a narrow behavior hypothesis.

How to verify:

```powershell
makeappx unpack /p app.msix /d unpacked
Get-Content unpacked\config.json
procmon /BackingFile psf.pml
dumpbin /exports FileRedirectionFixup.dll
dumpbin /dependents PsfRuntime64.dll
```

Minimal code/pseudocode:

```text
claim: app fails because it writes beside the executable
control: package without PSF, capture ACCESS DENIED on exact path
test: add FileRedirectionFixup for only that path pattern
measure: redirected file appears; no broad unrelated redirection
```

Interpretation: Microsoft PSF docs and source verify the shim mechanism. Unsupported claim nullified: "PSF makes a legacy app packaged." PSF can repair selected file/registry/process assumptions; it does not fix missing OS APIs, broken manifests, wrong architecture, or arbitrary custom action behavior.

## Connections
- `Fileapifromapp.h` is the AppContainer-compatible file API surface PSF often works around.
- `AppX Package API` and `msix-packaging` handle package structure; PSF handles runtime behavior.
- `VxKex` is the older-OS analogue: both are per-process compatibility layers, but PSF targets packaged-app restrictions while VxKex targets missing OS exports.
- `App Compat Cache` is relevant when testing shim changes that appear not to take effect.

## References
- <https://github.com/microsoft/MSIX-PackageSupportFramework>
- <https://learn.microsoft.com/en-us/windows/msix/psf/package-support-framework-overview>
- <https://learn.microsoft.com/en-us/windows/msix/psf/package-support-framework>
- <https://learn.microsoft.com/en-us/windows/msix/psf/psf-filesystem-writepermission>
