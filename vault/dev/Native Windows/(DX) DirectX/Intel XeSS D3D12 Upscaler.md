# Intel XeSS D3D12 Upscaler

XeSS is Intel's temporal upscaler SDK. The D3D12 integration shape is familiar: create a XeSS context for a device, choose quality/output resolution, then execute per frame with color, depth, motion vectors, jitter, exposure, and output UAV resources. The real work is making your engine's coordinate conventions match the SDK: motion-vector scale, reversed-Z depth, jitter offsets, resource states, and resolution changes.

Compare it with FidelityFX and DLSS rather than treating it as a standalone effect. All three sit after scene rendering and before presentation; all punish unstable motion vectors and bad reactive masks; all interact with dynamic resolution and `SetSourceSize`.

## References
- <https://github.com/intel/xess>

## Connections
- `FidelityFX SDK (FSR3, CACAO, SPD).md`
- `NVIDIA DLSS NGX SDK.md`
- `DXGI SwapChain2 SetSourceSize.md`
