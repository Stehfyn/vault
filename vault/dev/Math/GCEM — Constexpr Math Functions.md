<!-- generated-from-dump2 -->
# GCEM — Constexpr Math Functions

`<cmath>` reimplemented as `constexpr` so transcendentals are usable at compile time (`gcem::sqrt`, `gcem::exp`, `gcem::log`, `gcem::sin`, `gcem::erf`, `gcem::gamma`, `gcem::beta`, ...). Uses CORDIC/Padé approximations and term-by-term series evaluation written with `if constexpr` branches so the compiler can fold them. Important for compile-time math (lookup table generation, constexpr physics constants) — the standard `<cmath>` is implementation-defined and almost never `constexpr` even today.

```cpp
#include <gcem.hpp>

constexpr double tau     = 2.0 * gcem::acos(-1.0);
constexpr double rad     = gcem::sin(tau / 4);      // ~1.0, at compile time
constexpr auto   sigma2  = gcem::exp(-0.5);          // ~0.6065
static_assert(sigma2 > 0.6 && sigma2 < 0.61);
```

## References
- <https://github.com/kthohr/gcem>
