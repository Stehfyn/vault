<!-- generated-from-dump2 -->
# Google Highway Portable SIMD

Google's portable C++ SIMD wrapper. The differentiator: **length-agnostic** — you describe operations on a logical "vector of T" without committing to a specific lane count (`Vec<D>` where `D` is the descriptor), and the library compiles to the right ISA at runtime (SSE2/SSE4/AVX2/AVX-512 on x86, NEON on ARM, SVE on ARMv9, WASM SIMD on the web, RVV on RISC-V). Used inside JPEG XL (Highway is from the JPEG XL team) and now widely adopted as the SIMD layer in Chrome/V8/Skia. Big wins over Boost.SIMD / xsimd / nsimd: cleaner ABI (no per-ISA type aliases leaking into your code) and explicit support for *scalable* (length-unknown-at-compile-time) ISAs like SVE/RVV.

```cpp
#include <hwy/highway.h>

namespace hw = hwy::HWY_NAMESPACE;

void mul_add(const float* HWY_RESTRICT a, const float* HWY_RESTRICT b,
             const float* HWY_RESTRICT c, float* HWY_RESTRICT out, size_t n) {
    const hw::ScalableTag<float> d;          // descriptor
    const size_t lanes = hw::Lanes(d);
    size_t i = 0;
    for (; i + lanes <= n; i += lanes) {
        auto va = hw::LoadU(d, a + i);
        auto vb = hw::LoadU(d, b + i);
        auto vc = hw::LoadU(d, c + i);
        hw::StoreU(hw::MulAdd(va, vb, vc), d, out + i);
    }
    for (; i < n; ++i) out[i] = a[i] * b[i] + c[i];   // scalar tail
}
```

## References
- <https://github.com/google/highway>
