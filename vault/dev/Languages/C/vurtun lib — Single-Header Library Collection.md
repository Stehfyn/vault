<!-- generated-from-dump2 -->
# vurtun lib — Single-Header Library Collection

Micha Mettke's single-header library scrapyard — small, self-contained C/C++ headers covering the corners you don't want to depend on a framework for. Notable inclusions: `mmx` (geometric primitives, JSON parser, fixed-point), `nuklear`-precursor immediate-mode GUI experiments, audio (panner, sinc resampler), and assorted numerical recipes. Same authorial style as Nuklear: zero external deps, drop into your project, configure with `#define` toggles before include.

```c
// Idiomatic usage — one header per concern, configure before include.
#define MMX_GEOMETRY_IMPLEMENTATION
#include "mmx_geometry.h"

struct mmx_vec3 a = {1,2,3}, b = {4,5,6};
struct mmx_vec3 c = mmx_vec3_add(a, b);     // {5,7,9}
```

## References
- <https://github.com/vurtun/lib>
