# DMA_PE_Dumper - FPGA DMA PE Reconstruction

DMA_PE_Dumper is interesting because it reconstructs PE images from memory outside the target operating system's normal trust path. Using PCILeech/MemProcFS-style access changes the evidence model: the dumper is no longer asking the target process or kernel APIs for module bytes, but reading physical memory and interpreting page tables, process metadata, and PE headers itself.

The defensive/research value is understanding what in-memory images look like after the loader has touched them: relocated pages, copy-on-write sections, discardable data, unmapped headers, patched imports, and regions that no longer correspond cleanly to the file on disk. It belongs with PE dumping and loader notes, not as a generic "bypass" recipe.

## Connections
- `In-Memory Module Loading`, manual mapping, and process hollowing notes explain why memory-resident PE images may diverge from disk.
- `Process Dump Tools` and `ProcessSnapshot.h` cover in-OS capture approaches with different trust assumptions.

## References
- <https://github.com/Trustings/DMA_PE_Dumper>
