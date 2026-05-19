<!-- generated-from-dump2 -->
# LLFIO Low-Level Async File IO (P1031)

Reference implementation of WG21 P1031 "Low Level File I/O" — the standardization push for the C++ standard library to grow real, asynchronous, race-free file I/O. Covers things `<filesystem>` deliberately ducked: race-free directory operations using `*at()` syscalls, byte-range file locking, memory-mapped files with concurrent writer detection, `io_uring`/IOCP-backed async ops, and file-system-aware path canonicalization that doesn't TOCTOU.

```cpp
#include <llfio.hpp>
namespace llfio = LLFIO_V2_NAMESPACE;

// Race-free mkdir-then-open relative to an existing directory handle.
auto dh = llfio::directory({}, "/tmp").value();
auto fh = llfio::file(dh, "data.bin",
                      llfio::file_handle::mode::write,
                      llfio::file_handle::creation::always_new).value();

// Scatter-gather write with explicit O_DSYNC semantics.
llfio::file_handle::const_buffer_type bufs[] = {
    {(const std::byte*)header, headerLen},
    {(const std::byte*)body,   bodyLen  },
};
fh.write({bufs, 0}).value();
```

## References
- <https://github.com/ned14/llfio>
