<!-- generated-from-dump2 -->
# min-sized-rust — Binary Size Recipes

Recipe collection (not a crate) for shrinking Rust release binaries — `Cargo.toml` profile knobs, `panic = "abort"`, `lto = true`, `codegen-units = 1`, `strip`, `opt-level = "z"`, building without the standard library (`#![no_std]`), and the more aggressive tricks like rebuilding `std` with `-Z build-std=std,panic_abort -Z build-std-features=panic_immediate_abort` on nightly. Useful pre-flight checklist when you have a real binary-size budget (embedded, distributing via npm/PyPI wheels, CLI bundles). Numbers are concrete: a default "Hello world" goes from ~3.4MB to ~6KB with the full stack of tricks applied.

```toml
# Cargo.toml — the "well-behaved" subset that works on stable
[profile.release]
opt-level = "z"          # optimize for size
lto = true               # link-time optimization
codegen-units = 1        # better optimization, slower compile
panic = "abort"          # no unwinding tables
strip = true             # strip symbols
```

```bash
# Add this once your size budget gets serious:
cargo +nightly build -Z build-std=std,panic_abort \
    -Z build-std-features=panic_immediate_abort \
    --target x86_64-unknown-linux-gnu --release
```

## References
- <https://github.com/johnthagen/min-sized-rust>
