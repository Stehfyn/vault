# NpEtw - Named-Pipe I/O ETW Provider

NpEtw fills a real visibility gap: Windows exposes excellent file, registry, process, image-load, and network ETW, but named-pipe content and pipe-level flow are not covered with the same fidelity. A minifilter-style component can observe named-pipe operations and publish them through a custom ETW provider, letting ordinary ETW consumers correlate pipe activity with process, RPC, service-control, and authentication events.

The research value is architectural more than procedural. It shows when user-mode ETW is insufficient and why a provider may need to be added near the object being observed. That distinction matters for defenders: missed telemetry is not always a bad query; sometimes the provider simply does not exist in stock Windows.

## Connections
- Pair with `ProcMonXv2` and `wtrace` to compare stock kernel providers with custom provider coverage.
- Pair with `evntprov.h` and `EventWrite` for the custom-provider emission model.

## References
- <https://github.com/kobykahane/NpEtw>
