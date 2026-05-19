# Direct Page Table Manipulation

This project demonstrates the concept of bypassing ordinary process-handle memory APIs by reasoning about virtual-to-physical translation directly. Instead of `ReadProcessMemory` telemetry, the interesting artifacts move to kernel memory primitives, page-table walks, CR3/directory-base handling, and unusual physical-page access.

For research, the value is understanding why handle-based detections are incomplete. If an actor can get a kernel primitive or DMA-style view of memory, the target process's user-mode access checks are no longer the control point. Connect this to `User-Mode Physical Memory Library`, `PreviousMode Flip Memory R W`, and kernel exploitation resources.

## References
- <https://github.com/SamuelTulach/DirectPageManipulation>
