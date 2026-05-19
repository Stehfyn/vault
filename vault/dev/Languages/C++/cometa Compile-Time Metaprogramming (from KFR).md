<!-- generated-from-dump2 -->
# cometa Compile-Time Metaprogramming (from KFR)

Compile-time meta-programming utility belt extracted from the KFR DSP library. Provides CTTI (compile-time type information without RTTI), constexpr string manipulation, a `result<T, error>` discriminated-union sum type, named arguments, compile-time arrays and algorithms over them. Niche but cohesive — KFR uses it internally for SIMD type dispatch and FFT plan selection, so the utilities are battle-tested in tight loops. Overlaps with Hana (heterogenous algorithms), magic_enum (enum reflection), and tl::expected; you would adopt cometa if you already depend on KFR or want the bundle behind one header tree.

```cpp
#include <cometa.hpp>
using namespace cometa;

// CTTI: stable hashable type name without RTTI
constexpr auto name = ctti::type_id<int>().name();   // "int"

// constexpr array operations
constexpr auto xs   = cometa::cval<int, 1, 2, 3, 4>;
constexpr auto ys   = cometa::map(xs, [](auto x){ return x * x; });

// result<T, e_status>: error-code-ish sum type
result<int, e_status> parse(const char* s);
```

## References
- <https://github.com/kfrlib/cometa>
