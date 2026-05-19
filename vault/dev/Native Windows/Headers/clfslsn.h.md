# clfslsn.h

Inline-only helpers for CLFS Log Sequence Number (`CLFS_LSN`) arithmetic. An LSN is opaquely a 64-bit value, but it packs `(container_id, block_offset, record_sequence)` -- comparing two LSNs as raw `ULONGLONG`s is *wrong* across container reuse, so CLFS exposes `ClfsLsnEqual`, `ClfsLsnLess`, `ClfsLsnGreater`, `ClfsLsnNull`, `ClfsLsnInvalid`, `ClfsLsnIsInValid`, `ClfsLsnContainer`, `ClfsLsnBlockOffset`, `ClfsLsnRecordSequence`. These are macros / `__inline` functions, so they don't pull in a separate import -- they're cheap to use anywhere a CLFS LSN comparison is needed. Pair with `clfs.h` for the structures and `clfsw32.h` / `Clfsw32.h` for the user-mode call interface.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/clfslsn/>
