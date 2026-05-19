<!-- generated-from-dump2 -->
# Tempest — Cross-API Graphics Abstraction (Vk/D3D12/Metal)

Cross-API graphics + audio + UI abstraction layer in C++17 with Vulkan, DirectX 12, and Metal backends. Used by the Gothic / OpenGothic reimplementation by the same author. Worth reading for how *one* high-level resource API can map cleanly onto three explicit-API backends — particularly the synchronization and descriptor-set abstractions, which are where naive abstractions usually leak.

```cpp
Tempest::VulkanApi  api;
Tempest::Device     dev(api);
Tempest::Texture2d  tex = dev.texture(image, /*mips*/ true);

auto pso = dev.pipeline(Tempest::Triangles, vs, fs);
auto cmd = dev.commandBuffer();
cmd.begin();
cmd.setUniforms(pso, tex);
cmd.draw(vbo);
cmd.end();
dev.submit(cmd);
```

## References
- <https://github.com/Try/Tempest>
