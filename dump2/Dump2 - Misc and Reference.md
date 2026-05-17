# Dump2 - Misc and Reference

Starred repositories that are reference collections, unconventional implementations, or projects of general interest.

---

## fffaraz/awesome-cpp
https://github.com/fffaraz/awesome-cpp

The canonical C/C++ awesome list (71k stars). Curated collection of frameworks, libraries, and resources. Useful as a discovery tool for: compression (zlib, lz4, zstd), JSON parsing, concurrency primitives, serialization, testing frameworks, and graphics libraries. The JSON and serialization sections are especially dense.

```cpp
// Notable picks from the list:
// nlohmann/json    - header-only JSON with STL-like API
// fmtlib/fmt       - fast formatting library (now std::format basis)
// abseil-cpp       - Google's production C++ base library
// doctest          - lightweight test framework, header-only
// Catch2           - heavier but more features, BDD style
// GSL              - Microsoft's Guideline Support Library (span, not_null)
// taskflow         - modern C++ task graph parallelism

#include "nlohmann/json.hpp"
using json = nlohmann::json;
json j = {{"name", "test"}, {"value", 42}};
std::string s = j.dump(); // '{"name":"test","value":42}'
```

---

## kavishdevar/librepods
https://github.com/kavishdevar/librepods

Reverse-engineered AirPods protocol implementation for Linux/Android (27k stars). Documents the undocumented BLE AAP (Apple Accessory Protocol) used by AirPods for ear detection, battery status, case status, and noise cancellation control. Relevant for: BLE protocol RE, custom firmware for wireless audio, and understanding how Apple devices communicate over standard BLE with proprietary attributes.

```kotlin
// librepods: parse AirPods battery status from BLE advertisement
// Apple uses manufacturer-specific data (type 0xFF, company 0x004C)
// The battery packet format:
// Byte 0: 0x07 (type)
// Bytes 1-2: left/right/case battery (nibbles)
// Byte 3: status flags (in-ear, lid open, etc.)
fun parseBattery(data: ByteArray): BatteryStatus {
    val left  = (data[2].toInt() and 0xF0) shr 4
    val right = (data[2].toInt() and 0x0F)
    val case  = (data[3].toInt() and 0xF0) shr 4
    return BatteryStatus(left * 10, right * 10, case * 10)
}
```

---

## carlini/c-chat-gpt-2
https://github.com/carlini/c-chat-gpt-2

GPT-2 inference implemented in pure C (226 stars), no dependencies. Implements the transformer forward pass by hand: layer norm, multi-head attention with KV cache, MLP with GELU. The entire network fits in ~500 lines. A useful reference for understanding the exact numerical operations in a transformer at the level of raw `float` arrays.

```c
// Simplified transformer attention in C (carlini style)
void attention(float* q, float* k, float* v, float* out,
               int seq_len, int n_heads, int head_dim) {
    float scale = 1.0f / sqrtf((float)head_dim);
    for (int h = 0; h < n_heads; h++) {
        float* qh = q + h * head_dim;
        float attn_scores[MAX_SEQ] = {};
        // QK^T / sqrt(d)
        for (int t = 0; t <= seq_len; t++) {
            float* kh = k + t * n_heads * head_dim + h * head_dim;
            float dot = 0;
            for (int d = 0; d < head_dim; d++) dot += qh[d] * kh[d];
            attn_scores[t] = dot * scale;
        }
        softmax(attn_scores, seq_len + 1);
        // Weighted sum of V
        float* oh = out + h * head_dim;
        for (int t = 0; t <= seq_len; t++) {
            float* vh = v + t * n_heads * head_dim + h * head_dim;
            for (int d = 0; d < head_dim; d++) oh[d] += attn_scores[t] * vh[d];
        }
    }
}
```

---

## microsoft/TRELLIS
https://github.com/microsoft/TRELLIS

Microsoft's structured 3D latent generation model (12.6k stars, CVPR'25 Spotlight). Generates 3D assets from images/text using a latent diffusion model operating in a SLAT (Structured Latent) space that separates geometry from appearance. Relevant for game/graphics pipelines wanting AI-generated mesh+texture assets.

```python
# TRELLIS inference
from trellis.pipelines import TrellisImageTo3DPipeline
pipeline = TrellisImageTo3DPipeline.from_pretrained("JeffreyXiang/TRELLIS-image-large")
pipeline.cuda()

outputs = pipeline.run(
    image,
    seed=42,
    sparse_structure_sampler_params={"steps": 12, "cfg_strength": 7.5},
    slat_sampler_params={"steps": 12, "cfg_strength": 3.0},
)
# outputs["gaussian"] -- 3D Gaussian Splatting representation
# outputs["radiance_field"] -- NeRF-style
# outputs["mesh"] -- textured triangle mesh
```

---

## NASA-SW-VnV/ikos (see Systems and Tools)

---

## zigcc/awesome-zig
https://github.com/zigcc/awesome-zig

Curated Zig library and resource list (2.3k stars). Key sections: build system integrations (Zig's build.zig can replace CMake), C interop libraries, and comptime-heavy data structure implementations. Zig's comptime + `@cImport` makes it the cleanest way to wrap C headers without writing bindings by hand.

```zig
// Zig's @cImport: include C headers directly, no binding generator
const c = @cImport({
    @cInclude("windows.h");
    @cInclude("commctrl.h");
});

pub fn main() void {
    _ = c.InitCommonControlsEx(&.{
        .dwSize = @sizeOf(c.INITCOMMONCONTROLSEX),
        .dwICC  = c.ICC_WIN95_CLASSES,
    });
}
```
