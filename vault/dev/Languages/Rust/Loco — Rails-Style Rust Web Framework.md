<!-- generated-from-dump2 -->
# Loco — Rails-Style Rust Web Framework

"Rails-for-Rust" full-stack web framework. Built on Axum (HTTP), SeaORM (database), Redis (queues), and a code generator that scaffolds models / controllers / migrations from a single `loco generate` command. Position is deliberate: it's the *opinionated* anti-microframework — config files in YAML, jobs, mailers, auth, generated migrations, all bundled. Trades flexibility (you'll fight it if your architecture is unusual) for productivity on greenfield CRUD apps. Closest analogues outside Rust: Ruby on Rails (obviously), Laravel, Django.

```bash
# scaffold a project + a resource
cargo install loco-cli
loco new myapp
cd myapp
cargo loco generate scaffold post title:string content:text
cargo loco db migrate
cargo loco start
```

```rust
// src/controllers/post.rs
use loco_rs::prelude::*;
use crate::models::_entities::posts;

pub async fn list(State(ctx): State<AppContext>) -> Result<Response> {
    let items = posts::Entity::find().all(&ctx.db).await?;
    format::json(items)
}

pub fn routes() -> Routes {
    Routes::new().prefix("posts").add("/", get(list))
}
```

## References
- <https://github.com/loco-rs/loco>
