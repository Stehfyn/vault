<!-- generated-from-dump2 -->
# Boost-ext UT Unit Testing Framework

Kris Jusiak's C++20 micro unit-testing framework — header-only, no macros for assertions (uses operator overloading + `_test` UDLs), comparable feature surface to Catch2/doctest but in ~1k LOC. The C++20 dependency is real: it leans on concepts, source_location, lambdas as parameters, and consteval to get the "no-macros" feel. If you're stuck on C++17 or care about LLVM-libstdc++ portability that's still rough on C++20, doctest stays the safer pick; on a clean C++20 toolchain `ut` produces shorter call sites and faster compiles than either of the major frameworks.

```cpp
#include <boost/ut.hpp>
using namespace boost::ut;

int sum(int a, int b) { return a + b; }

int main() {
    "sum"_test = [] {
        expect(sum(2, 3) == 5_i);
        expect(sum(-1, 1) == 0_i);
    };

    "edge cases"_test = [] {
        given("an empty input") = [] {
            when("we sum") = [] {
                then("we get zero") = [] {
                    expect(sum(0, 0) == 0_i);
                };
            };
        };
    };
}
```

## References
- <https://github.com/boost-ext/ut>
