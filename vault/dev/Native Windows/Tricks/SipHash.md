# SipHash

SipHash is a fast keyed hash designed for hash table security (defeating hash-flooding attacks). It uses two 64-bit keys and a small round function. Python's dict and Rust's HashMap use it by default.

```cpp
// SipHash-2-4 implementation sketch
// Full spec: https://github.com/veorq/SipHash
#include <stdint.h>
#include <string.h>

#define ROTL(x,b) (uint64_t)(((x) << (b)) | ((x) >> (64-(b))))
#define SIP_ROUND(v0,v1,v2,v3) do { \
    v0+=v1; v1=ROTL(v1,13); v1^=v0; v0=ROTL(v0,32); \
    v2+=v3; v3=ROTL(v3,16); v3^=v2; \
    v0+=v3; v3=ROTL(v3,21); v3^=v0; \
    v2+=v1; v1=ROTL(v1,17); v1^=v2; v2=ROTL(v2,32); } while(0)

uint64_t SipHash24(const void* in, size_t inlen, const uint8_t key[16]) {
    uint64_t k0, k1;
    memcpy(&k0, key,   8);
    memcpy(&k1, key+8, 8);
    uint64_t v0 = k0 ^ 0x736f6d6570736575ULL;
    uint64_t v1 = k1 ^ 0x646f72616e646f6dULL;
    uint64_t v2 = k0 ^ 0x6c7967656e657261ULL;
    uint64_t v3 = k1 ^ 0x7465646279746573ULL;
    // ... process 8-byte blocks with SIP_ROUND x2 each
    // finalize with SIP_ROUND x4 and v0^v1^v2^v3
    return v0 ^ v1 ^ v2 ^ v3; // simplified
}
```

Hash table usage: generate random key[16] once per process start. This prevents an attacker who knows your hash function from crafting inputs that all land in the same bucket.

## References
- https://github.com/veorq/SipHash?tab=readme-ov-file
