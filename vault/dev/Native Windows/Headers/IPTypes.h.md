# IPTypes.h

Pulled in by `iphlpapi.h`; defines the `IP_ADAPTER_*` structure family that `GetAdaptersInfo` and (much more usefully) `GetAdaptersAddresses` return. Key types: `IP_ADAPTER_ADDRESSES` (the modern Vista+ adapter record with `FirstUnicastAddress`, `FirstDnsServerAddress`, `FriendlyName`, `Ipv6IfIndex`, `Mtu`, `TransmitLinkSpeed`), `IP_ADAPTER_UNICAST_ADDRESS_LH`, `IP_ADAPTER_PREFIX`, plus legacy `IP_ADAPTER_INFO` (IPv4-only). The standard idiom is the two-call pattern: call once with a NULL buffer to learn the required size, allocate, call again to fill it. Cluster: `iphlpapi.h` for the entry points, `ws2ipdef.h`/`in6addr.h` for `SOCKADDR_IN6`, `netioapi.h` for newer table APIs (`GetIfTable2`, `ConvertInterfaceLuidToIndex`).

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/iptypes/>
- <https://learn.microsoft.com/en-us/windows/win32/api/iphlpapi/nf-iphlpapi-getadaptersaddresses>
