# DXGI SwapChain2 SetSourceSize

`IDXGISwapChain2::SetSourceSize` lets an app present a smaller source rectangle into a larger swap-chain target so DXGI scales at presentation. It is useful for dynamic-resolution rendering and UI/content separation where the backbuffer size remains tied to the window but the rendered scene is intentionally lower resolution.

The key distinction from `ResizeBuffers` is ownership: `ResizeBuffers` changes swap-chain buffers; `SetSourceSize` changes the presented source size. That means less churn during resolution changes, but you still need to manage viewport, scissor, UI scaling, and any upscaler such as FSR/XeSS/DLSS separately.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setsourcesize>

## Connections
- `FidelityFX SDK (FSR3, CACAO, SPD).md`
- `Intel XeSS D3D12 Upscaler.md`
- `NVIDIA DLSS NGX SDK.md`
