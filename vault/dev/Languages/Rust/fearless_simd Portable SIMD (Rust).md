<!-- generated-from-dump2 -->
# fearless_simd Portable SIMD (Rust)

Linebender's (Vello / Druid / Xilem authors) Rust SIMD wrapper aimed at portable rasterizer code — same "length-agnostic, runtime-dispatched, target-feature-detected" approach as `google/highway` for C++, but with a Rust-native trait-based interface. The "fearless" framing: write your kernel once against generic `Simd<T>` trait methods, and a single binary contains optimized AVX-512, AVX2, NEON, and WASM-SIMD paths dispatched at startup based on what the CPU advertises. The motivation is Vello specifically — a GPU-first 2D renderer that still wants a fast CPU fallback path for headless/offscreen rendering — but the crate is independent and re-usable. Less mature than `std::simd` (still nightly-only in std) and `wide`/`pulp`; worth watching because the Linebender team has shipped non-trivial production code on top of it.

```rust
use fearless_simd::*;

fn dot(a: &[f32], b: &[f32]) -> f32 {
    fn kernel<S: Simd>(simd: S, a: &[f32], b: &[f32]) -> f32 {
        let mut acc = simd.splat_f32(0.0);
        for (ca, cb) in a.chunks_exact(S::LANES).zip(b.chunks_exact(S::LANES)) {
            acc = simd.fma_f32(simd.load_f32(ca), simd.load_f32(cb), acc);
        }
        simd.reduce_sum_f32(acc)
    }
    dispatch!(|simd| kernel(simd, a, b))    // pick best impl at runtime
}
```

## References
- <https://github.com/linebender/fearless_simd>
