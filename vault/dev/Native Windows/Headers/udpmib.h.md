# udpmib.h

UDP-side counterpart of `tcpmib.h`. Defines the row / table shapes returned by `GetExtendedUdpTable` (and the older `GetUdpTable` / `GetUdp6Table`): `MIB_UDPROW_OWNER_PID`, `MIB_UDPROW_OWNER_MODULE`, `MIB_UDP6ROW_OWNER_PID`, `MIB_UDP6ROW_OWNER_MODULE`, plus their `MIB_*TABLE` wrappers. Each row is a `(local addr, local port, PID)` tuple, optionally plus owner-module info for the row (Vista+). This is how `netstat -ano` enumerates UDP listeners and how anti-malware tools attribute UDP sockets to a process. Use `GetExtendedUdpTable` rather than the older calls -- it's the only path to PID attribution. Cluster: `iphlpapi.h` (entry points), `tcpmib.h` (TCP siblings), `iprtrmib.h` (overall MIB-II surface).

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/udpmib/>
