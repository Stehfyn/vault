<!-- generated-from-dump2 -->
# EVE Expressive Vector Engine SIMD

"Expressive Vector Engine" — Joel Falcou's C++20 SIMD wrapper, successor of Boost.SIMD. Distinguished from `google/highway` (length-agnostic, runtime dispatch) and `xsimd` (Numscale-derived, narrower scope) by emphasizing a *very* large library of pre-built numeric functions (transcendentals, statistics, integer specials, complex arithmetic) that are auto-vectorized over the SIMD lane type. So `eve::sin(x)` works on `eve::wide<float>` and gives you a vectorized sin without you writing the polynomial approximation yourself. C++20-only (requires concepts), which is the cost of admission for the clean overload sets.

```cpp
#include <eve/eve.hpp>
#include <eve/wide.hpp>
#include <eve/function/sin.hpp>

void vec_sin(const float* in, float* out, std::size_t n) {
    using wide_f = eve::wide<float>;
    auto W = wide_f::size();
    std::size_t i = 0;
    for (; i + W <= n; i += W) {
        wide_f x{&in[i]};
        eve::store(eve::sin(x), &out[i]);
    }
    for (; i < n; ++i) out[i] = std::sin(in[i]);
}
```

## References
- <https://github.com/jfalcou/eve>
