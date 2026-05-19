<!-- generated-from-dump2 -->
# qlibs mph — Compile-Time Perfect Hash

C++20 *minimal* perfect-hash function generator that runs entirely at compile time. Give it a `constexpr` list of keys, get back a `constexpr` lookup that maps each known key to a unique slot in [0, N) with no collisions and no probing. Same problem space as `gperf` and `frozen::unordered_map`, but unlike `gperf` (external codegen) it's a pure header, and unlike `frozen` it actually computes a *minimal* perfect hash (every slot used) rather than just an open-addressed constexpr table. Useful for tokenizers, opcode dispatch tables, HTTP header recognizers, anywhere you have a known set of <1000 strings/ints and want guaranteed O(1) lookup with the smallest possible table.

```cpp
#include <mph>

constexpr auto keywords = std::array{
    std::pair{"if",     1},
    std::pair{"else",   2},
    std::pair{"while",  3},
    std::pair{"return", 4},
};

constexpr auto lookup = mph::hash<keywords>{};
static_assert(lookup("while") == 3);
static_assert(lookup("nope")  == 0);   // sentinel
```

## References
- <https://github.com/qlibs/mph>
