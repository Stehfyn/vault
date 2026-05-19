<!-- generated-from-dump2 -->
# eframe Starter Template (egui)

The starter repo for new `eframe`/`egui` apps. `eframe` is egui's official framework: it bundles the windowing (winit), GPU backend (wgpu or glow), and a small `App` trait so you get cross-platform native + WebAssembly out of the box. The template is interesting because it includes the `trunk` config and a `lib.rs`/`main.rs` split that compiles the same code to a native binary or a WASM bundle without `cfg` noise. Standard answer to "I want to write a Rust GUI in 10 minutes."

```rust
// src/main.rs
use eframe::egui;

fn main() -> eframe::Result {
    let opts = eframe::NativeOptions::default();
    eframe::run_native("My App", opts, Box::new(|cc| Ok(Box::new(MyApp::new(cc)))))
}

struct MyApp { count: i32, name: String }
impl MyApp {
    fn new(_cc: &eframe::CreationContext<'_>) -> Self {
        Self { count: 0, name: "world".into() }
    }
}
impl eframe::App for MyApp {
    fn update(&mut self, ctx: &egui::Context, _: &mut eframe::Frame) {
        egui::CentralPanel::default().show(ctx, |ui| {
            ui.heading(format!("Hello {}!", self.name));
            ui.text_edit_singleline(&mut self.name);
            if ui.button("Click").clicked() { self.count += 1; }
            ui.label(format!("count = {}", self.count));
        });
    }
}
```

## References
- <https://github.com/emilk/eframe_template>
