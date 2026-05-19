<!-- generated-from-dump2 -->
# Offset Allocator (TLSF for GPU Heaps)

Single-header C port of Sebastian Aaltonen's two-level segregated fit allocator. Returns offsets into a caller-owned arena (not pointers), making it ideal for GPU heaps, file-backed mmaps, and packed asset buffers where you allocate from a `VkDeviceMemory` / `ID3D12Heap` you don't own. O(1) alloc and free with very low fragmentation.

```c
#define OFFSET_ALLOCATOR_IMPL
#include "offsetAllocator.h"

oaAllocator a;
oaCreate(&a, /*size*/ 64 * 1024 * 1024, /*maxAllocs*/ 4096);
oaAllocation slot = oaAllocate(&a, /*bytes*/ 256);
// slot.offset is the byte offset into your arena; slot.metadata is the free-list handle.
oaFree(&a, slot);
oaDestroy(&a);
```

## References
- <https://github.com/septag/OffsetAllocator>
