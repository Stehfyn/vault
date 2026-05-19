# PreviousMode Flip Memory R/W

The `PreviousMode` technique abuses a kernel bookkeeping field that tells system calls whether arguments originated from user mode or kernel mode. Research tools use it to explain why a tiny kernel write primitive can invalidate much larger user/kernel trust assumptions.

The defensive lesson is version sensitivity and blast radius. Offsets vary, primitives are usually obtained through BYOVD or a vulnerable driver, and post-action telemetry may look like ordinary native memory APIs rather than a custom driver protocol. Connect this to `User-Mode Physical Memory Library`, `PPL Killer`, and `Direct Page Table Manipulation`.

## References
- <https://github.com/SamuelTulach/meme-rw>
