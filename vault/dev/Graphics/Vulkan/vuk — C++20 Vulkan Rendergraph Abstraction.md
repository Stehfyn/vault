<!-- generated-from-dump2 -->
# vuk — C++20 Vulkan Rendergraph Abstraction

Rendergraph-based C++20 Vulkan abstraction. You declare passes that read/write *named* resources (`"shadowmap"`, `"hdr"`, etc.); vuk computes the DAG, inserts the right pipeline barriers and layout transitions automatically, and submits. Major selling point: you stop hand-rolling `VkImageMemoryBarrier` boilerplate — the bug class where you forget `srcAccessMask` for a write-after-read just disappears.

```cpp
vuk::RenderGraph rg("triangle");
rg.add_pass({
    .name      = "draw",
    .resources = {"swapchain"_image >> vuk::eColorWrite >> "out"},
    .execute   = [](vuk::CommandBuffer& cb) {
        cb.set_viewport(0, vuk::Rect2D::framebuffer())
          .set_scissor(0,  vuk::Rect2D::framebuffer())
          .bind_graphics_pipeline("triangle")
          .draw(3, 1, 0, 0);
    }
});
auto erg = std::move(rg).link(allocator, vuk::Compiler{});
vuk::execute_submit_and_present_to_one(allocator, std::move(erg), swapchain);
```

## References
- <https://github.com/martty/vuk>
