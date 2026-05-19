# Process Dump Tools

Process dump tooling sits between legitimate diagnostics and sensitive-memory exposure. The API center is `MiniDumpWriteDump`, but the meaningful choices are dump type, handle access, target bitness, protected-process restrictions, callback filtering, and whether the dump captures only stack/module metadata or full readable memory.

The linked `calmdump` project is useful as a compact reference for dump generation mechanics. Read it alongside PSS snapshots and NTAPI process-handle notes: modern dump tools often combine handle acquisition, snapshotting, minidump callbacks, and symbol-aware postmortem analysis rather than treating dump writing as one opaque call.

## Connections
- `ProcessSnapshot.h` covers copy-on-write snapshots that can stabilize dump capture.
- System Informer and phnt explain the native process and handle enumeration often used before dumping.

## References
- https://github.com/qi7chen/calmdump
