# NVIDIA DLSS NGX SDK

DLSS integration runs through NVIDIA NGX: initialize the SDK for the D3D device, create a feature handle, provide per-frame color/depth/motion-vector inputs plus render/display size metadata, then evaluate into an output resource. The useful detail is not the call sequence; it is the dependency on stable temporal inputs and NVIDIA runtime support. Bad motion vectors, wrong jitter, or resource-state mistakes produce the familiar ghosting/shimmering bugs.

Place this beside FidelityFX and XeSS. The shared engine-side contract is nearly identical, but DLSS adds NGX feature handles and NVIDIA-specific deployment/runtime expectations, while FSR is vendor-open and XeSS sits between vendor acceleration and broader fallback modes.

## References
- <https://github.com/NVIDIA/DLSS>

## Connections
- `FidelityFX SDK (FSR3, CACAO, SPD).md`
- `Intel XeSS D3D12 Upscaler.md`
- `DXGI SwapChain2 SetSourceSize.md`
