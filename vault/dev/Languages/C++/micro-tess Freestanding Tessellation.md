<!-- generated-from-dump2 -->
# micro-tess Freestanding Tessellation

Header-only C++11 vector-graphics tessellation library — converts paths, polygons, and stroked curves into triangle strips/fans suitable for a GPU or a software rasterizer. Deliberately freestanding: no `<algorithm>`, no `<vector>`, no `<cmath>`, no FPU required (you template on a `number` type that can be fixed-point Q15.16). That makes it usable on microcontrollers and inside hot rendering loops where `std::vector` allocations are unacceptable. Companion to `micro-gl` (the same author's CPU rasterizer); analogous to libtess2 but with allocator/number type as policy.

```cpp
#include <micro-tess/tess_simple.h>
#include <micro-tess/dynamic_array.h>

using namespace microtess;
using number = float;
using arr_v  = dynamic_array<vec2<number>>;
using arr_i  = dynamic_array<int>;

arr_v polygon = { {0,0}, {100,0}, {100,100}, {0,100} };
arr_v out_verts;
arr_i out_indices;

triangulate_simple<number, arr_v, arr_i>::compute(
    polygon, out_verts, out_indices,
    triangles::indices::TRIANGLES);
```

## References
- <https://github.com/micro-gl/micro-tess>
