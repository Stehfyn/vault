# libvalinet - ExplorerPatcher Helpers

Header-only utility C shared across valinet projects, especially ExplorerPatcher. Its value is in the unglamorous mechanisms that make runtime shell patching maintainable: byte-pattern scanning for per-build offsets, small inline-hook helpers, resource/string utilities, registry-backed settings, and wrappers around common Win32 chores. It is not a general-purpose framework; it is support code for living inside Explorer's moving implementation.

Read it beside ExplorerPatcher, DWM/custom-frame notes, and shell-extension material. The through-line is practical version resilience: when Microsoft changes private shell code, a patcher survives by keeping signatures, hooks, feature flags, and rollback paths small and auditable.

Code contribution: the useful patterns are `GetProcAddress`/pattern-scan resolution, tiny hook wrappers, registry settings helpers, and rollback paths around private shell entry points.

## Source Shape

Source pass: `valinet/hooking/iatpatch.h` shows the import-table patching shape used by this family of helper code. The source walks PE import descriptors, finds a named DLL/function thunk, temporarily changes page protection, swaps the function pointer, restores protection, and releases the module reference.

```c
HMODULE module = NULL;
GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
                   (PCWSTR)baseModule, &module);

PIMAGE_IMPORT_DESCRIPTOR imports =
    ImageDirectoryEntryToDataEx(module, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT,
                                &size, NULL);

for (; imports->Name; ++imports) {
    if (_stricmp((char *)module + imports->Name, "target.dll") != 0) continue;
    for (PIMAGE_THUNK_DATA thunk = FirstThunk(module, imports); thunk->u1.Function; ++thunk) {
        if (ImportNameMatches(module, thunk, "FunctionName")) {
            VirtualProtect(&thunk->u1.Function, sizeof(void *), PAGE_READWRITE, &oldProtect);
            thunk->u1.Function = (uintptr_t)HookFunction;
            VirtualProtect(&thunk->u1.Function, sizeof(void *), oldProtect, &oldProtect);
        }
    }
}
```

Source pass: `valinet/hooking/exeinject.h` shows why this belongs near shell patching notes rather than general UI notes: it has explicit crash/reinject paths and remote-library cleanup. That is operational support code for living inside Explorer/DWM-era processes.

## Connections

- `Shell/Explorer Patcher (Win11 Shell Restore).md` is the primary consumer context.
- `Shell/DUI70 - Shell DirectUI Framework.md` is the private shell UI surface that often forces version-keyed patching.
- `Shell/Shell COM WinRT UI Connection Routes.md` keeps this in the runtime patching route, separate from supported Shell COM and WinRT activation routes.
- `sktoolslib - Stefan Kueng Win32 Utility Library.md` is the contrast: long-lived native utility helpers without the same private-shell hook emphasis.

## Experiment Harness

Goal: make patch viability measurable before any process write or hook install.

```cpp
auto base = GetModuleHandleW(L"explorerframe.dll");
auto ver = QueryFileVersion(base);
auto matches = DryRunPatternScan(base, ".text", signature);
printf("module=%p version=%ls matches=%zu first_rva=%08x\n",
       base, ver.c_str(), matches.size(), matches.empty() ? 0 : matches[0]);
```

Procedure: run as a read-only scanner in the current process or against a copied DLL file; do not call `WriteProcessMemory`, `VirtualProtect`, or hook installers.

Measured signal: module version, image timestamp, unique signature match count, candidate RVA, rollback path availability.

Failure interpretation: zero matches means build drift; multiple matches means signature is too weak; either result blocks patch code. Microsoft PE anchor: <https://learn.microsoft.com/en-us/windows/win32/debug/pe-format>.

## References
- <https://github.com/valinet/libvalinet> - reusable support library behind ExplorerPatcher-style shell patching.
