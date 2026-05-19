# DirectX Capabilities Viewer

`DxCapsViewer` is a source reference for enumerating DirectX capability surfaces: DXGI adapters, D3D feature levels/options, DXVA decode caps, Direct2D/DirectWrite data, and texture-format support. Its value is that it calls the official "check" APIs systematically instead of relying on trial device creation or folklore about a GPU family.

Use it when deciding how to gate optional paths: shader model, tiled resources, conservative rasterization, typed UAV loads, HDR output, video decode, or DirectWrite features. It belongs beside `D3d12info` in `(DX12) DirectX12.md`, but covers a broader Windows graphics/media stack.

## References
- <https://github.com/microsoft/DxCapsViewer>
