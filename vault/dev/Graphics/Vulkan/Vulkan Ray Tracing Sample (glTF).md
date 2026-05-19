<!-- generated-from-dump2 -->
# Vulkan Ray Tracing Sample (glTF)

NVIDIA's reference glTF ray-tracing sample built on `VK_KHR_ray_tracing_pipeline` and `VK_KHR_acceleration_structure`. The shape of the API: you build BLASes per mesh (geometry), one TLAS that references them with per-instance 3x4 transforms + shader-binding-table offsets, then dispatch `vkCmdTraceRaysKHR` against an SBT containing raygen/miss/hit shaders. Worth reading specifically for: SBT layout, scratch-buffer sizing for `vkGetAccelerationStructureBuildSizesKHR`, and how to compact ASes via `VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR`.

```cpp
VkAccelerationStructureBuildGeometryInfoKHR buildInfo{
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR};
buildInfo.type  = VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR;
buildInfo.flags = VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR
                | VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR;
buildInfo.mode  = VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR;
buildInfo.geometryCount = 1;
buildInfo.pGeometries   = &triGeom;     // VkAccelerationStructureGeometryKHR with VK_GEOMETRY_TYPE_TRIANGLES_KHR

VkAccelerationStructureBuildSizesInfoKHR sizes{
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR};
vkGetAccelerationStructureBuildSizesKHR(dev,
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR,
    &buildInfo, &maxPrimitives, &sizes);
```

## References
- <https://github.com/nvpro-samples/vk_raytrace>
