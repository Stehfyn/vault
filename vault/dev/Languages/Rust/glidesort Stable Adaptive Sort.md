<!-- generated-from-dump2 -->
# glidesort Stable Adaptive Sort

Orson Peters' stable adaptive sort — quicksort/mergesort hybrid with explicit handling of already-sorted runs. Beats `std::sort` (introsort) on partially sorted, reversed, and mixed inputs by detecting ascending/descending runs and merging them in place; falls back to a pdqsort-style partition on truly random data. Importantly *stable* (preserves order of equal elements), so unlike `slice::sort_unstable` it's a drop-in replacement for `slice::sort` that's typically faster. The successor work `ipnsort` (in-place network sort) by the same author + Lukas Bergdoll went into Rust stdlib in 2024 as the new default for `slice::sort_unstable`; glidesort itself remains a third-party crate for the stable variant.

```rust
use glidesort::sort;

let mut v = vec![5, 2, 8, 1, 9, 3];
sort(&mut v);                        // ascending, stable

let mut tuples = vec![(1, "b"), (2, "a"), (1, "a")];
sort(&mut tuples);                   // (1,"b") still before (1,"a") - stable

// Custom comparator
glidesort::sort_by(&mut v, |a, b| b.cmp(a));   // descending
```

## References
- <https://github.com/orlp/glidesort>
