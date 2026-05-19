<!-- generated-from-dump2 -->
# Async++ Task and Future Library

C++11 task / future library by Amanieu d'Antras (also author of `hashbrown` upstream that became Rust's `HashMap`). Predates `std::experimental::future::then` and remains relevant because the *standard* `std::future` still has no continuation support — `Async++` gives you `.then()`, `when_all`, `when_any`, parallel `for`, and a real scheduler under it. Pre-C++20-coroutines this was the standard answer for "I want JavaScript-style promise chaining in C++". With coroutines you'd reach for concurrencpp or cppcoro first, but Async++ still wins on C++11/14 targets and on platforms where coroutines are still flaky.

```cpp
#include <async++.h>

auto t1 = async::spawn([]{ return 21; });
auto t2 = t1.then([](int x){ return x * 2; });

std::cout << t2.get() << '\n';   // 42

async::parallel_for(async::irange(0, 1'000'000), [&](int i){
    data[i] = work(i);
});

auto all = async::when_all(
    async::spawn(load_a),
    async::spawn(load_b),
    async::spawn(load_c));
auto [a, b, c] = all.get();
```

## References
- <https://github.com/Amanieu/asyncplusplus>
