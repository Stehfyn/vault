<!-- generated-from-dump2 -->
# FunctionalPlus Functional Utility Belt

Header-only C++14 functional-programming utility belt — `map`, `filter`, `fold_left`, `zip_with`, `group_by`, `transform_with_idx`, hundreds of small algorithms named after their Haskell / Clojure equivalents and operating on any container with iterators. The point is *discoverability*: instead of writing `std::accumulate` + custom lambda and hoping a reviewer remembers what it does, you write `fplus::sum(xs)` or `fplus::count_occurrences(xs)`. Predates `std::ranges` and remains more readable than range adapters for one-off transformations because each function has a verb name rather than a pipe chain. Trade-off: it does eager evaluation and copies — for big data you still want `std::ranges` views.

```cpp
#include <fplus/fplus.hpp>

auto xs    = std::vector<int>{1, 2, 3, 4, 5, 6};
auto evens = fplus::keep_if([](int x){ return x % 2 == 0; }, xs);
auto sqs   = fplus::transform([](int x){ return x * x; }, evens);
auto sum   = fplus::sum(sqs);                              // 56

auto pairs = fplus::zip(xs, fplus::numbers(0, (int)xs.size()));
auto words = fplus::split_words(false, std::string{"hello there world"});
```

## References
- <https://github.com/Dobiasd/FunctionalPlus>
