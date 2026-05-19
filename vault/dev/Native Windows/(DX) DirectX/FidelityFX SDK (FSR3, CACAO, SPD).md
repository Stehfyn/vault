# FidelityFX SDK (FSR3, CACAO, SPD)

The FidelityFX SDK is AMD's packaging for production rendering effects across D3D12 and Vulkan: FSR upscaling/frame generation, CACAO, SPD, denoisers, and related samples. The reason it matters in a Native Windows vault is the integration surface: each effect is a context plus per-frame dispatch descriptors over application-owned resources, so correctness depends on resource states, motion-vector conventions, depth conventions, exposure, jitter, and presentation timing rather than a single "enable FSR" call.

FSR frame generation also crosses into DXGI territory because generated frames need pacing and swap-chain integration. Read this beside `DXGI SwapChain2 SetSourceSize.md`, `Intel XeSS D3D12 Upscaler.md`, and `NVIDIA DLSS NGX SDK.md` to compare how vendor upscalers all require the same core inputs but differ in SDK lifetime, quality modes, and hardware assumptions.

## References
- <https://github.com/GPUOpen-LibrariesAndSDKs/FidelityFX-SDK>
