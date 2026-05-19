<!-- generated-from-dump2 -->
# TurboStitchGIF — Embedded GIF Decoder

Single-header C GIF decoder targeted at MCUs and constrained environments — the whole point is no `malloc`/`free`, so the caller pre-supplies every buffer (palette, LZW dictionary, frame canvas) and the library only does in-place work. This pattern (caller-owned memory, header-only) is how anything actually ships on a Cortex-M with a few hundred KB of RAM, where dynamic allocation either doesn't exist or causes fragmentation death over long uptimes. Decoding cost is dominated by the LZW unpack and the indexed-to-RGB blit; everything else is bookkeeping.

```c
// Conceptual usage — consult the project's header for actual symbol names.
// The library expects you to feed bytes incrementally and call back per scanline
// or per frame; no internal state owns memory it didn't get from you.
uint8_t canvas[W * H];           // indexed framebuffer, caller-owned
uint8_t lzw_workspace[4096 * 4]; // dictionary memory, caller-owned
// init_decoder(&dec, canvas, sizeof(canvas), lzw_workspace, sizeof(lzw_workspace));
// while (have_bytes) feed_decoder(&dec, chunk, n);
// on_frame_complete -> push canvas to display via your SPI/parallel driver
```

## References
- <https://github.com/Ferki-git-creator/TurboStitchGIF-HeaderOnly-Fast-ZeroAllocation-PlatformIndependent-Embedded-C-GIF-Decoder>
