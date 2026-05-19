<!-- generated-from-dump2 -->
# Ziglings — Learn Zig by Fixing Programs

Zig's official "learn by fixing broken programs" tutorial — ~100 small `.zig` files, each with a deliberate compile error or wrong output, that you fix in order. Adopted (and the upstream Zig team helps keep it in sync with breaking language changes). Same pedagogy as "Rustlings" — drives the learner through the type system, comptime, allocators, error sets, optional types, structs, and tagged unions in roughly the order you'd hit them writing a real program. Most useful artifact for someone coming from C/C++/Rust who needs to internalize Zig's idiosyncrasies (no hidden allocator, explicit error union types, `comptime` as a first-class evaluation mode).

```bash
git clone https://codeberg.org/ziglings/exercises ziglings
cd ziglings
zig build           # tries to compile/run all exercises; stops at first broken one
zig build 1         # run a specific exercise
zig build healed    # run only previously-passing exercises
```

```zig
// Each exercise is a small program like this with a hole to fix:
const std = @import("std");
pub fn main() void {
    const number: u8 = 200;
    const other:  u8 = 100;
    // FIX: u8 max is 255 — this overflows. Widen the type:
    const sum = number + other;
    std.debug.print("{d}\n", .{sum});
}
```

## References
- <https://github.com/ratfactor/ziglings>
