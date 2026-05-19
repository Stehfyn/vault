<!-- generated-from-dump2 -->
# Awesome Zig — Curated Resource List

Curated list of Zig libraries and resources, including build system and C interop examples.

```zig
const c = @cImport({
    @cInclude("windows.h");
    @cInclude("commctrl.h");
});

pub fn main() void {
    _ = c.InitCommonControlsEx(&.{
        .dwSize = @sizeOf(c.INITCOMMONCONTROLSEX),
        .dwICC = c.ICC_WIN95_CLASSES,
    });
}
```

## References
- <https://github.com/zigcc/awesome-zig>
