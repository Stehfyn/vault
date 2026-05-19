# clfs.h

Shared kernel/user-mode definitions for the Common Log File System. Defines the core record types -- `CLFS_LSN` (Log Sequence Number, the 64-bit cursor that addresses every byte in the log), `CLFS_NODE_ID`, `CLFS_LOG_INFORMATION`, `CLFS_WRITE_ENTRY`, `CLFS_MGMT_POLICY`, and the I/O class IDs -- without the Win32 entry points (those live in `clfsw32.h`). The kernel-mode driver/filter side includes this file plus `clfskd.h` / `clfsproc.h`. Conceptually CLFS is a structured WAL with multiplexed streams, marshalling areas (lock-free per-thread append zones), and reservations (reserve N bytes now, commit them as a transaction later) -- the same engine the DTC, TxF, TxR, and Kernel Transaction Manager were built on. Three published 2024-era CVEs (`CVE-2024-49138` and friends) were CLFS BLF-parsing flaws, which is why it's a recurring privilege-escalation target in patch notes.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/clfs/>
- <https://learn.microsoft.com/en-us/windows/win32/clfs/common-log-file-system-portal>
