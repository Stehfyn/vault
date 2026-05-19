<!-- generated-from-dump2 -->
# oneTBB Threading Building Blocks

oneAPI Threading Building Blocks - Intel's open-source C++ task-parallel library, now under the UXL Foundation. Differs from `std::thread`/OpenMP by exposing work as `task_group` / `parallel_for` against a work-stealing scheduler whose number of workers is `std::thread::hardware_concurrency` by default. Notable features: `concurrent_hash_map` / `concurrent_queue` / `concurrent_vector` (lock-free where possible), and `flow::graph` for explicit dataflow networks. Drop-in for OpenMP in scientific codes when you want C++ rather than pragmas.

```cpp
#include <oneapi/tbb.h>

oneapi::tbb::parallel_for(
    oneapi::tbb::blocked_range<size_t>(0, n),
    [&](const auto& r){
        for (size_t i = r.begin(); i != r.end(); ++i) out[i] = work(in[i]);
    });

// Flow graph: source -> mul -> sink, with implicit parallelism
oneapi::tbb::flow::graph g;
oneapi::tbb::flow::function_node<int, int> mul(g, oneapi::tbb::flow::unlimited,
    [](int x){ return x*2; });
oneapi::tbb::flow::function_node<int> sink(g, oneapi::tbb::flow::serial,
    [](int x){ std::cout << x << "\n"; });
oneapi::tbb::flow::make_edge(mul, sink);
for (int i = 0; i < 5; ++i) mul.try_put(i);
g.wait_for_all();
```

## References
- <https://github.com/uxlfoundation/oneTBB>
