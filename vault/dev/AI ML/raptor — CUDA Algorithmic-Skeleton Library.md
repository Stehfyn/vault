<!-- generated-from-dump2 -->
# raptor — CUDA Algorithmic-Skeleton Library

High-level algorithmic-skeleton library for CUDA — wraps the common parallel patterns (map, reduce, scan, stencil, partition, scatter/gather) as composable C++ templates so you write kernels in terms of "this is a map followed by a reduce" instead of hand-rolling block/thread arithmetic each time. Tradeoff vs. Thrust: smaller surface, easier to read; vs. raw CUDA: less fine-grained control over shared memory and warp specialization.

```cpp
#include <raptor/raptor.hpp>

raptor::vector<float> xs = ..., ys = ...;
raptor::vector<float> zs(xs.size());

// z[i] = x[i] * y[i] + 1, then sum.
raptor::map(zs.begin(), xs.begin(), ys.begin(), xs.size(),
            [] __device__ (float x, float y) { return x * y + 1.0f; });

float total = raptor::reduce(zs.begin(), zs.end(), 0.0f,
                             [] __device__ (float a, float b) { return a + b; });
```

## References
- <https://github.com/dma-neves/raptor>
