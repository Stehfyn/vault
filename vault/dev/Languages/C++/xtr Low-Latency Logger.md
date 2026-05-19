<!-- generated-from-dump2 -->
# xtr Low-Latency Logger

C++ logger in the same niche as `quill` and NanoLog: dedicated background thread does all formatting and I/O so the call site is "copy args into an SPSC ring buffer and return." The differentiator is the API — log statements look like printf, but the format string is parsed at compile time (constexpr) and only the binding *arguments* are pushed onto the ring, with formatting deferred to the consumer thread. Numeric arguments are passed by value (no allocations on the hot path), strings are copied once into the ring. Reported latency: tens of nanoseconds on the producer side. Aimed at HFT / trading / market-data pipelines.

```cpp
#include <xtr/logger.hpp>

xtr::logger log;                  // background formatting+IO thread
auto sink = log.get_sink("trader"); // per-thread sink avoids contention

// Compile-time format parse, args pushed to SPSC ring; no formatting here.
XTR_LOG(sink, "Filled {} @ {} px on {}", qty, px, symbol);

// Background thread later pulls the record, formats, and writes to stdout/file.
```

## References
- <https://github.com/choll/xtr>
