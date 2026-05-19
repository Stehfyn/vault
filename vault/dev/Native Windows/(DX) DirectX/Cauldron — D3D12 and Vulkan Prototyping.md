# Cauldron — D3D12 and Vulkan Prototyping

AMD Cauldron is a cross-API sample framework used by GPUOpen effects. Its value is not the window boilerplate; it is the common resource, shader, UI, and render-module structure that lets an effect ship both D3D12 and Vulkan paths without turning every sample into a new engine. That makes it a good reference for porting FidelityFX-style code where the algorithm is shared but barriers, descriptors, and presentation differ by API.

Use it when comparing `FidelityFX SDK (FSR3, CACAO, SPD).md` with Vulkan/OpenGL material in the GL folder. Do not use it as the smallest D3D12 teaching sample; it intentionally carries framework weight so effects can be swapped and benchmarked consistently.

## References
- <https://github.com/GPUOpen-LibrariesAndSDKs/Cauldron>
