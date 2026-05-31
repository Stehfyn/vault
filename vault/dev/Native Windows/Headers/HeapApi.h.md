# HeapApi.h

Canonical Win32 heap surface in `kernel32`/`ntdll`: `HeapCreate`, `HeapDestroy`, `HeapAlloc`, `HeapReAlloc`, `HeapFree`, `HeapSize`, `HeapValidate`, `HeapWalk`, `HeapCompact`, `HeapSetInformation`, `GetProcessHeap`, `GetProcessHeaps`. Sits on top of `RtlAllocateHeap` and the segment-heap / NT-heap implementation in `ntdll.dll`; on Windows 10+ certain processes (`MicrosoftEdgeCP`, modern UWP, some opt-in apps) use the segment heap which has stronger guarantees but different fragmentation behaviour from the classic NT heap. The CRT's `malloc` lives on top of `HeapAlloc` against either a private heap or `GetProcessHeap`. Two perf knobs worth knowing: `HEAP_NO_SERIALIZE` for single-threaded heaps (skips the critical section), and `HeapSetInformation(h, HeapEnableTerminationOnCorruption, ...)` which is mandatory for any modern binary and turns heap-corruption detection into immediate process exit rather than exploitable behaviour.

## Runtime Boundary

The safe cross-module rule is simple: free memory with the allocator family that allocated it. That makes `HeapAlloc(GetProcessHeap())` a better ABI boundary than CRT `malloc` only when every module explicitly agrees to that heap and exposes ownership in the function contract.

```c
HANDLE heap = GetProcessHeap();
void* p = HeapAlloc(heap, 0, bytes);
// pass p across a DLL boundary only if the callee is told to call HeapFree(heap, 0, p)
HeapFree(heap, 0, p);
```

## Experiment Harness

Turn allocator ownership into a measurable contract. Export one path that uses `GetProcessHeap` and one that uses a private heap; make the caller free both ways and record which combinations survive under verifier.

```c
HANDLE h = HeapCreate(0, 0, 0);
void* a = HeapAlloc(GetProcessHeap(), 0, 64);
void* b = HeapAlloc(h, 0, 64);
HeapFree(GetProcessHeap(), 0, a); // expected valid
HeapFree(GetProcessHeap(), 0, b); // expected invalid boundary
```

Signal: `HeapValidate(GetProcessHeap(), 0, p)` before free and verifier/pageheap after free. Failure interpretation: a pointer value is not an ownership token; the heap handle or freeing function is part of the ABI.

Connections: `CRT Linkage (MD MT DLL)` is the adjacent runtime-policy note; `ntdll.lib` is where the lower `RtlAllocateHeap` family lives; `AccessMask Decoder` explains the object-rights vocabulary around handles that carry heap-adjacent process access.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/heapapi/>
- <https://learn.microsoft.com/en-us/windows/win32/memory/low-fragmentation-heap>
