<!-- generated-from-dump2 -->
# Boost.PFR Aggregate Reflection

"Pretty Flat Reflection" — aggregate-only static reflection for C++14/17 with **zero macros and zero registration**. The implementation pulls a famous trick: detects how many members an aggregate has by trying `T{Any{}, Any{}, ...}` brace-initialization with increasing pack sizes and using SFINAE to find the largest one that compiles, then uses structured bindings to pull out each member as an l-value. So plain `struct Point { int x, y; };` becomes `boost::pfr::get<0>(p)`, `tuple_size_v<decltype(p)> == 2`, `for_each_field(p, ...)` without you writing anything. Limits: aggregates only (no constructors, no inheritance, no private members) and there is no portable way to recover member *names* on C++17 (C++20 adds it via `__PRETTY_FUNCTION__` parsing).

```cpp
#include <boost/pfr.hpp>

struct Point { int x, y, z; };
Point p{1, 2, 3};

std::cout << boost::pfr::get<0>(p);             // 1
std::cout << boost::pfr::tuple_size_v<Point>;   // 3

boost::pfr::for_each_field(p, [](auto&& f, std::size_t i){
    std::cout << i << " = " << f << '\n';
});

// I/O for free:
std::cout << boost::pfr::io(p);   // {1, 2, 3}
```

## References
- <https://github.com/boostorg/pfr>
