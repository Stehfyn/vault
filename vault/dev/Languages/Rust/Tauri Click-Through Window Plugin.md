<!-- generated-from-dump2 -->
# Tauri Click-Through Window Plugin

Tauri plugin to make a window click-through / penetrable (passes mouse events to windows beneath).

```rust
// underlying Win32 trick: WS_EX_LAYERED | WS_EX_TRANSPARENT
SetWindowLongPtrW(hwnd, GWL_EXSTYLE,
    GetWindowLongPtrW(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED | WS_EX_TRANSPARENT);
```

## References
- <https://github.com/sner21/tauri-plugin-penetrable>
