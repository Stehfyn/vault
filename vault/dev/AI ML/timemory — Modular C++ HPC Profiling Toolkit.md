<!-- generated-from-dump2 -->
# timemory — Modular C++ HPC Profiling Toolkit

NERSC's modular C++ performance-analysis toolkit — a *framework* for building profilers rather than a single profiler. You compose `tim::component_tuple<wall_clock, cpu_util, peak_rss, cuda_event>` and the library handles start/stop/aggregation/output. Used in HPC contexts to wrap MPI ranks. Has Python/Fortran/CUDA bindings and works as a `LD_PRELOAD` profiler too.

```cpp
#include <timemory/timemory.hpp>
using tim::component::wall_clock;
using tim::component::peak_rss;
using bundle_t = tim::component_tuple<wall_clock, peak_rss>;

void hot_loop(int n) {
    TIMEMORY_AUTO_BUNDLE(bundle_t, "hot_loop");
    for (int i = 0; i < n; ++i) work(i);
}

int main(int argc, char** argv) {
    tim::timemory_init(argc, argv);
    hot_loop(1'000'000);
    tim::timemory_finalize();      // prints / writes JSON of all bundles
}
```

## References
- <https://github.com/NERSC/timemory>
