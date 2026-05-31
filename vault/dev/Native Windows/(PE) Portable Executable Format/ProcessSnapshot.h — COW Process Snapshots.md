# ProcessSnapshot.h - COW Process Snapshots

`ProcessSnapshot.h` exposes the Process Snapshotting API (`Pss*`), which can capture a copy-on-write snapshot of a process's virtual address space, handles, threads, and related state for diagnostics. The key distinction from a direct live dump is stability: analysis can proceed against a snapshot while the target continues or exits.

PSS is especially relevant to PE and dump work because it freezes the memory view used to inspect mapped images, private executable regions, stacks, and handles. It is not a universal bypass for protected-process policy or access rights, but it is a cleaner primitive for legitimate diagnostics than racing a live process.

## Capture Shape

The call is a process-handle authority check plus a capture mask. Use it when a dump or PE inspection pass needs stable address-space state without suspending every thread manually.

```c
HPSS snap = NULL;
DWORD rc = PssCaptureSnapshot(process,
    PSS_CAPTURE_VA_CLONE | PSS_CAPTURE_HANDLES | PSS_CAPTURE_THREADS,
    CONTEXT_ALL, &snap);
// inspect or feed the snapshot to dump tooling
PssFreeSnapshot(GetCurrentProcess(), snap);
```

## Experiment Harness

Make the target mutate memory while the collector captures. The collector reads the same address from the live process and from the snapshot-backed dump path.

```text
target: allocate page, write counter every 10 ms, print address
collector: OpenProcess -> PssCaptureSnapshot(PSS_CAPTURE_VA_CLONE | PSS_CAPTURE_THREADS)
measure: dump snapshot, then compare counter value against live ReadProcessMemory
```

Signal: snapshot value stays stable while live memory advances. Failure interpretation: `ERROR_ACCESS_DENIED` is a handle/protection problem, not a PSS semantic failure; unstable snapshot output usually means the code accidentally read the live process instead of the captured clone.

## Connections
- `Process Dump Tools` covers minidump writing that may use captured state.
- `DMA_PE_Dumper` is an out-of-OS contrast with very different trust assumptions.
- `HandleApi.h` is the source of the process-handle and duplicated-handle discipline around snapshot targets.
- `mindumpapiset.h` and `DbgHelp.h` are the header route from captured process state to minidump output.

## References
- Windows SDK `ProcessSnapshot.h`
- <https://learn.microsoft.com/en-us/windows/win32/api/processsnapshot/nf-processsnapshot-psscapturesnapshot>
- <https://learn.microsoft.com/en-us/previous-versions/windows/desktop/proc_snap/export-a-process-snapshot-to-a-file>
