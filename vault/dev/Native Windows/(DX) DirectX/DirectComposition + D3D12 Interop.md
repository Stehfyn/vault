# DirectComposition + D3D12 Interop

This sample demonstrates the D3D12 version of a DirectComposition presentation path: render into a DXGI swap chain, set that swap chain as an `IDCompositionVisual`'s content, attach the visual to an HWND target, and commit the visual tree. The important point is that DirectComposition consumes DXGI content; it does not care whether the producer was D3D11 or D3D12 as long as the device/swap-chain setup is compatible.

Use this when a plain HWND swap chain is too rigid: transparent overlays, visual transforms, blur/effects, or multiple composed surfaces inside one window. Pair it with the DWM thumbnail notes when the visual content comes from another window, and with `Windows Composition Engine.md` for the DComp mental model.

## References
- <https://github.com/PJayB/DirectCompositionDirectX12Sample>
