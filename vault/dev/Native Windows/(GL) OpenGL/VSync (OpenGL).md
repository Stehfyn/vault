# VSync (OpenGL)

On Windows OpenGL, swap interval is controlled by `WGL_EXT_swap_control` (`wglSwapIntervalEXT(1)` for vsync). That asks the driver to synchronize `SwapBuffers` with presentation, but in windowed mode DWM composition means the app is not presenting directly to scanout. `DwmFlush` can sometimes reduce phase drift by waiting for DWM to process queued presents, but it is not a universal low-latency fix.

The StackOverflow thread matters because "reliable vsync" is a multi-layer problem: WGL swap interval, driver queue depth, DWM compositor cadence, and DXGI/D3DKMT vblank timing can disagree. Read it with the DWM vblank notes and `Late-Latched Uniforms for Input Lag.md`.

## API Skeleton

The OpenGL call only controls the driver's swap interval for the current WGL context. It does not expose the monitor's VidPN source, DWM's compositor queue, or the DXGI frame statistics that a D3D path can ask for.

```cpp
using PFNWGLSWAPINTERVALEXTPROC = BOOL (WINAPI *)(int interval);
auto wglSwapIntervalEXT = reinterpret_cast<PFNWGLSWAPINTERVALEXTPROC>(
    wglGetProcAddress("wglSwapIntervalEXT"));

if (wglSwapIntervalEXT) {
    wglSwapIntervalEXT(1);
}

RenderFrame();
SwapBuffers(hdc);

// Optional phase fence against DWM's compositor work, not a raw scanline wait.
DwmFlush();
```

For raw display timing, use `../(DWM) Desktop Window Manager/VBlank Wait.md`. For compositor-clock timing, use `../(DWM) Desktop Window Manager/DCompositionWaitForCompositorClock — Decompiled.md`. For input-state freshness inside a GL frame, use `Late-Latched Uniforms for Input Lag.md`.

## Experiment Harness

Goal: prove which layer controls observed frame pacing: WGL swap interval, DWM flush, driver queue, or raw output cadence.

Procedure:
1. Render a color-toggling frame counter and run `SwapBuffers` with interval 0 and 1.
2. Add optional `DwmFlush` after swap and compare against no flush.
3. In a companion thread or D3D test window, log DXGI/DWM timing from `../(DWM) Desktop Window Manager/VBlank Wait.md`.

```cpp
wglSwapIntervalEXT(interval);
auto a = qpc();
SwapBuffers(hdc);
auto b = qpc();
if (use_dwm_flush) DwmFlush();
log(interval, use_dwm_flush, b - a);
```

Metric: swap blocking time, frame interval histogram, visible duplicate/drop count, and phase difference versus DWM timing.

Failure interpretation: interval 1 with no blocking can mean compositor/driver queueing hides the wait. `DwmFlush` reducing drift means the app was getting ahead of compositor work. Stable GL intervals but bad DWM phase means the bottleneck is outside WGL.

## Discussion Claim To Verify

The StackOverflow report is specific: on some Windows Intel/NVIDIA systems, a trivial windowed OpenGL loop with `wglSwapIntervalEXT(1)` drops frames unless `DwmFlush` is added after `SwapBuffers`; analogous D3D9/D3D11 loops were reported as stable. That gives a clean falsification matrix.

```cpp
for (auto api : { WGL, D3D11 }) {
  for (auto flush : { false, true }) {
    for (int frame = 0; frame != 10000; ++frame) {
      qpc0 = qpc();
      RenderOneColor(frame);
      api.PresentOrSwap(vsync_on);
      qpc1 = qpc();
      if (flush) DwmFlush();
      DwmGetCompositionTimingInfo(nullptr, &ti);
      log(api, flush, qpc1 - qpc0, ti.cFrames, ti.cFramesLate, ti.cFramesDropped);
    }
  }
}
```

Confirming evidence: WGL interval-1 has a wider frame-interval histogram or more DWM late/dropped counters than D3D11, and adding `DwmFlush` narrows that distribution without increasing render cost beyond the expected compositor wait. Nullifying evidence: WGL and D3D11 have the same cadence once the same window size, compositor state, GPU, power mode, and present queue depth are controlled.

The forum comments in that thread point at `D3DKMTWaitForVerticalBlankEvent`, but they also report that it was not the robust workaround for this specific windowed-OpenGL symptom. Treat that as a negative-control route: raw vblank can prove the monitor cadence is stable, but it does not prove that DWM accepted the GL back buffer at the right phase.

```cpp
// Four-way matrix, same window size and same color-toggle workload.
Run("wgl-swap",        [] { SwapBuffers(hdc); });
Run("wgl-swap+dwm",    [] { SwapBuffers(hdc); DwmFlush(); });
Run("wgl-swap+kmt",    [] { WaitForRawVBlank(); SwapBuffers(hdc); });
Run("d3d11-present",   [] { swapchain->Present(1, 0); });
```

Interpretation: if `wgl-swap+kmt` still stutters while `wgl-swap+dwm` improves, the bug is not raw scanout timing; it is the boundary between WGL's queued swap and DWM's composition queue. Use GPUView/WPA to look for `SwapBuffers`, DWM present, and GPU queue bubbles. If only NVIDIA/Intel hybrid machines reproduce it, log adapter LUIDs for the GL context's DC, the DWM/DXGI output, and any implicit copy path before drawing a driver conclusion.

## References
- <https://stackoverflow.com/questions/45676892/reliable-windowed-vsync-with-opengl-on-windows>
- <https://learn.microsoft.com/en-us/windows/win32/api/dwmapi/nf-dwmapi-dwmflush> - DWM queue flush reference.

## Connections
- `../(DWM) Desktop Window Manager/VBlank Wait.md`
- `../(DWM) Desktop Window Manager/How to dramatically improve Chrome's requestAnimationFrame VSYNC accuracy in Windows.md`
- `Late-Latched Uniforms for Input Lag.md`
- `OpenGL on DXGI Swapchain.md`
