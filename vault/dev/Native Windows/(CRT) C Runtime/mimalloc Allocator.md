# mimalloc Allocator

`mimalloc` is Microsoft's compact general-purpose allocator: per-thread heaps, eager free-list reuse, guarded fast paths, and optional secure/debug modes. On Windows it is interesting because it can replace the CRT allocator in application code without replacing the process heap APIs (`HeapAlloc`, `LocalAlloc`), the COM task allocator, or handles returned by Win32. That boundary is non-negotiable: memory allocated by `mi_malloc` must be freed by `mi_free`, not by a DLL built against a different CRT or by a Win32 API that documents a different deallocator.

The allocator is most useful in native tools with heavy small-object churn or where allocator determinism matters more than adopting the platform heap wholesale. It does not remove the CRT by itself; it only substitutes one family of allocation entry points.

## Source Code Reading

The `microsoft/mimalloc` repository exposes the allocator as a layered fast path, not a black-box `malloc` replacement.

Files read:
- `include/mimalloc.h`
- `include/mimalloc-override.h`
- `include/mimalloc-new-delete.h`
- `src/alloc.c`
- `src/free.c`
- `src/heap.c`
- `src/init.c`
- `src/os.c`

The hot path in `src/alloc.c` is `_mi_page_malloc_zero`: take the current heap and page, pop a block from `page->free`, advance the free list, increment `page->used`, optionally zero/debug-fill the block, and return it. If the free list is empty, the code falls back to `_mi_malloc_generic`, which is where page/segment refill and larger allocation policy enter.

```c
// Pseudocode shape from src/alloc.c
block = page->free;
if (!block) return _mi_malloc_generic(heap, size, zero, flags, usable);
page->free = mi_block_next(page, block);
page->used++;
if (zero) zero_block(block);
return block;
```

That explains the performance claim better than a benchmark blurb: the common allocation case is deliberately page-local and thread/heap-local. The Windows-specific boundary appears lower, in OS/virtual-memory code such as `src/os.c`, where pages and segments ultimately come from operating-system reservation/commit primitives.

Code-driving uses:
- Include `mimalloc.h` and call `mi_malloc` / `mi_free` only inside one ownership domain.
- Include `mimalloc-new-delete.h` when a C++ translation unit should route global `new/delete`.
- Include `mimalloc-override.h` or use the override library only when process-wide interposition is the explicit experiment.

Actionable probe: allocate/free a million fixed-size objects with `mi_malloc`, CRT `malloc`, and `HeapAlloc(GetProcessHeap())`; record latency and RSS, then deliberately free one `mi_malloc` pointer with `free` under Application Verifier. The second half is not a benchmark; it proves ownership is part of the ABI.

## Connections
- `HeapApi.h` is the native process-heap surface that remains separate from mimalloc.
- `CRT Linkage (MD MT DLL)` explains why allocator ownership must be part of every DLL ABI contract.

## References
- <https://github.com/microsoft/mimalloc>
