<!-- generated-from-dump2 -->
# renderdoc-rs Bindings

Rust bindings to the RenderDoc in-application API — the C API that lets an app embed RenderDoc and trigger frame captures from code (e.g. `set_capture_keys`, `trigger_capture`, `start_frame_capture` / `end_frame_capture`). Useful when the standard "press F12" capture isn't an option (your app is a server, runs headless, or you want to capture only specific frames identified by some game-state condition). Wraps the `renderdoc.dll` / `librenderdoc.so` API in safe Rust types per API version (`V100`...`V160`), dynamically loading the lib at runtime so the binary works whether or not RenderDoc is present.

```rust
use renderdoc::{RenderDoc, V160};

fn main() {
    let mut rd: RenderDoc<V160> = RenderDoc::new()
        .expect("RenderDoc not loaded - run via renderdoccmd or qrenderdoc");

    // Trigger capture on the next frame; file lands in default capture dir
    rd.trigger_capture();

    // Or programmatic begin/end for a specific scope
    rd.start_frame_capture(std::ptr::null(), std::ptr::null());
    render_one_frame();
    rd.end_frame_capture(std::ptr::null(), std::ptr::null());
}
```

## References
- <https://github.com/ebkalderon/renderdoc-rs>
