<!-- generated-from-dump2 -->
# glow — Cross-Platform OpenGL Wrapper (Rust)

Single Rust crate that gives you the same OpenGL 4.6 / WebGL2 / GLES 3.x API surface regardless of which one you're actually running on. Wraps `gl_generator`-style FFI to the desktop GL on native, dispatches to the browser's WebGL2 context (via `web-sys`) on WASM, and exposes an *identical* trait so you can write `unsafe { gl.bind_buffer(...); gl.buffer_data_u8_slice(...); }` once and have it work in three places. Used by `egui_glow` and several wgpu-alternative pipelines that want raw GL access. Doesn't try to make GL safe — it's still `unsafe fn` everywhere; the safety win is purely "I don't need three feature-gated codepaths."

```rust
use glow::HasContext;

unsafe {
    let gl: &glow::Context = /* obtained from glutin / web-sys */;
    let vao = gl.create_vertex_array().unwrap();
    gl.bind_vertex_array(Some(vao));

    let vbo = gl.create_buffer().unwrap();
    gl.bind_buffer(glow::ARRAY_BUFFER, Some(vbo));
    gl.buffer_data_u8_slice(glow::ARRAY_BUFFER,
        bytemuck::cast_slice(&[0.0f32, 1.0, 2.0]),
        glow::STATIC_DRAW);

    gl.draw_arrays(glow::TRIANGLES, 0, 3);
}
```

## References
- <https://github.com/grovesNL/glow>
