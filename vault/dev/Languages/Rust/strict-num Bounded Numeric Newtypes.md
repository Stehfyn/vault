<!-- generated-from-dump2 -->
# strict-num Bounded Numeric Newtypes

Tiny Rust crate from the author of resvg / usvg that adds bounded-range numeric newtypes - `NonZeroPositiveF64`, `NormalizedF64` (0..=1), `PositiveF64` (0.0..), `FiniteF64` (no NaN/Inf), and a checked `LengthAdjust`. The point is to embed common preconditions into the type system so SVG/PDF/font code stops re-validating "is this a non-negative finite number" at every layer. Construction is fallible (`try_from`/`new` returning `Option`), arithmetic is panic-free.

```rust
use strict_num::NormalizedF64;

let alpha = NormalizedF64::new(0.5).unwrap();    // ok
let bad   = NormalizedF64::new(1.5);             // None
let neg   = NormalizedF64::new(-0.0);            // Some(0.0) - signs normalized

assert_eq!(alpha.get(), 0.5);
```

## References
- <https://github.com/RazrFalcon/strict-num>
