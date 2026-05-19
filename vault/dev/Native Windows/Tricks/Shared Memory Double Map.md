# Shared Memory Double Map

Raymond Chen's note explains a deceptively useful VM trick: map the same file-mapping object more than once and you get distinct virtual addresses backed by the same physical pages. Writes through either view are immediately visible through the other because the aliasing happens below the virtual address layer.

This is useful for ring buffers, wraparound-free parsers, and IPC designs where pointer arithmetic is simpler if the same storage appears twice contiguously. Connect it to `Microsoft IPC - Shared Memory Library` and any memory-mapped file notes; the trick is about virtual layout, not persistence.

## References
- <https://devblogs.microsoft.com/oldnewthing/20231229-00/?p=109204>
