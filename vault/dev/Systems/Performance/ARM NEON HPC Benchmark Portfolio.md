<!-- generated-from-dump2 -->
# ARM NEON HPC Benchmark Portfolio

Ashton Six's collection of ARM-NEON-tuned HPC writeups and reproducible benchmarks targeting Graviton4 / Neoverse V2. Notable entries: **NEON Bytepack** (~1.9x throughput vs scalar for bit-pack/unpack), **NEON Delta Coding** (~1.5-2.2x for delta/XOR decode), **BSPX** (bitset compression claimed 46% smaller than Roaring + RLE on test data), and **P4Synth** (boolean-function synthesizer reporting ~1000x faster than a SAT baseline). Worth reading not just for the numbers but the methodology — each subdirectory ships its own harness and reports cycles-per-byte rather than wall-time, so the comparisons survive different host configurations.

```cpp
// Flavour of the work: NEON-vectorized bit unpack from a packed 5-bit stream
// to uint8_t array. Real implementations live under the project's neon-bytepack/.
//
// uint8x16_t mask  = vdupq_n_u8((1<<5) - 1);
// uint8x16_t lo    = vld1q_u8(src);
// uint8x16_t hi    = vld1q_u8(src + 16);
// // shifts + ORs to realign nibbles spanning byte boundaries, then mask.
// uint8x16_t out0  = vandq_u8(vshrq_n_u8(lo, 0), mask);
// uint8x16_t out1  = vandq_u8(vshrq_n_u8(lo, 5), mask);
// vst1q_u8(dst,     out0);
// vst1q_u8(dst+16,  out1);
```

## References
- <https://github.com/ashtonsix/perf-portfolio>
