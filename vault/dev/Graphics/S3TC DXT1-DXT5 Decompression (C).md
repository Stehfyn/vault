<!-- generated-from-dump2 -->
# S3TC DXT1/DXT5 Decompression (C)

Compact reference implementation of S3TC/DXT1 and DXT5 block decompression in C — same problem space as Anteru/dxt-decompress but with a slightly different API surface (single-function decode of a whole texture rather than per-block). Useful as a drop-in when you can't link a real image lib (e.g., embedded, kernel-mode tooling, or shader-tool plumbing).

```c
// Decompress a DXT5 surface to RGBA8888.
// width/height are in texels and must be multiples of 4 (or pad before calling).
void BlockDecompressImageDXT5(unsigned long width,
                              unsigned long height,
                              const unsigned char* blockStorage,
                              unsigned long* image);
```

## References
- <https://github.com/Benjamin-Dobell/s3tc-dxt-decompression>
