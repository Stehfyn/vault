<!-- generated-from-dump2 -->
# Frozen Constexpr Containers

Header-only constexpr immutable containers — `frozen::map`, `frozen::set`, `frozen::unordered_map`, `frozen::string` — built entirely at compile time. Direct alternative to `gperf` (the GNU perfect-hash generator) for the "I have a fixed table of 200 keywords and want O(1) lookup with no startup cost" case, except you stay in C++ instead of dropping into an external code generator. The hash function is selected at compile time and the storage is a constexpr array, so the lookup compiles down to a few memory loads and a comparison. Sergey "serge-sans-paille" Guelton (LLVM, Pythran).

```cpp
#include <frozen/unordered_map.h>
#include <frozen/string.h>

constexpr frozen::unordered_map<frozen::string, int, 4> table = {
    {"red",   1},
    {"green", 2},
    {"blue",  3},
    {"alpha", 4},
};

static_assert(table.at("green") == 2);            // pure compile-time
int v = table.at(user_input);                      // runtime lookup, no heap
```

## References
- <https://github.com/serge-sans-paille/frozen>
