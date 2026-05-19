# Chrome requestAnimationFrame VSYNC Accuracy on Windows

The Chromium issue is about `requestAnimationFrame` phase error on Windows: if the browser schedules animation off coarse timers or stale swap feedback, JavaScript callbacks drift relative to DWM's compositor tick. `DwmGetCompositionTimingInfo` exposes QPC-domain timing (`qpcVBlank`, frame counters, refresh period) that lets the browser predict the next composition boundary instead of guessing from `Sleep` granularity.

The connection to the rest of this folder is direct. `DCompositionWaitForCompositorClock` is the newer explicit wait primitive; `D3DKMTWaitForVerticalBlankEvent` waits nearer the display kernel path; `DwmGetCompositionTimingInfo` is the browser-friendly DWM timing query. They answer the same question at different layers: "when will the next composed frame actually scan out?"

```c
DWM_TIMING_INFO ti = { sizeof(DWM_TIMING_INFO) };
DwmGetCompositionTimingInfo(NULL, &ti);
// ti.qpcVBlank = QPC timestamp of next VBlank
// ti.cFrames   = composition frame count
LARGE_INTEGER now;
QueryPerformanceCounter(&now);
// schedule next rAF at ti.qpcVBlank
```

## References
- https://issues.chromium.org/issues/40409426#comment42
- https://github.com/w3c/html/issues/785
- Related: `VBlank Wait.md`, `DCompositionWaitForCompositorClock — Decompiled.md`, `Lagless VSYNC ON via Beam Racing.md`
