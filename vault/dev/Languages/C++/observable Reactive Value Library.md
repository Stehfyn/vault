<!-- generated-from-dump2 -->
# observable Reactive Value Library

C++14 header-only reactive primitives: `observable<T>` is a value that fires subscribers on change, `observe(expr)` lifts a normal C++ expression of observables into a derived observable that auto-recomputes when any input changes. Closest analogue is Knockout/MobX's `computed`, but compile-time-typed and value-based. The clever bit is the expression-template `observe(...)`: it returns a node graph whose recomputation is invalidated lazily, so chains like `c = observe(a + b * 2)` only re-evaluate when actually read. Useful for game/UI state where you want one source of truth and derived views that stay coherent without a manual update step.

```cpp
#include <observable/observable.hpp>
using observable::observable;

observable<int> a = 1;
observable<int> b = 2;

auto sum = observe(a + b);                    // derived; recomputes lazily
auto sub = sum.subscribe([](int v){ std::cout << "sum=" << v << '\n'; });

a = 10;     // prints "sum=12"
b = 5;      // prints "sum=15"
```

## References
- <https://github.com/ddinu/observable>
