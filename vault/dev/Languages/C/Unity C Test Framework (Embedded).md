<!-- generated-from-dump2 -->
# Unity C Test Framework (Embedded)

Lightweight C unit-testing framework targeted at embedded development. (Unrelated to the game engine.) Header-light, no malloc, runs on bare-metal MCUs with just a `puts`-equivalent. The interesting design choices: assertions stringify both sides via the preprocessor for diagnostic output (`TEST_ASSERT_EQUAL_INT(a, b)` prints both expressions and values on failure), and the runner is a code generator (the `generate_test_runner.rb` script) that scans your test file and emits a `_Runner.c` calling each `test_*` function - sidesteps the lack of reflection.

```c
#include "unity.h"

void test_addition_should_be_associative(void) {
    int a = 2, b = 3, c = 4;
    TEST_ASSERT_EQUAL_INT(a + (b + c), (a + b) + c);
}

void test_strings_match(void) {
    TEST_ASSERT_EQUAL_STRING("hello", greet());
}

// The generator emits main() that calls each test_* + RUN_TEST.
```

## References
- <https://github.com/ThrowTheSwitch/Unity>
