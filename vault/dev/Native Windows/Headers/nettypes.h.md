# nettypes.h

Tiny "shared types" header that breaks include cycles between the various networking SDKs. Defines `IFTYPE` (alias for `ULONG`), `IF_INDEX` (`NET_IFINDEX`), `NET_LUID_LH` (the persistent NetLuid identifier -- used by `ConvertInterfaceLuidToIndex` / `...ToAlias` / `...ToGuid` to stop code from getting confused when the volatile `IF_INDEX` is renumbered across reboots), and a handful of `IFTYPE_*` enum members corresponding to IANA `ianaiftype-mib`. Almost always pulled in transitively by `ifdef.h`, `iphlpapi.h`, `netioapi.h`. Nothing functional to call directly.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/ifdef/>
- <https://learn.microsoft.com/en-us/windows/win32/api/netioapi/>
