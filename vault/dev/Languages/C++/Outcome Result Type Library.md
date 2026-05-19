<!-- generated-from-dump2 -->
# Outcome Result Type Library

Niall Douglas's exception-alternative for C++. Three vocabulary types: `result<T, E>` (T or E, no payload extras), `outcome<T, EC, E>` (T or EC or E + payload pointer), `checked<T, E>` (same as result but undefined behavior to use without checking). The interesting design choice vs `std::expected` is the explicit "error code with payload" layering: `outcome` carries both a `std::error_code` and an optional exception pointer/string so you can layer "fatal exception escaped" on top of "expected error" within one type. Drives many of the proposals that became `std::expected<T,E>` in C++23.

```cpp
#include <outcome.hpp>
namespace oc = OUTCOME_V2_NAMESPACE;

oc::result<int> parse(std::string_view s) {
    if (s.empty()) return std::errc::invalid_argument;
    return std::stoi(std::string(s));            // success
}

if (auto r = parse("42"); r) {
    use(r.value());
} else {
    log(r.error().message());
}

// "try"-style propagation:
OUTCOME_TRY(auto n, parse(s));                   // unwraps or returns the error
```

## References
- <https://github.com/ned14/outcome>
