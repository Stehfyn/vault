<!-- generated-from-dump2 -->
# Lockfree SPSC and MPMC Ring Buffers

Header-only C++11 lock-free / wait-free SPSC and MPMC ring buffers, queues, and bipartite buffers (bipbuf). Targets embedded / RTOS contexts where you cannot afford a mutex and the producer/consumer count is small and known. The bipartite buffer is the interesting one: variable-length records contiguous in memory (so you can write a packet header + payload and consume it as a single read), while remaining lock-free — relatively rare combination compared to fixed-element-size SPSC ring buffers. No `std::atomic_ref`, no allocations, sized statically as a template parameter.

```cpp
#include <lockfree/spsc/ring_buf.hpp>

lockfree::spsc::RingBuf<int, 1024> rb;   // capacity, fixed at compile time

// Producer thread
int items[] = {1, 2, 3};
rb.Write(items, 3);                       // bulk write, returns bytes written

// Consumer thread
int out[16];
size_t got = rb.Read(out, 16);
```

## References
- <https://github.com/DNedic/lockfree>
