# ip2string.h

`Rtl*` IP-address parse / format primitives exported from `ntdll.dll`. Specifically: `RtlIpv4AddressToStringW` / `RtlIpv4StringToAddressW`, `RtlIpv6AddressToStringW` / `RtlIpv6StringToAddressW`, plus the `Ex` variants that include a port and scope id (`RtlIpv6AddressToStringExW` produces `[fe80::1%4]:443`). These predate `InetPtonW` / `InetNtopW` (which were added in Vista in `ws2_32.dll`) and have one big advantage: they require no Winsock startup (no `WSAStartup`, no socket library link), making them the cheap choice inside drivers, services, and bootstrap code that can't afford to spin up Winsock. They're also what `inet_pton` ends up calling internally on modern Windows.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/ip2string/>
