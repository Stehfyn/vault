# Compressapi.h

The Win8-introduced compression service in `cabinet.dll` (`Compression API`). Supports four algorithms -- `COMPRESS_ALGORITHM_MSZIP`, `XPRESS`, `XPRESS_HUFF`, `LZMS` -- accessed through the same `CreateCompressor` / `Compress` / `CreateDecompressor` / `Decompress` shape. XPRESS / XPRESS-Huff are the algorithms `pagefile.sys` compression, NTFS file-level compression (`compact /exe:LZX`), Windows Update payloads, and Hyper-V VHDX-set use; LZMS is what `compact /exe:LZX` rebrands and gives substantially better ratios at the cost of speed. Notably the API does *not* do gzip / deflate / zstd -- for those you still want zlib, libdeflate, or BCryptDecrypt-adjacent CNG primitives. Cluster: `wim.h` (WIM uses XPRESS/LZMS), `xpress.h` (older kernel-mode XPRESS).

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/compressapi/>
- <https://learn.microsoft.com/en-us/windows/win32/cmpapi/-compression-portal>
