<!-- generated-from-dump2 -->
# looking-glass Aggregate Reflection

C++17 static reflection for aggregate types — iterate fields, get count, names (via stringification trick), apply visitors. Implemented with the Type Loophole / structured-binding-deduction technique pioneered by alexpolt/luple and Antony Polukhin's Boost.PFR. Distinguishes itself by being header-only with no Boost dependency and a tighter API.

```cpp
#include <looking-glass/reflect.hpp>

struct Point { float x, y, z; };

Point p{ 1.f, 2.f, 3.f };
lg::for_each_field(p, [](auto& v){ std::cout << v << " "; });
// 1 2 3

constexpr auto n = lg::field_count<Point>();   // 3, at compile time
```

## References
- <https://github.com/nitronoid/looking-glass>
