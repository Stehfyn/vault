<!-- generated-from-dump2 -->
# Creusot Rust Deductive Verifier

Deductive verification tool for Rust — you annotate functions with `#[requires(...)]` / `#[ensures(...)]` pre/post-conditions and loop invariants written in a "Pearlite" predicate language, Creusot extracts the proof obligations through the borrow checker's lens (using ownership to encode separation logic for free), and discharges them via Why3 to SMT solvers (Z3, CVC4, Alt-Ergo). Different niche from `prusti` and `kani`: Prusti is also Why3-backed but uses Viper; Kani is bounded model checking (no quantified specs, just `kani::assume`/`kani::assert` with bounded loops). Creusot can prove totally unbounded properties (e.g. "this iterator implementation is correct for any input"), at the cost of needing real proof annotations.

```rust
use creusot_contracts::*;

#[ensures(result@ == x@ + y@)]
#[ensures(result@ >= x@)]
fn add_nonneg(x: u32, y: u32) -> u32 {
    x + y
}

#[requires(v@.len() > 0)]
#[ensures(forall<i: Int> 0 <= i && i < v@.len() ==> result@ >= v@[i])]
fn max(v: &Vec<u32>) -> u32 {
    let mut m = v[0];
    #[invariant(forall<j: Int> 0 <= j && j < produced.len() ==> m@ >= v@[j])]
    for &x in v {
        if x > m { m = x; }
    }
    m
}
```

## References
- <https://github.com/creusot-rs/creusot>
