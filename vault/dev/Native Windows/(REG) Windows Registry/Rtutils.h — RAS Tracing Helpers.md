# Rtutils.h — RAS/Routing Tracing Helpers

`Rtutils.h` contains utility functions used by Routing and Remote Access components: tracing registration, trace printing, registry helpers, and event/reporting support from the RRAS era. It is not a general-purpose logging framework; it is a compatibility surface for networking services that predate ETW as the normal diagnostic channel.

The registry angle is that many RAS/Routing diagnostics are enabled, filtered, or located through service-specific configuration. When maintaining VPN, dial-up, or RRAS-adjacent code, this header explains why tracing may be wired through old service keys rather than modern manifest-based ETW providers.

## Connections
- `pdh.h`, `LoadPerf.h`, and `qos.h` are adjacent old networking/diagnostic APIs that still appear in service maintenance code.
- `processenv.h` and `userenv.h` matter for service context, because RRAS components usually run outside an interactive user profile.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/rtutils/>
