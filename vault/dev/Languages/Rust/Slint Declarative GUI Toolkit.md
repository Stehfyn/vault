<!-- generated-from-dump2 -->
# Slint Declarative GUI Toolkit

Declarative GUI toolkit with a domain-specific markup language (`.slint`) that you embed in Rust / C++ / JS / Python apps. Closer in spirit to QML than to egui/iced: layouts and styling live in `.slint` files, business logic in the host language, the two glue together via generated bindings. Compiles `.slint` markup ahead-of-time to platform-native widgets when available or its own software/GPU renderer when not — same source runs on a desktop, a microcontroller (no_std), and a browser via WASM. The licensing is split: GPL by default, royalty-free commercial license available, paid enterprise — a deliberate "open-core" stance, not pure FOSS.

```slint
// my_ui.slint
export component AppWindow inherits Window {
    title: "Counter";
    in-out property <int> counter: 0;
    callback request_increment;
    VerticalLayout {
        padding: 12px; spacing: 8px;
        Text { text: "count: " + counter; font-size: 20px; }
        Button { text: "+1"; clicked => { root.request_increment(); } }
    }
}
```

```rust
// main.rs
slint::include_modules!();

fn main() -> Result<(), slint::PlatformError> {
    let app = AppWindow::new()?;
    let weak = app.as_weak();
    app.on_request_increment(move || {
        let a = weak.unwrap();
        a.set_counter(a.get_counter() + 1);
    });
    app.run()
}
```

## References
- <https://github.com/slint-ui/slint>
