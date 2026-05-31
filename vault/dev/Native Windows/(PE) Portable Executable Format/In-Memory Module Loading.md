# In-Memory Module Loading

MemoryModule is the classic benign reference for loading a PE-format DLL from a memory buffer instead of from a file path. It has to reproduce the loader's core jobs: map sections with the right permissions, apply base relocations, resolve imports, handle TLS, expose exports, and call initialization in the expected order.

The reason it belongs here is contrast. Windows' real loader updates `PEB->Ldr`, sends DLL notifications, applies policy, participates in ETW/image-load telemetry, and integrates with exception/unwind metadata. In-memory loaders often miss some of that behavior, which is why they are useful for studying loader contracts and why they leave different forensic artifacts.

## Loader Worklist

The source value is the call order. A memory loader has to recreate enough of `LdrLoadDll`'s observable contract for the target DLL to survive, especially when the DLL uses TLS, delay imports, C++ exceptions, or exported callbacks.

```c
dos = (IMAGE_DOS_HEADER*)base;
nt  = (IMAGE_NT_HEADERS*)((BYTE*)base + dos->e_lfanew);
// reserve SizeOfImage, copy headers/sections
// apply IMAGE_BASE_RELOCATION blocks
// walk IMAGE_IMPORT_DESCRIPTOR and resolve thunks
// run TLS callbacks, then call AddressOfEntryPoint as DllMain
```

## Source Code Reading

The `fancycode/MemoryModule` implementation is a clean way to replace vague loader words with actual jobs.

Files read:
- `MemoryModule.c`
- `MemoryModule.h`
- `example/DllLoader/DllLoader.cpp`
- `example/SampleDLL/SampleDLL.cpp`
- `tests/TestSuite.c`

Core routine composition in `MemoryModule.c`:

```text
MemoryLoadLibrary
  -> MemoryLoadLibraryEx(default alloc/free/load/GetProcAddress callbacks)
     -> validate IMAGE_DOS_HEADER / IMAGE_NT_HEADERS
     -> reserve+commit OptionalHeader.SizeOfImage
     -> copy headers and sections via CopySections
     -> PerformBaseRelocation if image base moved
     -> BuildImportTable through callback LoadLibrary/GetProcAddress
     -> finalize page protections
     -> ExecuteTLS
     -> call AddressOfEntryPoint as DllMain(DLL_PROCESS_ATTACH)

MemoryGetProcAddress
  -> locate IMAGE_EXPORT_DIRECTORY
  -> resolve by name or ordinal
```

The implementation detail that matters: `ExecuteTLS` runs before the entry point, and `BuildImportTable` still calls the real loader for dependencies. This is not a universe without Windows loader behavior; it is a partial user-mode reproduction for one top-level image.

Claim -> source/probe -> interpretation:
- Claim: "Loading from memory is equivalent to `LoadLibrary`."
- Source/probe: compare `LoadLibraryW` with `MemoryLoadLibrary` using a DLL that has TLS callbacks, imports, and a `DllMain` side effect; observe loader lists, ETW image-load events, and `GetModuleHandle`.
- Interpretation: equivalence is false beyond basic execution. MemoryModule can run many DLLs, but it does not fully participate in loader metadata, policy, notifications, or all modern unwind/CFG/package constraints.

## Experiment Harness

First prove the real loader's behavior, then compare any memory loader against it. Build two DLLs with the same filename in different directories; call `LoadLibraryW(L"probe.dll")`, then print `GetModuleFileNameW(module)`.

```c
HMODULE m = LoadLibraryW(L"probe.dll");
wchar_t path[MAX_PATH];
GetModuleFileNameW(m, path, ARRAYSIZE(path));
wprintf(L"%ls\n", path);
```

```powershell
dumpbin /headers probe.dll | findstr /i "machine entry"
dumpbin /imports host.exe
set PATH=C:\alt;%PATH%
.\host.exe
```

Signal: loaded path, import table, TLS callback hit count, and `DllMain` order. Failure interpretation: wrong path means search-order assumptions are false; missing TLS/import behavior means the memory loader has not reproduced the loader contract. Undocumented/inferred area: `PEB->Ldr`, loader notifications, and private `Ldr*` behavior are not fully specified by public docs; treat them as observations, not portable contracts.

## Discussion Claim Verification

Claim: "Manual or in-memory loading is just `LoadLibrary` from bytes."

Why it matters for new code: loader equivalence is not a slogan. New loader-like code must account for relocations, imports, TLS callbacks, section protections, unwind metadata, load config, CFG, delay imports, activation context, and loader notifications. Missing one item can turn a sample that works for a toy DLL into a corrupt process.

How to verify:

```powershell
dumpbin /headers sample.dll
dumpbin /imports sample.dll
dumpbin /loadconfig sample.dll
dumpbin /tls sample.dll
wevtutil qe Microsoft-Windows-Kernel-Image/Operational /c:5 /f:text
```

Minimal code/pseudocode:

```text
control: h1 = LoadLibraryW("sample.dll")
test:    h2 = MemoryLoadLibrary(bytes)
measure:
  GetModuleHandle("sample.dll")
  GetModuleFileName(h1/h2)
  TLS callback counter
  imported function side effect
  exception throw/catch through DLL frame
```

Interpretation: MemoryModule verifies a partial loader worklist, not full equivalence. Unsupported claim nullified: "if `DllMain` runs, the loader contract is satisfied." `DllMain` running proves only that entry-point invocation happened.

## Connections
- `ManualMap`, `MemJect`, and Reflective DLL Loader notes are security-adjacent variations of the same loader responsibilities.
- `perfect-loader` and `Proxy-DLL-Loads` show different relationships to the official loader path.
- `winnt.h` defines the `IMAGE_*` structures used by every PE parser and manual loader.
- `CRT Linkage (MD MT DLL)` matters because a manually loaded CRT-linked DLL may expect process/runtime initialization that the real loader normally coordinates.

## References
- https://raw.githubusercontent.com/fancycode/MemoryModule/master/example/DllLoader/DllLoader.cpp
- https://github.com/fancycode/MemoryModule
- <https://learn.microsoft.com/en-us/windows/win32/debug/pe-format>
- <https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-search-order>
- <https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-security>
