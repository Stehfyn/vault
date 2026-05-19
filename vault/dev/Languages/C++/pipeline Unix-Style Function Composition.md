<!-- generated-from-dump2 -->
# pipeline Unix-Style Function Composition

Header-only C++17 "Unix-pipe-style" function composition with `operator|`. Lets you build data-processing pipelines as `input | transform | filter | sink` instead of nested function calls or `std::ranges` boilerplate. Predates `std::ranges` becoming widely available; on C++17 toolchains where ranges still feel awkward (Apple Clang, MSVC older than 2019.x) it scratched the same itch with less template machinery. On C++20+ you'd reach for `std::views` first, but pipeline is shorter to drop in and supports stateful sinks (e.g. accumulators) more naturally than `std::ranges` does.

```cpp
#include <pipeline/pipeline.hpp>
namespace p = pipeline;

auto pipe =
    p::fn([](int x){ return x * x; })
    | p::fn([](int x){ return x + 1; })
    | p::fn([](int x){ std::cout << x << '\n'; });

pipe(3);                  // prints 10
```

## References
- <https://github.com/p-ranav/pipeline>
