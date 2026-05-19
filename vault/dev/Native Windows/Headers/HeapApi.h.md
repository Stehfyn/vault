# HeapApi.h

Canonical Win32 heap surface in `kernel32`/`ntdll`: `HeapCreate`, `HeapDestroy`, `HeapAlloc`, `HeapReAlloc`, `HeapFree`, `HeapSize`, `HeapValidate`, `HeapWalk`, `HeapCompact`, `HeapSetInformation`, `GetProcessHeap`, `GetProcessHeaps`. Sits on top of `RtlAllocateHeap` and the segment-heap / NT-heap implementation in `ntdll.dll`; on Windows 10+ certain processes (`MicrosoftEdgeCP`, modern UWP, some opt-in apps) use the segment heap which has stronger guarantees but different fragmentation behaviour from the classic NT heap. The CRT's `malloc` lives on top of `HeapAlloc` against either a private heap or `GetProcessHeap`. Two perf knobs worth knowing: `HEAP_NO_SERIALIZE` for single-threaded heaps (skips the critical section), and `HeapSetInformation(h, HeapEnableTerminationOnCorruption, ...)` which is mandatory for any modern binary and turns heap-corruption detection into immediate process exit rather than exploitable behaviour.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/heapapi/>
- <https://learn.microsoft.com/en-us/windows/win32/memory/low-fragmentation-heap>
