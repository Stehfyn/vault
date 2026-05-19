<!-- generated-from-dump2 -->
# Floem Reactive Rust GUI Library

Native Rust GUI library extracted from the Lapce editor (a Rust competitor to VS Code). The differentiator vs egui (immediate mode, redraw-everything-each-frame) and iced (Elm-style update/view): floem uses a *fine-grained reactive* model borrowed from SolidJS — your view describes signals (`RwSignal<T>`), and individual DOM-like nodes subscribe to exactly the signals they read, so a state change only re-runs the slivers of view that actually depend on it. Result: handles large views (a text editor's whole document tree) without the per-frame work cost. Wgpu rendering, winit windowing.

```rust
use floem::reactive::create_rw_signal;
use floem::views::{button, label, v_stack, Decorators};
use floem::IntoView;

fn app_view() -> impl IntoView {
    let counter = create_rw_signal(0);

    v_stack((
        label(move || format!("count = {}", counter.get())),
        button(|| "Increment").on_click_stop(move |_| {
            counter.update(|c| *c += 1);
        }),
    ))
    .style(|s| s.padding(20).gap(10))
}

fn main() { floem::launch(app_view); }
```

## References
- <https://github.com/lapce/floem>
