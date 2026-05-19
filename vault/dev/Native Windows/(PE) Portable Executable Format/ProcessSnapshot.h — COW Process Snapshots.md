# ProcessSnapshot.h - COW Process Snapshots

`ProcessSnapshot.h` exposes the Process Snapshotting API (`Pss*`), which can capture a copy-on-write snapshot of a process's virtual address space, handles, threads, and related state for diagnostics. The key distinction from a direct live dump is stability: analysis can proceed against a snapshot while the target continues or exits.

PSS is especially relevant to PE and dump work because it freezes the memory view used to inspect mapped images, private executable regions, stacks, and handles. It is not a universal bypass for protected-process policy or access rights, but it is a cleaner primitive for legitimate diagnostics than racing a live process.

## Connections
- `Process Dump Tools` covers minidump writing that may use captured state.
- `DMA_PE_Dumper` is an out-of-OS contrast with very different trust assumptions.

## References
- Windows SDK `ProcessSnapshot.h`
