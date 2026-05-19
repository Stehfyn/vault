<!-- generated-from-dump2 -->
# BS Thread Pool

Single-header C++17/20/23 thread pool — submit any callable, get back a `std::future`. The pool is a `std::vector<std::thread>` pulling from a shared `std::queue<std::function<void()>>` behind a `std::mutex` / `std::condition_variable`, plus a `BS::synced_stream` helper for thread-safe cout. Deliberately not lock-free or work-stealing: the design priority is correctness, readability, and zero dependencies, with a single header you drop into a project. Bench-competitive enough for typical workloads but loses to work-stealing pools (TBB, enkiTS, taskflow) on fine-grained recursive tasks where the central mutex becomes a bottleneck.

```cpp
#include <BS_thread_pool.hpp>
#include <iostream>

int main() {
    BS::thread_pool pool;                          // hardware_concurrency threads

    auto sum_future = pool.submit_task([]{
        int s = 0;
        for (int i = 1; i <= 100; ++i) s += i;
        return s;
    });

    pool.detach_loop(0, 1000, [](int i) {
        // runs in parallel across the pool
    });
    pool.wait();

    std::cout << sum_future.get() << '\n';
}
```

## References
- <https://github.com/bshoshany/thread-pool>
