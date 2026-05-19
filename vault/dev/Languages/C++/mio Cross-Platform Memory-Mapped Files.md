<!-- generated-from-dump2 -->
# mio Cross-Platform Memory-Mapped Files

Cross-platform header-only C++11 memory-mapped file IO. Wraps `mmap` on POSIX and `CreateFileMapping`/`MapViewOfFile` on Windows under one interface — `mio::mmap_source` (read-only), `mio::mmap_sink` (read-write), or `mio::ummap_source` (untyped, byte-level). Lets the OS page in only the regions you touch, so reading a 50GB log file becomes a `std::ifstream::read`-free `std::string_view` over the mapped pages. Key correctness detail: handles offset alignment to the page granularity, returns the requested logical offset via a small adjusted-pointer accessor, so you don't have to round manually. Lighter than Boost.Iostreams; Sopel C++17 `<filesystem>`-friendly.

```cpp
#include <mio/mmap.hpp>

std::error_code ec;
mio::mmap_source m = mio::make_mmap_source("/var/log/syslog", ec);
if (ec) { /* handle */ }

std::string_view view(m.data(), m.size());
auto pos = view.find("ERROR");
if (pos != std::string_view::npos)
    std::cout << view.substr(pos, 80) << '\n';
```

## References
- <https://github.com/vimpunk/mio>
