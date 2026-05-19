# Dynamic Diffuse Global Illumination (DDGI)

NVIDIA's RTXGI-DDGI repository is a reference implementation of probe-based dynamic diffuse global illumination: ray tracing updates a sparse volume of irradiance/distance probes, and the deferred lighting pass samples that volume for indirect light. It sits between baked lightmaps and full path tracing: dynamic enough for moving lights/geometry, cheaper and more stable than brute-force multi-bounce tracing.

The Windows-native relevance is the D3D12/Vulkan integration pattern: raytracing acceleration structures, UAV/SRV resources for probe irradiance/distance, temporal update scheduling, and deferred shading inputs all have to line up. Read this with D3D12 capability queries because DXR support and shader model assumptions are gating constraints.

## References
- <https://github.com/NVIDIAGameWorks/RTXGI-DDGI>

## Connections
- `(DX12) DirectX12.md`
- `DirectX Capabilities Viewer.md`
