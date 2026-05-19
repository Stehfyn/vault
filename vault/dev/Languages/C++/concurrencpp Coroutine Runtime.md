<!-- generated-from-dump2 -->
# concurrencpp Coroutine Runtime

C++20 task/coroutine runtime with executors, timers, channels, and a `result<T>` future type — basically what `std::execution` (P2300) is going to standardize, but available today on plain C++20. The model: every async operation returns `result<T>`, every suspension point names the executor it resumes on (`co_await my_executor->submit(...)`), so the scheduling policy is part of the type-system rather than implicit. Solves the "where does my continuation run?" hazard that bare `std::future` and Asio's coroutine integration leave to the user. Competes with cppcoro (Lewis Baker, deprecated), Folly's coro stack, and Asio's coroutine support.

```cpp
#include <concurrencpp/concurrencpp.h>

concurrencpp::result<int> work(concurrencpp::executor_tag,
                               std::shared_ptr<concurrencpp::thread_pool_executor> tpe)
{
    co_await tpe->submit([]{ /* heavy CPU here */ });
    co_return 42;
}

int main() {
    concurrencpp::runtime runtime;
    auto tpe = runtime.thread_pool_executor();
    auto r   = work({}, tpe);
    std::cout << r.get() << '\n';
}
```

## References
- <https://github.com/David-Haim/concurrencpp>
