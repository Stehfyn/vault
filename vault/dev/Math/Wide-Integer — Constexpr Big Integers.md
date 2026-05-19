<!-- generated-from-dump2 -->
# Wide-Integer — Constexpr Big Integers

Header-only C++14 template for arbitrary-width fixed-size unsigned/signed integers — `uintwide_t<Digits, LimbType>` where Digits is bit width (must be a power of two ≥ 16) and LimbType picks the limb (`uint32_t`, `uint64_t`). Same author as Boost.Multiprecision; this lib is the opposite tradeoff: no allocations, fully constexpr, embeddable on bare-metal microcontrollers. Notable that the I/O (decimal print/parse) and division are also constexpr — you can compute a 2048-bit RSA modular inverse at compile time. Used for RSA, ECDSA, Miller-Rabin primality on MCUs where you can't afford GMP.

```cpp
#include <math/wide_integer/uintwide_t.h>

using uint256_t = ::math::wide_integer::uint256_t;

constexpr uint256_t a("0x0123456789ABCDEF0123456789ABCDEF"
                      "0123456789ABCDEF0123456789ABCDEF");
constexpr uint256_t b("0xFEDCBA98765432100123456789ABCDEF"
                      "FEDCBA98765432100123456789ABCDEF");

constexpr uint256_t c = (a * b) % uint256_t("0x"
                      "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC2F");
static_assert(c != uint256_t(0));   // multiplied + mod-reduced at compile time
```

## References
- <https://github.com/ckormanyos/wide-integer>
