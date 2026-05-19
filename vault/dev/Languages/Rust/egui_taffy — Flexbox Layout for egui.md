<!-- generated-from-dump2 -->
# egui_taffy — Flexbox Layout for egui

Integration crate that adds CSS-style flexbox / grid / block layout to egui by delegating to `taffy` — DioxusLabs' standalone Rust port of the same layout engine that browsers use. egui's built-in layout is good for forms but breaks down for non-trivial responsive designs (nested gaps, percentage sizes, wrap-after-N-items). With `egui_taffy` you describe a sub-tree with a `Style` (familiar to anyone who's written CSS) and the inner widgets are positioned by taffy each frame.

```rust
use egui_taffy::{taffy::prelude::*, tui};

egui::CentralPanel::default().show(ctx, |ui| {
    tui(ui, "main").reserve_available_space().style(Style {
        display: Display::Flex,
        flex_direction: FlexDirection::Row,
        gap: length(8.0),
        ..Default::default()
    }).show(|ui| {
        ui.style(Style { flex_grow: 1.0, ..Default::default() })
          .ui_add(|ui| ui.button("Left"));
        ui.style(Style { flex_grow: 2.0, ..Default::default() })
          .ui_add(|ui| ui.button("Center (twice as wide)"));
        ui.style(Style { flex_grow: 1.0, ..Default::default() })
          .ui_add(|ui| ui.button("Right"));
    });
});
```

## References
- <https://github.com/PPakalns/egui_taffy>
