<!-- generated-from-dump2 -->
# Quill — Async Low-Latency C++ Logger

Header-mostly async C++ logging library aimed at low-latency trading and game-server workloads. Hot path enqueues formatted args into a lock-free SPSC ring per thread; a dedicated backend thread does the actual `vsnprintf` and sink I/O, keeping caller latency in the tens-of-nanoseconds range.

```cpp
#include "quill/Backend.h"
#include "quill/Frontend.h"
#include "quill/Logger.h"
#include "quill/sinks/ConsoleSink.h"

int main() {
    quill::Backend::start();
    auto sink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>("con");
    quill::Logger* log = quill::Frontend::create_or_get_logger("root", std::move(sink));
    LOG_INFO(log, "tick={} price={:.2f}", 42, 101.75);
}
```

## References
- <https://github.com/odygrd/quill>
