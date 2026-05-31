# DLL Build Config

For installer custom actions, shell extensions, and preload/shim DLLs, the build configuration is part of deployment correctness. `/LD` produces the DLL image, but CRT choice, target architecture, exports, manifests, delay-loads, and signing determine whether that DLL can actually load inside `msiexec.exe`, Explorer, a packaged app process, or an arbitrary AppInit target.

The x64 developer environment note matters because setup tooling frequently crosses architecture boundaries: a 32-bit custom action cannot load into 64-bit `msiexec`, and registry/file redirection changes what the action sees. Build both bitnesses intentionally instead of assuming "Any CPU" semantics exist for native DLLs.

## Export and Runtime Shape

A deployable native DLL needs a stable export contract before the installer or shim layer can use it. Keep custom-action exports C-shaped, bitness-specific, and explicit about CRT/heap ownership.

```c
extern "C" __declspec(dllexport)
UINT __stdcall MyCustomAction(MSIHANDLE hInstall);

// Build route: cl /LD action.cpp msi.lib /MD
```

## Discussion Claim Verification

Claim: "The DLL is built correctly if it exports the expected function."

Why it matters for new code: export presence is only one loader gate. Installer custom actions, shell extensions, PSF fixups, and preload/shim DLLs also need the right bitness, subsystem, CRT dependency, delay-load behavior, manifest, signing policy, and safe ownership boundary for any pointer or handle crossing the host process.

How to verify:

```powershell
cl /nologo /LD action.cpp msi.lib /MD /link /MAP:action.map
dumpbin /headers action.dll | findstr /i "machine DLL"
dumpbin /exports action.dll
dumpbin /dependents action.dll
dumpbin /imports action.dll
sigcheck -m action.dll
```

Minimal code/pseudocode:

```c
extern "C" __declspec(dllexport)
UINT __stdcall MyCustomAction(MSIHANDLE hInstall) {
    // Use MSI APIs for session state; do not return CRT-owned pointers.
    return ERROR_SUCCESS;
}
```

Interpretation: Microsoft DLL-build docs verify `/LD` and toolset selection, but not host compatibility. Unsupported claim nullified: "export exists, so the host can load it." The host must be able to resolve every dependency before it can call the export.

## Connections
- `CRT Linkage (MD MT DLL)` covers the runtime boundary a deployed DLL brings with it.
- `win32-ldpreload` and `MSIX Package Support Framework` are examples where DLL load behavior is the whole mechanism.
- `Msi.h` supplies the `MSIHANDLE` installer-session boundary for native custom actions.
- PE loader notes explain what `/LD`, exports, delay imports, and manifests become on disk.

## References
- <https://learn.microsoft.com/en-us/cpp/build/dlls-in-visual-cpp?view=msvc-170>
- <https://learn.microsoft.com/en-us/cpp/build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line?view=msvc-170>
