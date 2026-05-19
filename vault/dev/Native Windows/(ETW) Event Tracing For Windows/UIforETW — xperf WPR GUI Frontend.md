# UIforETW - xperf/WPR GUI Frontend

UIforETW is valuable because it treats ETW as a performance-capture discipline, not as a programming exercise. It wraps WPR/xperf profiles for CPU sampling, context switches, GPU/DWM, file I/O, and symbol configuration, producing ETL files intended for Windows Performance Analyzer rather than for custom callbacks.

The repository matters for its profiles and capture defaults. Buffer sizes, stack walking, symbol paths, and provider mixes are where many ETW investigations fail. UIforETW documents a battle-tested configuration style for game, browser, and desktop latency analysis.

## Connections
- Complement to `relogger.h`: UIforETW captures ETL; relogging can reduce or transform it later.
- Complement to `ProcMonXv2` and `wtrace`, which emphasize live operational views instead of WPA analysis.

## References
- <https://github.com/google/UIforETW>
