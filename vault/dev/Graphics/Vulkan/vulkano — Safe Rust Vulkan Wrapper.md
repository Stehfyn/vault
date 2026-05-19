<!-- generated-from-dump2 -->
# vulkano — Safe Rust Vulkan Wrapper

Safe Rust wrapper around Vulkan — `unsafe` blocks at API boundaries only, with the type system enforcing things that the C API leaves to runtime validation (e.g. you literally cannot construct a `RenderPass` with mismatched attachment formats; it's a compile error). Trade-off: significantly more verbose than `ash` (which is a thin transliteration of `vulkan.h`), and you fight the borrow checker around `Arc<Device>` lifetimes; but you also can't UAF a `VkBuffer`.

```rust
use vulkano::pipeline::graphics::vertex_input::Vertex;

#[derive(BufferContents, Vertex)]
#[repr(C)]
struct MyVert { #[format(R32G32_SFLOAT)] pos: [f32; 2] }

let render_pass = vulkano::single_pass_renderpass!(
    device.clone(),
    attachments: {
        color: { format: Format::R8G8B8A8_SRGB,
                 samples: 1, load_op: Clear, store_op: Store }
    },
    pass: { color: [color], depth_stencil: {} }
)?;
```

## References
- <https://github.com/vulkano-rs/vulkano>
