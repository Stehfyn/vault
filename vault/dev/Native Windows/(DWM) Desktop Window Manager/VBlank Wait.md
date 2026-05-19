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

## References
- https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforverticalblankevent
- Related: `Lagless VSYNC ON via Beam Racing.md`, `Linux DRM Vertical Blank.md`, `DCompositionWaitForCompositorClock — Decompiled.md`
