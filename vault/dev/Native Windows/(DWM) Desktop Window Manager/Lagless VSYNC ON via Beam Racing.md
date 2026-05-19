# Lagless VSYNC ON via Beam Racing

Multi-page Blur Busters thread by Mark Rejhon (chief Blur Buster) aimed at emulator authors: how to achieve **tear-free display with near-zero added latency** by running the emulator's raster *just ahead* of the physical display's scanout — a technique called "beam racing." The idea is to drop VSYNC ON entirely and instead use **VSYNC OFF with a very high present rate**, where each presented frame contains only the few scanlines the GPU is about to send to the cable. Done right, the visible result is identical to VSYNC ON, but the input-to-photon latency drops to a sub-frame value because you never have to wait for the next refresh boundary.

Page 10 (`start=90`) is deep in the practical jitter-handling territory: how to read or estimate the current physical scanline (raster-register polling on some hardware, derived from `QueryPerformanceCounter` deltas elsewhere), how to de-jitter the OS's coarse vblank timestamps (which can wobble multiple scanlines on Windows), and how the emulator's internal raster has to *lead* the real raster by a tunable margin so a worst-case jitter spike never causes the emulator scanout to fall behind the cable's scanout (which would tear).

Key takeaways from the thread:

- Use a **rolling-window scanline buffer**: render the emulator's scanlines slightly ahead of the cable's, present small slices on each `Present(0,0)`, never accumulate more than ~N scanlines of lead.
- The OS-reported vblank timestamp is noisy; build a Kalman-style smoother over the last K samples to get sub-scanline timing.
- If the GPU exposes a raster-position register (NVAPI's `NV_GPU_PERFCOUNTER_TYPE`-adjacent, or `D3DKMTGetScanLine` on Windows), use it; otherwise derive position from `vblank_time + fraction_through_refresh`.
- The break-even point: this technique only beats plain VSYNC OFF when present jitter is below ~1 scanline; on a noisy stack you're better off with conventional VSYNC ON and accepting the frame of latency.

Companion APIs on Windows: `D3DKMTGetScanLine`, `D3DKMTWaitForVerticalBlankEvent` (see `VBlank Wait.md`), `IDXGIOutput::WaitForVBlank`, `DwmGetCompositionTimingInfo`. The important distinction is that beam racing wants physical scanout position; compositor-clock waits are useful for phase prediction but too indirect once DWM queues or transforms the present. On Linux see the DRM vblank pipeline (see `Linux DRM Vertical Blank.md`).

```cpp
// Sketch of the beam-racing loop on Windows.
// Present small slices of the emulator's framebuffer, leading the real raster.
D3DKMT_GETSCANLINE sl = { adapter, vidPnSourceId };
D3DKMTGetScanLine(&sl); // sl.ScanLine = current physical row

constexpr int kLeadScanlines = 16; // tuning knob
int target = sl.ScanLine + kLeadScanlines;

// Render only the rows from g_emuRowCursor up to `target` into the swap chain.
RenderSlice(g_emuRowCursor, target);
g_emuRowCursor = target;

// Present immediately, no vblank wait — VSYNC OFF.
swapChain->Present(0, DXGI_PRESENT_DO_NOT_WAIT);

// On WM_PAINT-free, GPU-bound loops, this happens hundreds of times per refresh.
// If the emulator falls behind sl.ScanLine, we tear. If it gets too far ahead,
// the kLeadScanlines guard prevents future scanlines from being committed early.
```

## References
- <https://forums.blurbusters.com/viewtopic.php?t=3972&start=90>
- <https://forums.blurbusters.com/viewtopic.php?f=22&t=3972> (thread root, "Emulator Developers: Lagless VSYNC ON Algorithm")
- <https://blurbusters.com/blur-busters-lagless-raster-follower-algorithm-for-emulator-developers/>
- See also: `VBlank Wait.md` (Windows-side `D3DKMTWaitForVerticalBlankEvent`)
