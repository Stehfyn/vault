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

## Experiment Harness

Goal: test whether `DwmGetCompositionTimingInfo` predicts frame phase better than `Sleep`/timer cadence.

Procedure:
1. Create a trivial animation loop that logs QPC at callback start, before present/paint, and after Dwm timing query.
2. Predict next callback from `qpcVBlank` and refresh period; compare against a naive `Sleep(16)` loop.
3. Repeat at 60/120/144 Hz if available and while dragging another window.

```c
DWM_TIMING_INFO ti = { sizeof(ti) };
DwmGetCompositionTimingInfo(NULL, &ti);
phase_error = qpc_now() - ti.qpcVBlank;
log(ti.cRefresh, ti.qpcVBlank, phase_error);
```

Metric: phase error to DWM vblank, missed frame count, p95 callback lateness, and drift over 30 seconds.

Failure interpretation: `E_INVALIDARG` means a non-null HWND was passed on modern Windows. Low phase error but visible stutter means callback prediction is not the bottleneck; inspect present queue, rendering cost, or compositor work. Large periodic spikes often indicate timer coalescing, CPU scheduling, or power state changes.

## Discussion Claim To Verify

The linked Chromium/W3C discussion is useful only if turned into a timing falsification: does `DwmGetCompositionTimingInfo` actually predict the callback/present phase better than timer-derived cadence? The old Chromium code-review trail for Windows vsync used `DwmGetCompositionTimingInfo` in the platform timing layer, which gives a concrete source target to inspect: browser code that converts DWM QPC values into a refresh interval and callback deadline.

Probe shape:

```cpp
// Native sidecar process beside a browser/test window.
DWM_TIMING_INFO ti = { sizeof(ti) };
DwmGetCompositionTimingInfo(nullptr, &ti);
log(qpc_now(), ti.qpcVBlank, ti.cRefresh, ti.cFrames,
    ti.cFramesLate, ti.cFramesDropped);

// Browser page logs requestAnimationFrame timestamps through postMessage/WebSocket.
// Join browser callback QPC-ish timestamps with native DWM timing samples.
```

Measurement that matters: callback phase error relative to `qpcVBlank`, frame-to-frame interval variance, drift over 30 seconds, and whether spikes correlate with `cFramesLate`/`cFramesDropped`. If `requestAnimationFrame` remains phase-unstable while DWM timing is stable, the failure is above DWM timing prediction. If DWM timing itself jitters against `IDXGIOutput::WaitForVBlank`, the failure is compositor timing or multi-monitor cadence, not JavaScript scheduling.

The W3C issue adds a second claim that should be tested separately: browsers should not hardcode 60 Hz or arbitrary caps on high-refresh displays, and callback timestamps should track display cadence closely enough that a moderate amount of callback work does not create visible jank. That is not a Windows API claim by itself; the Windows version is whether `DwmGetCompositionTimingInfo`, DXGI frame statistics, and the browser's own callback timestamps agree at 60/120/144 Hz.

```cpp
// Native probe emits the monitor/compositor cadence.
DWM_TIMING_INFO ti = { sizeof(ti) };
DwmGetCompositionTimingInfo(nullptr, &ti);
log("dwm", qpc_now(), ti.qpcRefreshPeriod, ti.qpcVBlank,
    ti.cRefresh, ti.cFramesLate, ti.cFramesDropped);

// Web page emits rAF deltas and controlled callback work duration.
// requestAnimationFrame(ts) {
//   busy_spin_us(work_us);
//   post({ ts, performance_now: performance.now(), work_us });
// }
```

Interpretation: if the native compositor period is 6.94 ms on a 144 Hz display but the rAF histogram clusters near 16.67 ms, the discussion claim is confirmed as a browser scheduling/cap problem. If rAF period matches refresh but phase wanders while DWM/DXGI are stable, the browser is matching rate but not phase. If both native and rAF timing jitter under CPU load, the probe has found an OS scheduling or GPU queue problem instead of an HTML timing-spec problem; rerun with MMCSS and ETW CPU scheduling traces before blaming rAF.

## References
- https://issues.chromium.org/issues/40409426#comment42
- https://github.com/w3c/html/issues/785
- https://learn.microsoft.com/en-us/windows/win32/api/dwmapi/nf-dwmapi-dwmgetcompositiontiminginfo
- Related: `VBlank Wait.md`, `DCompositionWaitForCompositorClock — Decompiled.md`, `Lagless VSYNC ON via Beam Racing.md`
