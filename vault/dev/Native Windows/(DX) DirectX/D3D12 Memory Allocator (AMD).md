# D3D12 Memory Allocator (AMD)

D3D12MA is the D3D12 counterpart to Vulkan Memory Allocator: it suballocates `ID3D12Heap` memory, chooses heap types, tracks committed vs placed resources, and reports budget/fragmentation so every texture and buffer does not become its own heap decision. This matters because D3D12 exposes memory ownership directly; allocation policy becomes a renderer subsystem, not an API afterthought.

The library is most useful once samples move past a dozen resources: streaming textures, transient render targets, upload/readback heaps, aliasing, and residency pressure. Read it next to bindless/deferred samples and Cauldron, where descriptor and resource lifetime complexity appears quickly.

## References
- <https://github.com/GPUOpen-LibrariesAndSDKs/D3D12MemoryAllocator>
