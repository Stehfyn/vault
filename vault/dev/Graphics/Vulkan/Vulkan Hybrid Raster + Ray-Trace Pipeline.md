<!-- generated-from-dump2 -->
# Vulkan Hybrid Raster + Ray-Trace Pipeline

Vulkan sample that demonstrates a hybrid raster + ray-trace pipeline: G-buffer is rasterized, then specific effects (shadows, reflections, AO) are computed by tracing rays from G-buffer positions. This is the architecture Battlefield V / Control / Cyberpunk ship with — pure path tracing is too expensive, but you can afford a few rays per pixel for *specific* effects against a fully rasterized primary visibility pass.

```cpp
// Per-pixel ray-traced shadow trace, dispatched as compute against a TLAS.
// 1 ray per pixel; result is denoised before compositing with the G-buffer.
vkCmdBindPipeline(cmd, VK_PIPELINE_BIND_POINT_COMPUTE, shadowPipeline);
vkCmdBindDescriptorSets(cmd, VK_PIPELINE_BIND_POINT_COMPUTE,
                        shadowLayout, 0, 1, &shadowSet, 0, nullptr);
vkCmdDispatch(cmd, (w + 7) / 8, (h + 7) / 8, 1);
```

## References
- <https://github.com/diharaw/hybrid-rendering>
