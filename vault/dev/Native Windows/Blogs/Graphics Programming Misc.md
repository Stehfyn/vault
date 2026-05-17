# Graphics Programming Notes

Collected graphics programming references: shader techniques, profiling visualization, and algorithm articles.

## Flamegraphs vs Treemaps vs Sunburst (Brendan Gregg)

Flamegraphs are the most actionable for CPU profiling: call stack width = time. Treemaps show hierarchy by area. Sunbursts combine both but are harder to read quickly. For sampling profilers, flamegraphs should be the default.

```cpp
// Collecting stack samples for a flamegraph (Windows)
// Use ETW/WPR or CaptureStackBackTrace:
void* frames[64] = {};
USHORT depth = CaptureStackBackTrace(0, 64, frames, nullptr);
// Map frame addresses to symbols via SymFromAddr (DbgHelp)
// Output format: "func1;func2;func3 count" per sample
```

## Game Boy Shader Palette

Classic GB palette maps 2-bit grayscale to 4 fixed colors. Achievable in HLSL by quantizing luminance to [0,3] and indexing a palette array.

```hlsl
// HLSL Game Boy palette shader
static const float4 GB_PALETTE[4] = {
    float4(0.059f, 0.220f, 0.059f, 1.0f),  // darkest
    float4(0.188f, 0.384f, 0.188f, 1.0f),
    float4(0.545f, 0.675f, 0.059f, 1.0f),
    float4(0.608f, 0.737f, 0.059f, 1.0f),  // lightest
};
float4 main(float2 uv : TEXCOORD) : SV_TARGET {
    float gray = dot(tex.Sample(s, uv).rgb, float3(0.299f, 0.587f, 0.114f));
    int idx = (int)(gray * 3.9999f);
    return GB_PALETTE[clamp(idx, 0, 3)];
}
```

## References
- https://www.brendangregg.com/blog/2017-02-06/flamegraphs-vs-treemaps-vs-sunburst.html
- https://blog.otterstack.com/posts/202512-gbshader/
