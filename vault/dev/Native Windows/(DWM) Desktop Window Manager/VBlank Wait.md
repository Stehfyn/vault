# VBlank Wait

`D3DKMTWaitForVerticalBlankEvent` is the WDDM/DXGK-side vblank wait, below DXGI and DWM. You pass an adapter/device/source id and block until the VidPN source reaches vertical blank. That makes it useful for latency experiments, beam-racing research, and drivers/tools that need display timing without creating a swap chain.

Do not confuse this with compositor timing. `IDXGIOutput::WaitForVBlank` is the user-mode DXGI wrapper, `DwmGetCompositionTimingInfo` reports the compositor's view of the cadence, and `DCompositionWaitForCompositorClock` waits on the DComp compositor clock. On a composed desktop those are related but not identical clocks.

## Snippet
```c
D3DKMT_WAITFORVERTICALBLANKEVENT wait = {};
wait.hAdapter = adapter;
wait.hDevice = device;
wait.VidPnSourceId = sourceId;

NTSTATUS status = D3DKMTWaitForVerticalBlankEvent(&wait);
```

## User-Mode Counterpart

When you already have a DXGI output, the documented user-mode shape is simpler, but it is still a wait for the output's vertical blank, not proof that DWM has accepted or displayed your particular frame.

```cpp
wil::com_ptr<IDXGIOutput> output;
swap_chain->GetContainingOutput(&output);

output->WaitForVBlank();

DXGI_FRAME_STATISTICS stats = {};
if (SUCCEEDED(swap_chain->GetFrameStatistics(&stats))) {
    auto present_count = stats.PresentCount;
    auto refresh_count = stats.SyncRefreshCount;
}
```

Use `D3DKMTGetScanLine` in `Lagless VSYNC ON via Beam Racing.md` when the current physical row matters. Use `../(DX) DirectX/Windows Composition Engine.md` or `DCompositionWaitForCompositorClock — Decompiled.md` when the compositor phase matters more than raw scanout.

## Experiment Harness

Goal: separate raw output vblank, DXGI present statistics, and DWM composition timing on the same monitor.

Procedure:
1. Create a minimal flip-model swap chain and call `GetContainingOutput`.
2. In one loop, timestamp `IDXGIOutput::WaitForVBlank`, `Present(1,0)`, `GetFrameStatistics`, and `DwmGetCompositionTimingInfo(NULL, ...)`.
3. Repeat on a static desktop, during animation, with a second monitor attached, and after toggling refresh rate or VRR/HDR if available.

```cpp
auto a = qpc();
output->WaitForVBlank();
auto b = qpc();
DWM_TIMING_INFO ti = { sizeof(ti) };
DwmGetCompositionTimingInfo(NULL, &ti);
swap_chain->GetFrameStatistics(&stats);
log(b - a, ti.cRefresh, ti.qpcVBlank, stats.PresentCount);
```

Metric: vblank interval distribution, drift between `qpcVBlank` and observed waits, present count increments, late/missed frame counters from `DWM_TIMING_INFO`.

Failure interpretation: no frame statistics can mean unsupported swap-chain mode or not enough presents. Multi-monitor drift usually means the containing output or largest-window-intersection output changed. Stable raw vblank with unstable DWM counters means the compositor queue, not scanout, is the variable.

## References
- https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforverticalblankevent
- https://learn.microsoft.com/en-us/windows/win32/api/dwmapi/nf-dwmapi-dwmgetcompositiontiminginfo
- Related: `Lagless VSYNC ON via Beam Racing.md`, `Linux DRM Vertical Blank.md`, `DCompositionWaitForCompositorClock — Decompiled.md`
