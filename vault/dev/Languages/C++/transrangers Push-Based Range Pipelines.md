<!-- generated-from-dump2 -->
# transrangers Push-Based Range Pipelines

Joaquín M López Muñoz's experiment in "push" range pipelines. Standard ranges (`views::transform | views::filter | ...`) are pull-based: the sink calls `++it` repeatedly, each stage decorates the iterator. transrangers invert the dataflow: the source pushes elements through a chain of callables until a stopping condition. Empirically generates better code for filtered pipelines (no double-stepping past filtered-out elements), at the cost of being one-shot and non-storable.

```cpp
#include <transrangers/all.hpp>
namespace tr = transrangers;

std::vector<int> v{1,2,3,4,5,6,7,8,9,10};

tr::all(v)
  | tr::filter([](int x){ return x % 2 == 0; })
  | tr::transform([](int x){ return x * x; })
  | tr::for_each([](int x){ std::cout << x << "\n"; });
// 4 16 36 64 100  — single fused loop, no per-stage iterator state.
```

## References
- <https://github.com/joaquintides/transrangers>
