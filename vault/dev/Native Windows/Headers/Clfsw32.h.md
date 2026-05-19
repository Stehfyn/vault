# Clfsw32.h

User-mode wrapper around the Common Log File System (CLFS) introduced in Windows Server 2003 / Vista. CLFS is a kernel-resident general-purpose log manager -- the same engine TxF and the DTC use -- exposing high-throughput append-only logs with marshalling areas, multiplexed streams, and reservations for crash-consistent commit. Headers cluster: `clfs.h` (shared kernel/user types), `clfsw32.h` (Win32 entry points in `clfsw32.dll`), `clfsmgmt.h` (policy), `clfslsn.h` (LSN arithmetic). Largely unused today outside Microsoft's own transactional infrastructure -- TxF itself was deprecated in Windows 10 -- but still the only Win32 way to get an OS-managed write-ahead log.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/clfsw32/>
- <https://learn.microsoft.com/en-us/windows/win32/clfs/common-log-file-system-portal>
