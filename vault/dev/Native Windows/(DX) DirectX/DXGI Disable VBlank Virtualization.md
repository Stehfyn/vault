# DXGI Disable VBlank Virtualization

`DXGIDisableVBlankVirtualization` opts the process out of DXGI's vblank virtualization. That matters for measurement and low-latency exclusive-style paths where the app wants the physical output cadence rather than a compositor-smoothed or virtualized view of vblank timing. It is a niche API, but it belongs near the DWM vblank notes because it changes what timing feedback means.

Use with care: it is process-wide, not a per-swap-chain tuning knob, and it does not replace correct frame pacing. It only removes one layer of abstraction from timing.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/dxgi1_6/nf-dxgi1_6-dxgidisablevblankvirtualization>

## Connections
- `../(DWM) Desktop Window Manager/VBlank Wait.md`
- `../(DWM) Desktop Window Manager/Lagless VSYNC ON via Beam Racing.md`
