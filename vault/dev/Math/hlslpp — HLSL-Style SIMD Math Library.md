<!-- generated-from-dump2 -->
# hlslpp — HLSL-Style SIMD Math Library

C++ math library whose API mimics HLSL - `float4`, `float4x4`, swizzles, `dot`, `cross`, `mul`, `transpose`, with the same operator overloads - backed by SSE/NEON/Wasm SIMD intrinsics. Useful for shader-style CPU code (skinning, frustum culling, AABB intersections) where you want the prototype to read like the shader you'll port it to. Notable for supporting `float4` writes via swizzle (`v.xyz = u.yzx`) by template-overloading the proxy.

```cpp
#include "hlsl++.h"

using namespace hlslpp;

float4   v(1, 2, 3, 4);
float4   u = v.zyxw;          // swizzle read
v.xy = u.zw;                  // swizzle write

float4x4 m  = float4x4::translation(float3(1, 0, 0));
float4   pt = mul(m, float4(0, 0, 0, 1));   // (1,0,0,1)
```

## References
- <https://github.com/redorav/hlslpp>
