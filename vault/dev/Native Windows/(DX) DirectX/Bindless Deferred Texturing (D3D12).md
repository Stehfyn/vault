# Bindless Deferred Texturing (D3D12)

MJP's sample is about descriptor-indexed materials in a deferred renderer. Instead of sampling material textures during the geometry pass, it writes UV/material identity into the G-buffer and performs texture sampling later in the deferred pass through dynamically indexed descriptor tables. That is the useful D3D12 lesson: bindless is not just "lots of textures"; it changes where material evaluation happens and forces you to reason about descriptor heap residency, shader model support, and cache behavior.

The decal system is equally relevant because it uses clustered/deferred placement rather than forward-rendered decal meshes. Read it beside `D3D12 Memory Allocator (AMD).md` and `(DX12) DirectX12.md`: bindless renderers stress descriptor management and allocation policy earlier than toy samples do.

## References
- <https://github.com/TheRealMJP/DeferredTexturing>
