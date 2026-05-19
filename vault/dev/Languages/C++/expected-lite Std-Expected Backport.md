<!-- generated-from-dump2 -->
# expected-lite Std-Expected Backport

Single-header backport of C++23's `std::expected<T, E>` (a sum type "value or error") that compiles on C++11 onwards. Necessary because `std::expected` only landed in libstdc++/libc++ very recently (around 2024), so any code that wants the Either-style error type today and still has to support older toolchains uses this. API matches the standard closely (`.value()`, `.error()`, `.and_then()`, `.transform_error()`, monadic chaining) so migration is mostly `using nonstd::expected;` → `using std::expected;`. Same family as tl::expected (Sy Brand) — they're API-compatible-ish; expected-lite is part of Martin Moene's "nonstd-lite" backport suite.

```cpp
#include <nonstd/expected.hpp>
#include <string>

nonstd::expected<int, std::string> parse(const std::string& s) {
    try { return std::stoi(s); }
    catch (...) { return nonstd::make_unexpected("not a number"); }
}

auto r = parse("42")
    .and_then([](int n){ return nonstd::expected<int, std::string>{n * 2}; })
    .transform_error([](auto&& e){ return "parse: " + e; });

if (r) std::cout << *r;
else   std::cerr << r.error();
```

## References
- <https://github.com/nonstd-lite/expected-lite>
