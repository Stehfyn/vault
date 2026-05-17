Chrome issue tracking VSYNC timing accuracy for `requestAnimationFrame` on Windows, related to DWM composition timing. Uses `DwmGetCompositionTimingInfo` to obtain the QPC timestamp of the next VBlank, enabling sub-millisecond scheduling accuracy instead of relying on the system timer.

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
