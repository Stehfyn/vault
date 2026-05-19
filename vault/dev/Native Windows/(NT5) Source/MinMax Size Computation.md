# MinMax Size Computation (minmax.c)

`minmax.c` is the internal side of resize constraints. It combines monitor/work-area metrics, frame metrics, style bits, zoom/maximize state, and `WM_GETMINMAXINFO` application overrides into the track limits the user actually experiences during sizing. The practical nuance is that the application's `MINMAXINFO` response is not the whole answer; NTUSER still applies policy around the non-client frame and monitor geometry.

This is where custom chrome and multi-monitor behavior often go wrong. A window can claim a client minimum that becomes impossible after frame inflation, DPI scaling, or work-area clamping. Reading the NT5 implementation makes clear why resize bugs often involve both `WM_GETMINMAXINFO` and `SetWindowPos`/`SWP_FRAMECHANGED`.

## Connections
- `Caption Rendering` explains the frame whose metrics feed the calculation.
- `Window Manager Internals` applies the resulting size and z-order changes.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/minmax.c
