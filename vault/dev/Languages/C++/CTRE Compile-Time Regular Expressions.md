<!-- generated-from-dump2 -->
# CTRE Compile-Time Regular Expressions

Hana Dusíková's CTRE library — write `auto m = ctre::match<"\\w+\\s+\\w+">(s);` and the regex is *parsed and compiled to specialized code at compile time*. No runtime regex engine, no `std::regex` heap allocation, no pattern-string-to-DFA conversion in your hot path. Generated code typically runs 3-10x faster than `std::regex` and 1.5-3x faster than RE2 / Hyperscan for matching (not search across megabytes — Hyperscan still wins there). The cost is compile time and the C++20 NTTP-string requirement. CTRE is now the default recommendation for "I have a fixed regex baked into my code" in modern C++; `std::regex` remains for "the regex comes from user input."

```cpp
#include <ctre.hpp>

if (auto m = ctre::match<"(\\d{4})-(\\d{2})-(\\d{2})">("2026-05-17")) {
    auto year  = m.get<1>().to_view();   // "2026"
    auto month = m.get<2>().to_view();   // "05"
    auto day   = m.get<3>().to_view();   // "17"
    std::cout << year << '/' << month << '/' << day;
}

// Search vs match:
for (auto&& m : ctre::range<"\\w+">(text))
    process(m.to_view());
```

## References
- <https://github.com/hanickadot/compile-time-regular-expressions>
