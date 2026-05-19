<!-- generated-from-dump2 -->
# OpenRAND — Counter-Based PRNGs for HPC

C++17/CUDA library of **counter-based** PRNGs (Threefry, Philox, Squares) packaged for HPC use. The fundamental property — and the entire reason these PRNGs exist — is that the k-th output of the stream is computable directly from the integer k without iterating, so parallel workers can each pull their own substream with no shared state. Bit-exact reproducibility across CPU and GPU executions of the same code: the same `(seed, counter)` always yields the same bits whether evaluated by thread 0 of a serial run or by GPU lane 123456 of a Kokkos kernel. Indispensable for Monte Carlo simulation reproducibility in HPC and ML reproducibility audits. Pairs naturally with Kokkos/RAJA/SYCL — the whole point is the same generator works without code changes across them.

```cpp
#include <openrand/philox.h>

// Per-particle, per-step seed; computed from physics indices, not from RNG state.
// Two different runs producing the same (i, step) get the same draws bit-for-bit.
auto rng = openrand::Philox(/*seed=*/12345u, /*counter=*/{particle_id, step, 0, 0});

float u = rng.draw_float();             // U(0,1)
auto v3 = rng.draw_normal3();            // 3 i.i.d. standard normals

// Bit-exact reproducibility across CPU and GPU: launch the same kernel
// from Kokkos/CUDA/serial; same particle_id+step gives the same draws.
```

## References
- <https://github.com/msu-sparta/OpenRAND>
