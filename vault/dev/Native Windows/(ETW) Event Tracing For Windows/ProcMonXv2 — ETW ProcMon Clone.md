# ProcMonXv2 - ETW ProcMon Clone

ProcMonXv2 is a useful counterexample to the assumption that Procmon-style visibility always requires a custom kernel driver. It builds a process/file/registry/network monitor on real-time ETW providers, then does the hard desktop-tooling work: filtering, correlation, formatting, and keeping a high-volume UI responsive.

Its limitation is also instructive. ETW can expose a large fraction of operational behavior, but it does not automatically provide every pre-operation decision point, stack, buffer, or object detail that a driver can collect. Read it as a practical map of what stock ETW can do well before reaching for kernel instrumentation.

## Connections
- Compare with `wtrace` for CLI streaming and `UIforETW` for WPA-oriented capture.
- Compare with NpEtw for cases where stock providers do not cover the object class being studied.

## References
- <https://github.com/zodiacon/ProcMonXv2>
