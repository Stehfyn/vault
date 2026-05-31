# CRT Linkage (MD MT DLL)

`/MD` and `/MT` choose the CRT implementation model, not whether the program itself is a DLL or an EXE. `/MD` links import libraries and expects the Universal CRT / vcruntime DLLs at run time; `/MT` copies the static CRT into each linked image. `/LD` merely tells the linker to produce a DLL. Confusing these flags produces the classic plugin bug: an EXE and a DLL each built with static CRTs have separate heaps, separate `errno`, separate locale state, and separate `atexit` lists, so allocating in one module and freeing in another is undefined even when the signatures look compatible.

The modern default for application code is usually `/MD` because servicing, heap ownership, and ABI boundaries are cleaner. `/MT` is defensible for single-file tools, recovery environments, and deployment targets where redistributables are the real failure mode. Mixing `/MDd`, `/MTd`, `/MD`, and `/MT` across a process should be treated as a build-system error unless every boundary is pure Win32 handles or caller-owned buffers.

## DLL Boundary Contract

The actionable rule is to keep allocation and destruction on the same side of the ABI. Export either caller-allocated buffers, Win32 handles, or paired create/free functions from the same module.

```c
// Good native DLL boundary: ownership is explicit and symmetric.
__declspec(dllexport) BOOL MakeText(wchar_t* dst, DWORD cchDst);

__declspec(dllexport) void* WidgetCreate(void);
__declspec(dllexport) void  WidgetDestroy(void* widget); // same DLL frees it
```

## Experiment Harness

Build an EXE and DLL in a 2x2 CRT matrix, then run only one operation: DLL allocates, EXE frees. Use a disposable test process and enable PageHeap/Application Verifier when possible.

```powershell
cl /nologo /LD /MT allocdll.c /Fealloc_mt.dll
cl /nologo /MD host.c alloc_mt.lib /Fehost_md.exe
gflags /p /enable host_md.exe /full
.\host_md.exe
```

Minimal ABI under test:

```c
// DLL
__declspec(dllexport) void* Give(size_t n) { return malloc(n); }

// EXE: intentionally wrong unless both sides share the same CRT instance.
void* p = Give(32);
free(p);
```

Signal: invalid-heap termination, verifier break, or heap corruption proves the boundary is wrong. A clean run does not prove safety; it only means the allocator mismatch did not fault on that run. The safe follow-up is a paired `Take(void*)` export or a caller-owned buffer API.

## Discussion Claim Triage

The Stack Overflow link is useful because it surfaces the recurring misconception: `/MD`, `/MT`, and `/LD` are often treated as interchangeable "DLL flags." They are not.

```text
claim: "/MD means DLL and /MT means EXE/static."
source/disassembly/probe:
  cl /LD /MD plugin.c /Feplugin_md.dll
  cl /LD /MT plugin.c /Feplugin_mt.dll
  dumpbin /imports plugin_md.dll
  dumpbin /imports plugin_mt.dll
interpretation:
  both outputs are DLLs because /LD controls image type.
  /MD versus /MT controls CRT dependency and runtime state ownership.
```

```text
claim: "cross-DLL malloc/free is fine when both modules use MSVC."
source/disassembly/probe:
  build EXE/DLL matrix: /MD-/MD, /MD-/MT, /MT-/MD, /MT-/MT
  DLL exports Give=malloc and Take=free
  host tests host-free and DLL-free under PageHeap
interpretation:
  the only ABI-stable design is same allocator family or paired ownership.
  clean execution is not proof; verifier failures are proof of a broken boundary.
```

## Discussion Claim Verification

Claim: "`/MD`, `/MT`, and `/LD` are mostly deployment preferences."

Why it matters for new code: the wrong interpretation creates ABI bugs. `/LD` changes the PE image type. `/MD` and `/MT` change which CRT owns heap state, initializer tables, `errno`, locale, debug heap behavior, and termination callbacks. A plugin API that passes CRT-owned memory is therefore not a C ABI just because it uses `extern "C"`.

How to verify:

```powershell
cl /nologo /LD /MD plugin.c /Feplugin_md.dll /link /MAP:plugin_md.map
cl /nologo /LD /MT plugin.c /Feplugin_mt.dll /link /MAP:plugin_mt.map
dumpbin /headers plugin_md.dll | findstr /i "DLL"
dumpbin /imports plugin_md.dll
dumpbin /imports plugin_mt.dll
dumpbin /dependents plugin_md.dll
dumpbin /dependents plugin_mt.dll
```

Minimal code/pseudocode:

```c
// Bad ABI probe: intentionally crosses CRT ownership.
__declspec(dllexport) char* make_text(void) {
    char* p = (char*)malloc(32);
    return p;
}

// Good ABI pattern: same module owns destruction.
__declspec(dllexport) void free_text(char* p) {
    free(p);
}
```

Interpretation: the Stack Overflow confusion is nullified by the PE headers and imports. Both `/MD` and `/MT` can produce DLLs; `/LD` controls that. Cross-module allocation is verified only when the allocator contract is explicit or both sides are known to share the same CRT instance. A successful smoke test does not prove heap safety.

## Connections
- `Binary Size Reduction` and `VC-LTL5` explain two different reasons people fight the default CRT linkage.
- `CRT Startup Hooks` is affected by this choice because each CRT instance owns its own initializer tables and termination callbacks.
- `HeapApi.h` is the shared Win32 allocator surface when a process deliberately chooses a non-CRT ownership contract.
- `DLL Build Config` is the deployment side: bitness, exports, manifests, and CRT choice decide whether the module loads before any API can be called.

## References
- <https://stackoverflow.com/questions/35884239/conceptual-ambiguity-between-md-mt-and-dll-lib/35884751#35884751>
- <https://learn.microsoft.com/en-us/cpp/build/reference/md-mt-ld-use-run-time-library>
- <https://learn.microsoft.com/en-us/cpp/c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries>
