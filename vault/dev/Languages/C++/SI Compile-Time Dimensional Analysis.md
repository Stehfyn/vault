<!-- generated-from-dump2 -->
# SI Compile-Time Dimensional Analysis

Header-only C++17 implementation of compile-time dimensional analysis (length/time/mass/...) with SI user-defined literals. Same idea as Boost.Units and `mp-units` but without external deps and with a smaller surface — `123_m`, `4.5_s`, division yields `metre_per_second_t`, multiplication of incompatible dimensions is a compile error rather than a silent bug. Useful for embedded / robotics / aerospace code where mistaking radians for degrees has destroyed actual hardware. Trade-off: error messages are the usual cryptic template avalanche, and ABI changes between library versions because the unit types are encoded into the symbol.

```cpp
#include <SI/length.h>
#include <SI/time.h>
using namespace SI::literals;

auto distance = 100_m;
auto duration = 9.58_s;       // Bolt's 100m
auto speed    = distance / duration;   // -> metre_per_second_t
// auto bad   = distance + duration;   // compile error: mismatched dimensions

double v_in_kph = speed.to<SI::kilo_metre_per_hour_t>().value();
std::cout << v_in_kph << " km/h\n";
```

## References
- <https://github.com/bernedom/SI>
