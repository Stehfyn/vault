<!-- generated-from-dump2 -->
# dbg-macro — Rust dbg! Port for C++

David Peter's port of Rust's `dbg!()` macro to C++. Lets you write `dbg(expr)` anywhere; expands to "print the file:line, the stringified expression, and the value with type info, returning the value". Cheap printf-debugging that's git-able (you can grep for `dbg(` to remove all the markers before commit). Uses `__PRETTY_FUNCTION__`-based pretty-printers for many STL containers without forcing operator<<.

```cpp
#include <dbg.h>

int n = dbg(compute(5));     // [main.cpp:7 (foo)] compute(5) = 25 (int)
auto v = dbg(std::vector<int>{1,2,3}); // [main.cpp:8 (foo)] std::vector{...} = {1, 2, 3} (std::vector<int>)
```

## References
- <https://github.com/sharkdp/dbg-macro>
