# perflib.h - PerfLib v2 Provider Header

`perflib.h` is the provider API for modern Windows performance counters. Unlike ETW events, which are time-ordered records, PerfLib counters expose sampled state: counter sets, instances, values, and metadata that tools can query repeatedly. This makes PerfLib a better fit for gauges and rates than for reconstructing a causality chain.

The link to ETW is conceptual: both are provider/consumer systems with registration and schema, but their data models differ. Confusing them produces bad instrumentation. Use ETW when each occurrence matters; use PerfLib when the current value or aggregate rate is the artifact.

## Connections
- ETW provider API: `evntprov.h`.
- ETW trace post-processing: `relogger.h`.

## References
- Windows SDK `perflib.h`
