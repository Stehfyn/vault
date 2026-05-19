<!-- generated-from-dump2 -->
# Boost.LexicalCast Text Conversion

The original `boost::lexical_cast<T>(x)` — text-to-anything and anything-to-text conversion through a uniform interface. In modern C++ it has been almost entirely superseded by `std::to_chars` / `std::from_chars` (faster, locale-independent, no exceptions, since C++17) for numerics, and by `std::format` / `std::ostringstream` for the other direction. `lexical_cast` still survives where the conversion needs to flow through user-defined `operator<<` / `operator>>` or when the codebase already depends on Boost. Historically it was widely abused for hot-path conversions and showed up in profiles because the implementation routed through an internal `stringstream`.

```cpp
#include <boost/lexical_cast.hpp>

int    i = boost::lexical_cast<int>("42");
double d = boost::lexical_cast<double>("3.14");
auto   s = boost::lexical_cast<std::string>(123);

try {
    int bad = boost::lexical_cast<int>("hello");
} catch (const boost::bad_lexical_cast& e) {
    // not a number
}
```

## References
- <https://github.com/boostorg/lexical_cast>
