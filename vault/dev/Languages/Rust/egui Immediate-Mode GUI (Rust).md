<!-- generated-from-dump2 -->
# egui Immediate-Mode GUI (Rust)

The canonical Rust immediate-mode GUI library — same model as Dear ImGui (every frame, walk the UI code; library tracks state via stable widget IDs hashed from call-site source location). Pure Rust, no C++ shim; backend-agnostic (eframe + winit + wgpu/glow is the standard combo, but you can plug it into any renderer that gives you a textured triangle list). Wins over Dear ImGui for Rust users because it integrates cleanly with the borrow checker, and over retained-mode libraries (slint, floem, iced) when you want minimum ceremony for tools / debug UIs / editors. Same author also maintains Rerun (the data-viewer).

```rust
use eframe::egui;

fn main() -> eframe::Result {
    eframe::run_simple_native("egui demo",
        eframe::NativeOptions::default(),
        move |ctx, _frame| {
            egui::CentralPanel::default().show(ctx, |ui| {
                ui.heading("Hello");
                if ui.button("Click me").clicked() {
                    println!("clicked");
                }
                ui.horizontal(|ui| {
                    ui.label("Slider:");
                    static mut V: f32 = 0.0;
                    unsafe { ui.add(egui::Slider::new(&mut V, 0.0..=1.0)); }
                });
            });
        })
}
```

## References
- <https://github.com/emilk/egui>
