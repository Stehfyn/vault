<!-- generated-from-dump2 -->
# left-right Reader-Writer Primitive

Jon Gjengset's Rust primitive for "many readers, one writer, never blocked, eventually consistent." Mechanism: keep *two* copies of the data structure; readers atomically check which side is "current" and read it without a lock; the writer mutates the *other* side, then atomically swaps the pointer, then catches up the now-stale side by replaying the same operations. Readers never see a torn write; readers are never blocked by the writer. Cost: writer does work twice and memory is doubled. Underpins `evmap` (the eventually-consistent map), and the design is well documented in Jon's video series. Contrast with `arc-swap` (similar pattern, simpler API, copies whole values rather than replaying ops) and `RwLock` (readers can starve writers; writers always block readers).

```rust
use left_right::{Absorb, ReadHandle, WriteHandle};

struct Counter(i64);
enum Op { Add(i64), Reset }

impl Absorb<Op> for Counter {
    fn absorb_first(&mut self, op: &mut Op, _: &Self) {
        match op { Op::Add(n) => self.0 += *n, Op::Reset => self.0 = 0 }
    }
    fn absorb_second(&mut self, op: Op, _: &Self) {
        match op { Op::Add(n) => self.0 += n,  Op::Reset => self.0 = 0 }
    }
    fn sync_with(&mut self, first: &Self) { self.0 = first.0 }
}

let (mut w, r) = left_right::new::<Counter, Op>();
w.append(Op::Add(10));
w.publish();                                  // make changes visible to readers
println!("{}", r.enter().unwrap().0);         // 10
```

## References
- <https://github.com/jonhoo/left-right>
