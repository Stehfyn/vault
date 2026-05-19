<!-- generated-from-dump2 -->
# FastNoiseLite — Coherent Noise Library

Single-file portable coherent-noise library: Perlin, OpenSimplex2 (F & S variants), Cellular (Worley), Value noise, all with fractal / FBM stacking and domain warping. Ported to C, C++, C#, Java, HLSL, GLSL, JavaScript, Rust, Go — same parameters and output across all bindings, which matters when you generate terrain on a GPU shader and need the CPU to query the same value for collision queries / chunk streaming. Successor to Auburn's older FastNoise (which had a SIMD variant `FastNoiseSIMD`); the "Lite" rename is because the SIMD path was dropped in favor of portability. The OpenSimplex2 implementation is the standout — it's the only widely-used port of the OS2 algorithm that's also been audited for visual quality.

```cpp
#include "FastNoiseLite.h"

FastNoiseLite n;
n.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
n.SetFrequency(0.01f);
n.SetFractalType(FastNoiseLite::FractalType_FBm);
n.SetFractalOctaves(4);

for (int y = 0; y < 256; ++y)
for (int x = 0; x < 256; ++x) {
    float v = n.GetNoise((float)x, (float)y);   // [-1, 1]
    heightmap[y*256 + x] = (v + 1.0f) * 0.5f;
}
```

```glsl
// HLSL/GLSL version is a generated single-file include with identical params
#include "FastNoiseLite.hlsl"
float h = fnlGetNoise2D(state, uv.x, uv.y);
```

## References
- <https://github.com/Auburn/FastNoiseLite>
