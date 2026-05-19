<!-- generated-from-dump2 -->
# atomic_queue Lock-Free MPMC Queue

Header-only C++14 lock-free fixed-size MPMC queues. Two variants matter: `AtomicQueue<T, Size>` stores `T` directly in an array (best for trivially-copyable PODs, no allocation) and `AtomicQueue2<T, Size>` stores pointers (when `T` is large or non-trivial). Both use a slot-array with per-slot `std::atomic` sequence numbers — the same Vyukov-bounded-MPMC pattern that boost::lockfree and folly::MPMCQueue use, but stripped to a single header with very few configuration knobs. Author publishes extensive throughput benchmarks: typically beats `boost::lockfree::queue` by 2-3x at low contention and stays competitive at high contention with shorter tail latency.

```cpp
#include <atomic_queue/atomic_queue.h>

// MPMC, 1024 slots, T=int, busy-wait on full/empty
atomic_queue::AtomicQueue<int, 1024> q;

// Producer
q.push(42);
if (!q.try_push(43)) { /* queue full */ }

// Consumer
int v = q.pop();        // busy-waits
if (q.try_pop(v)) {     // non-blocking
    // got v
}
```

## References
- <https://github.com/max0x7ba/atomic_queue>
