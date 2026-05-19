<!-- generated-from-dump2 -->
# Vulkan SC Emulation Layer (Khronos)

Khronos's emulation layer that lets you run Vulkan SC (Safety-Critical) applications on top of standard Vulkan drivers — useful for developing/testing SC code on workstation GPUs before deploying to certified embedded silicon. Vulkan SC removes runtime features that hurt determinism (no allocator callbacks, frozen pipeline state via offline-compiled `VkPipelineCache` blobs, no dynamic descriptor indexing), so the emulator's job is to *enforce* those restrictions on top of a permissive driver.

```cpp
// Vulkan SC pipelines are loaded from a pre-built pipeline cache; runtime
// compilation is disallowed. The emulation layer rejects calls that try to
// create a pipeline without the cache or with an unrecognized identifier.
VkPipelineCacheCreateInfo pcci{VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO};
pcci.initialDataSize = blobSize;
pcci.pInitialData    = blob;
VkPipelineCache cache;
vkCreatePipelineCache(dev, &pcci, nullptr, &cache);
```

## References
- <https://github.com/KhronosGroup/VulkanSC-Emulation>
