# ExtremeCopy — Unbuffered Explorer Copy Replacement

Replacement for Explorer's copy/move dialog focused on raw throughput on Windows. Bypasses `CopyFileEx`'s default 64 KiB chunking and goes through unbuffered I/O (`FILE_FLAG_NO_BUFFERING` + sector-aligned buffers + overlapped reads/writes) so it can saturate fast NVMe or 10 GbE SMB targets. Hooks into the shell as a "drop-in" replacement via the `IExplorerCommand` extension and `INFO_DELETE`/`INFO_RENAME` paths so it kicks in transparently when you Ctrl+C/V in Explorer.

## References
- <https://github.com/kevinwu1024/ExtremeCopy>
