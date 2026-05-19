<!-- generated-from-dump2 -->
# Modern Vulkan glTF Viewer (Bindless, Mesh Shaders)

Performance-focused glTF 2.0 viewer in Vulkan (C++23). Uses bindless descriptors (`VK_EXT_descriptor_buffer` / mutable descriptor types), mesh shaders where available, and IBL with prefiltered/irradiance cubemaps. Useful as a reference for *modern* (post-1.3) Vulkan idioms: dynamic rendering instead of render passes, synchronization2, and pushing all glTF material data into a single SSBO indexed by gl_DrawID.

```cpp
// Dynamic rendering: no VkRenderPass / VkFramebuffer needed.
VkRenderingAttachmentInfo colorAtt{VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO};
colorAtt.imageView   = swapchain.view;
colorAtt.imageLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
colorAtt.loadOp      = VK_ATTACHMENT_LOAD_OP_CLEAR;
colorAtt.storeOp     = VK_ATTACHMENT_STORE_OP_STORE;
colorAtt.clearValue.color = {{0,0,0,1}};

VkRenderingInfo ri{VK_STRUCTURE_TYPE_RENDERING_INFO};
ri.renderArea = {{0,0}, extent};
ri.layerCount = 1;
ri.colorAttachmentCount = 1;
ri.pColorAttachments    = &colorAtt;
vkCmdBeginRendering(cmd, &ri);
// draw...
vkCmdEndRendering(cmd);
```

## References
- <https://github.com/stripe2933/vk-gltf-viewer>
