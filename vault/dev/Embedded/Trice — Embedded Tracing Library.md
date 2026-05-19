<!-- generated-from-dump2 -->
# Trice — Embedded Tracing Library

Embedded-friendly tracing library with NanoLog-style offline-decoding semantics: at compile time, a preprocessor stage replaces each `TRICE("fmt", args)` call site with a 16-bit id + raw argument bytes; at runtime, you only ship the bytes over UART/RTT/USB; a host-side decoder reconstructs the formatted message. Designed for ISR-safe use on bare-metal MCUs, which is also why the Windows-tracing comparison comes up. Wrong subdir for the same reason as NanoLog — should be in `vault/dev/Embedded/`.

```c
#include "trice.h"
void irq_handler(void) {
    TRICE16( "msg:fast: count=%d, status=0x%04x\n", counter, status );
    // Emits ~6-8 bytes to the ring buffer, no formatting, no malloc.
}
```

## References
- <https://github.com/rokath/trice>
