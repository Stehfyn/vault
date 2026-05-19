<!-- generated-from-dump2 -->
# termbench — Terminal Throughput Benchmark

The benchmark Casey Muratori built to embarrass the Windows Terminal team: writes a known stream of styled characters to stdout, measures throughput in MB/s and time-per-frame, and compares terminals on identical input. The non-obvious finding (which kicked off a public dispute with Microsoft) was that Windows Terminal in 2021 was orders of magnitude slower than even early-90s conhost or a basic SDL-based renderer, despite hardware-accelerated text rendering being a solved problem. Useful both as a reproducible test for your own terminal work and as an early example of "actually measure it" debate culture.

```c
// Conceptual: emit a fixed-size payload of colored cells and measure wall time.
// (Real harness lives in termbench.cpp; outputs MB/s and ms/frame.)
char Buffer[64 * 1024];
size_t n = 0;
for (int y = 0; y < ROWS; ++y) {
    for (int x = 0; x < COLS; ++x) {
        // SGR truecolor + glyph
        n += sprintf(&Buffer[n], "\x1b[38;2;%d;%d;%dmW", (x*4)&0xFF, (y*4)&0xFF, 128);
    }
    n += sprintf(&Buffer[n], "\x1b[0m\n");
}
// Pump it repeatedly, time both the emit + flush:
auto t0 = now();
for (int i = 0; i < N_FRAMES; ++i) fwrite(Buffer, 1, n, stdout);
fflush(stdout);
double sec = now() - t0;
printf("%.2f MB/s\n", (N_FRAMES * (double)n) / sec / 1e6);
```

## References
- <https://github.com/cmuratori/termbench>
