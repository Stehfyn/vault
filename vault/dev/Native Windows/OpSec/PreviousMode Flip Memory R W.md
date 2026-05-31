# PreviousMode Flip Memory R/W

The `PreviousMode` technique abuses a kernel bookkeeping field that tells system calls whether arguments originated from user mode or kernel mode. Research tools use it to explain why a tiny kernel write primitive can invalidate much larger user/kernel trust assumptions.

The defensive lesson is version sensitivity and blast radius. Offsets vary, primitives are usually obtained through BYOVD or a vulnerable driver, and post-action telemetry may look like ordinary native memory APIs rather than a custom driver protocol. Connect this to `User-Mode Physical Memory Library`, `PPL Killer`, and `Direct Page Table Manipulation`.

Structure-level route:

```text
small kernel write primitive
  -> thread/requestor trust metadata changes
  -> native memory syscall sees kernel-mode trust context
  -> ordinary-looking user-mode caller performs sensitive memory access
```

This is the inverse of the cheat-driver IOCTL pattern. Instead of every read/write crossing a custom device protocol, a small kernel-side state change can make later NT memory APIs look deceptively normal. For reversing, preserve OS build, thread context, native API name, and whether a vulnerable driver appeared earlier in the timeline.

## References
- <https://github.com/SamuelTulach/meme-rw>
