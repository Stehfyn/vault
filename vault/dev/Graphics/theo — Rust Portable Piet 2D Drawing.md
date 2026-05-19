<!-- generated-from-dump2 -->
# theo — Rust Portable Piet 2D Drawing

Rust drawing framework: a piet-compatible 2D drawing API that runs on top of any windowing system rather than being locked to a specific platform stack. Notable because piet historically had separate per-backend builds (CoreGraphics on macOS, Direct2D on Windows, Cairo on Linux); theo lets one piet codepath emit GPU draws through wgpu against any winit window, trading some platform-native antialiasing fidelity for portability.

```rust
use theo::Display;

let mut display = Display::builder()
    .build(&event_loop)
    .expect("create theo display");

let mut surface = display
    .make_surface(&window, width, height)
    .expect("attach surface");

// piet-style drawing
let mut ctx = surface.draw().unwrap();
ctx.clear(None, piet::Color::WHITE);
ctx.fill(&shape, &piet::Color::rgb8(0xff, 0, 0));
ctx.finish().unwrap();
```

## References
- <https://github.com/notgull/theo>
