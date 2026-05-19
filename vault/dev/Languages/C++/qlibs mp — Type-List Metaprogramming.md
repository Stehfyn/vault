<!-- generated-from-dump2 -->
# qlibs mp — Type-List Metaprogramming

Kris Jusiak's C++20 meta-programming kernel — type lists with `transform`, `filter`, `fold`, `unique`, `sort`, `find`, etc., all expressed in terms of *function objects on a `type_list`* rather than nested template recursion. Roughly equivalent to Boost.MP11 in spirit (Peter Dimov's small "modern" type list lib) but tuned for C++20 concepts and shorter compile times. The qlibs family (`qlibs/mp`, `qlibs/reflect`, `qlibs/mph`, `qlibs/sml`) consistently goes for "sub-1000 LOC, fast compile, no Boost, single header" so they fit together cleanly.

```cpp
#include <mp>
namespace mp = boost::mp;

using ts   = mp::type_list<int, double, char, float>;
using ints = mp::filter<std::is_integral, ts>::type;   // type_list<int, char>

constexpr auto n = mp::size_v<ts>;                     // 4
using last       = mp::back<ts>::type;                 // float
```

## References
- <https://github.com/qlibs/mp>
