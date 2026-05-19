<!-- generated-from-dump2 -->
# NanoLog — Nanosecond Logging Library

Stanford PlatformLab's logging library that hits nanoseconds per log call by deferring all formatting to an offline decoder. At compile time, a clang plugin extracts the format string and per-call argument types; at runtime, each log statement only writes raw arguments + an integer log-id into a thread-local ring buffer. The decoder side replays format strings against the binary log. Wrong subdir — not actually ETW, though the design lessons (offline decode, no formatting on the hot path) apply directly to writing ETW providers. Should be in `vault/dev/Systems/Performance/`.

```cpp
#include "NanoLogCpp17.h"
NANO_LOG(NOTICE, "Processed %d packets from %s", count, peer);
// Compiles to roughly: ringbuf.write(LOGID_42); ringbuf.write(count); ringbuf.write(peer);
// No printf, no snprintf, no allocation. Decoder produces the formatted string later.
```

## References
- <https://github.com/PlatformLab/NanoLog>
