<!-- generated-from-dump2 -->
# komihash 64-bit Hash and PRNG

Aleksey Vaneev's family of non-cryptographic 64-bit hash and PRNG primitives, sitting in the same niche as wyhash, xxh3, and rapidhash. Headline number: ~27 GB/s on a modern x86 box. Mechanism is a 64x64 -> 128-bit multiply mix (the same trick xxh3/wyhash use), but with a different round structure and an explicit streamed mode whose state can be checkpointed mid-stream and resumed — which most competitors don't support cleanly. Passes SMHasher; the author also publishes `komirand` (matching PRNG) and `prvhash` (a stronger sibling for cases where wyhash-class collisions concern you).

```c
#include "komihash.h"

// One-shot:
uint64_t h = komihash(data, len, /*seed=*/0);

// Streamed (lets you hash data that's not contiguous in memory):
komihash_stream_t s;
komihash_stream_init(&s, /*seed=*/0);
komihash_stream_update(&s, chunk1, n1);
komihash_stream_update(&s, chunk2, n2);
uint64_t h2 = komihash_stream_final(&s);

// Matching PRNG:
komirand_t r;
komirand_init(&r, /*seed=*/12345);
uint64_t x = komirand(&r);
```

## References
- <https://github.com/avaneev/komihash>
