# mimalloc Allocator

`mimalloc` is Microsoft's compact general-purpose allocator: per-thread heaps, eager free-list reuse, guarded fast paths, and optional secure/debug modes. On Windows it is interesting because it can replace the CRT allocator in application code without replacing the process heap APIs (`HeapAlloc`, `LocalAlloc`), the COM task allocator, or handles returned by Win32. That boundary is non-negotiable: memory allocated by `mi_malloc` must be freed by `mi_free`, not by a DLL built against a different CRT or by a Win32 API that documents a different deallocator.

The allocator is most useful in native tools with heavy small-object churn or where allocator determinism matters more than adopting the platform heap wholesale. It does not remove the CRT by itself; it only substitutes one family of allocation entry points.

## Connections
- `HeapApi.h` is the native process-heap surface that remains separate from mimalloc.
- `CRT Linkage (MD MT DLL)` explains why allocator ownership must be part of every DLL ABI contract.

## References
- <https://github.com/microsoft/mimalloc>
