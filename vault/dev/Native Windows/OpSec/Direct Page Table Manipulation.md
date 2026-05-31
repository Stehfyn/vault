# Direct Page Table Manipulation

This project demonstrates the concept of bypassing ordinary process-handle memory APIs by reasoning about virtual-to-physical translation directly. Instead of `ReadProcessMemory` telemetry, the interesting artifacts move to kernel memory primitives, page-table walks, CR3/directory-base handling, and unusual physical-page access.

For research, the value is understanding why handle-based detections are incomplete. If an actor can get a kernel primitive or DMA-style view of memory, the target process's user-mode access checks are no longer the control point. Connect this to `User-Mode Physical Memory Library`, `PreviousMode Flip Memory R W`, and kernel exploitation resources.

Use this comparison when tying the note to ordinary process-access telemetry:

```cpp
struct MemoryAccessPath {
    bool uses_process_handle;
    bool calls_ReadProcessMemory;
    bool walks_page_tables;
    bool reads_physical_pages;
    bool depends_on_driver_or_dma;
};
```

The boundary shift is the lesson: user-mode access control is meaningful only on the handle path. Once the path is page-table or physical-page based, the useful artifacts move to driver provenance, CR3/directory-base discovery, page-walk cadence, and large scans over physical memory.

## References
- <https://github.com/SamuelTulach/DirectPageManipulation>
