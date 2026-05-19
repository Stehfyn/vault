<!-- generated-from-dump2 -->
# async_ui — Async-Function UI Library (Rust)

Experimental Rust UI library where components are *async functions*. A component runs forever as a future, awaiting events from its widgets — `button.until_click().await` literally suspends until the user clicks. Closer to UI in Erlang's gen_server style than to React or egui. The clever bit: instead of forcing a virtual-DOM diff or a retained-mode scene graph, lifetimes-as-scope keep widgets alive only while the async function holds them, so dropping a component automatically unmounts its widgets. Currently small and unstable; mostly interesting as a research proof-of-concept for "what does the Rust borrow checker actually enable in a GUI?"

```rust
use async_ui_web::{html::*, prelude::*};

async fn counter() {
    let mut count = 0;
    let btn = Button::new();
    let text = Text::new(format!("count = {count}"));
    fragment((&btn, &text)).render(async {
        btn.set_text("+1");
        loop {
            btn.until_click().await;
            count += 1;
            text.set_data(&format!("count = {count}"));
        }
    }).await;
}

fn main() {
    async_ui_web::mount(counter());
}
```

## References
- <https://github.com/wishawa/async_ui>
