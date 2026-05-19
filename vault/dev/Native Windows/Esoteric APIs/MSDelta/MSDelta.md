# MSDelta

MSDelta is Windows' native binary-delta facility: produce a delta from a known source blob to a target blob, then apply that delta later when the same source is available. That makes it closer to servicing/update technology than to ZIP-style compression; the value is minimizing update payloads while preserving exact target reconstruction.

The important operational details are source identity and memory ownership. A delta is only meaningful against the intended source version, and successful `CreateDeltaB`/`ApplyDeltaB` calls return buffers that must be released with `DeltaFree`. Connect this to `msdelta.h`, Windows servicing notes, and high-performance file-copy entries where the tradeoff is CPU and metadata discipline versus transferred bytes.

## References
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/msdelta>
