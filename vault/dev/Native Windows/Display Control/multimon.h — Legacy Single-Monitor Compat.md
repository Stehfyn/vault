# multimon.h - Legacy Single-Monitor Compat

`multimon.h` is a compatibility shim from the era when code needed to compile against multi-monitor APIs but still run on single-monitor Windows. With `COMPILE_MULTIMON_STUBS` in exactly one translation unit, it can provide fallback definitions for functions such as `MonitorFromWindow` and `GetMonitorInfo` on systems that did not expose them. That makes it historically useful for reading old code, but mostly irrelevant for modern Windows targets.

The main lesson is architectural: display APIs have accumulated in layers. `multimon.h` answers "which monitor contains this window?", DEVMODE answers "what mode is this display device using?", DisplayConfig answers "what adapter-target path topology is active?", and monitor configuration answers "what will the physical panel do over DDC/CI?"

## Connections
- `Examples.md` separates DisplayConfig, DEVMODE, and monitor-control use cases.
- `Window Sizing.md` in Common Controls uses the modern `MonitorFromWindow` / `GetMonitorInfo` path for work-area aware sizing.
