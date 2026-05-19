<!-- generated-from-dump2 -->
# cpr — C++ Requests HTTP Client

"C++ Requests" — a thin, ergonomic C++11/14 wrapper over libcurl that copies the Python `requests` API surface (`cpr::Get`, `cpr::Post`, `Url{}`, `Header{}`, `Body{}`, `Authentication{}`, ...). The point is to spare you the libcurl handle/option/setopt dance for the 95% case of "fetch this URL, give me bytes and a status code." Synchronous by default, but ships an Async API that returns `cpr::AsyncResponse` (a future) and a session pool you can reuse for keep-alive connections. Doesn't try to compete with Boost.Beast or cpp-httplib on the server side — strictly an HTTP client.

```cpp
#include <cpr/cpr.h>

auto r = cpr::Get(
    cpr::Url{"https://api.example.com/users"},
    cpr::Header{{"Authorization", "Bearer " + token}},
    cpr::Parameters{{"page", "2"}, {"limit", "50"}},
    cpr::Timeout{5000}                       // ms
);
if (r.status_code == 200) std::cout << r.text;

auto post = cpr::Post(
    cpr::Url{"https://api.example.com/items"},
    cpr::Body{R"({"name":"foo"})"},
    cpr::Header{{"Content-Type", "application/json"}}
);

// Async
cpr::AsyncResponse fut = cpr::GetAsync(cpr::Url{"https://example.com/"});
auto resp = fut.get();
```

## References
- <https://github.com/libcpr/cpr>
