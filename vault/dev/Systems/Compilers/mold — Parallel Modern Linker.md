<!-- generated-from-dump2 -->
# mold — Parallel Modern Linker

Rui Ueyama's modern linker. ~5-10x faster than GNU ld / gold and ~2x faster than LLVM lld at link time, by aggressively parallelizing every phase: relocation processing, output section assembly, symbol resolution. Notable design: relies heavily on multi-pass design where the first pass scans inputs in parallel to build a complete symbol table, then the assembly pass writes the output file in parallel using `mmap` + `pwrite` to disjoint regions. Drop-in replacement for `ld` / `ld.gold`; many distros now offer it.

```text
# Use mold by symlinking it as ld, or invoke explicitly:
$ clang -fuse-ld=mold main.c -o main

# Or for cargo / rust:
$ RUSTFLAGS="-C linker-flavor=gcc -C link-arg=-fuse-ld=mold" cargo build

# Benchmark on the Chromium link (~3 GB output binary):
#   GNU ld:    ~50  s
#   gold:      ~30  s
#   lld:       ~8   s
#   mold:      ~2.5 s
```

## References
- <https://github.com/rui314/mold>
