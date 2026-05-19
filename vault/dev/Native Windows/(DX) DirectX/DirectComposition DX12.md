# DirectComposition DX12

DirectComposition with D3D12 is mostly a swap-chain ownership problem. The app renders with D3D12, presents through a DXGI swap chain, and gives that swap chain to a DComp visual. DComp then schedules the visual tree into DWM rather than letting the HWND own presentation directly.

The distinction from `DirectComposition + D3D12 Interop.md` is editorial, not technical; keep both notes only if one tracks the sample and the other tracks the minimal API pattern. The useful nearby topics are DComp clock timing, transparent windows, and DWM shared thumbnail visuals.

## References
- <https://github.com/PJayB/DirectCompositionDirectX12Sample>

## Connections
- `Windows Composition Engine.md`
- `../(DWM) Desktop Window Manager/DWM Thumbnail - VirtualDesktop IDCompositionVisual.md`
