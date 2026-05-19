<!-- generated-from-dump2 -->
# dprofiler — ETW Flame Graph UI

Lightweight Windows profiler that samples CPU, memory, I/O, and lock contention via ETW providers, then renders flame graphs / per-thread timelines in a Qt UI. Targeted at native game/engine developers who want WPA-style insights without the WPA learning curve.

```bash
# Capture a 30s system-wide trace, then open the produced .etl in dprofiler UI.
dprofiler.exe capture --duration 30 --output trace.etl --providers cpu,disk,lock
dprofiler.exe view trace.etl
```

## References
- <https://github.com/xwlan/dprofiler>
