# winsafe - Ergonomic Rust Win32 Bindings

`winsafe` is a curated Rust wrapper over Win32 with newtyped handles, typed constants/messages, RAII guards, and optional GUI abstractions. The distinction from raw generated bindings is ergonomics: `HWND`, `HBITMAP`, `HDC`, and related resources are wrapped so ownership and cleanup are harder to get wrong, while the `gui` feature supplies a higher-level window/control model.

Its tradeoff is coverage. It is smaller and more opinionated than generated crates such as `windows`, but nicer for the APIs it covers. In the GDI/Common Controls context, the interesting part is resource safety: many native bugs in these notes are leaked objects, stale selected bitmaps, or pointer-sized casts that a careful wrapper can prevent.

## References
- <https://github.com/rodrigocfd/winsafe> - ergonomic Rust Win32/GUI binding crate.

## Connections
- `Common Controls/Custom Controls.md` and the GDI bitmap entries show the raw APIs that wrappers try to make less error-prone.
