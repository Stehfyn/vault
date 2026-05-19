<!-- generated-from-dump2 -->
# QuickHeap SIMD Priority Queue (Rust)

SIMD-optimized priority queue in Rust; faster than std::BinaryHeap for large heaps.

```rust
use quickheap::QuickHeap;
let mut heap = QuickHeap::<u64>::new();
heap.push(42);
heap.push(7);
let min = heap.pop(); // 7
```

## References
- <https://github.com/RagnarGrootKoerkamp/quickheap>
