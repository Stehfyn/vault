# LoadPerf.h — Performance Counter Loader Header

`LoadPerf.h` is the programmatic side of `lodctr` / `unlodctr`: it installs and removes performance-counter name/help text and provider registration data, historically from `.ini` and generated header files. The important detail is where the state lands: under the Performance registry hives used by PDH, PerfLib, and service-hosted counter DLLs. A bad install can leave orphaned counter indexes, corrupt localized strings, or make PDH queries return nonsense even though the service itself still runs.

This is installer-adjacent registry work. Use it when a setup action must register legacy counter providers, but treat it as machine-global mutable state, not an application preference. Modern ETW/EventCounter-style telemetry often avoids this whole registry-index model.

## Connections
- `pdh.h` is the consumer side of the counters loaded here.
- `advpub.h` and `SetupAPI.h` show neighboring setup mechanisms that also write machine-global registration state.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/loadperf/>
- <https://learn.microsoft.com/en-us/windows/win32/perfctrs/adding-counter-names-and-descriptions-to-the-registry>
