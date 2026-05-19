<!-- generated-from-dump2 -->
# doctest Single-Header Test Framework

Single-header C++ test framework. The differentiator vs Catch2: compile time. Doctest is written so the public header is small and macro-light, the test-runner implementation hides behind `#define DOCTEST_CONFIG_IMPLEMENT` in exactly one TU, and you can compile-disable everything via `DOCTEST_CONFIG_DISABLE` so production builds carry zero overhead. Practical effect: drop `TEST_CASE` blocks next to the code they exercise (same TU as the unit under test) without paying for it in non-test builds. Same expression-decomposition trick as Catch2 (`CHECK(a == b)` prints both operands) but ~10x faster to compile in large codebases.

```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

TEST_CASE("factorial of small ints") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(5) == 120);

    SUBCASE("negative inputs collapse to 1") {
        CHECK(factorial(-3) == 1);
    }
}
```

## References
- <https://github.com/doctest/doctest>
