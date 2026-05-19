<!-- generated-from-dump2 -->
# Nuklear — Single-Header ANSI C Immediate-Mode GUI

Single-header ANSI C immediate-mode GUI library — Dear ImGui's older C cousin. No backend coupling: you call Nuklear to build a vertex/index buffer, then hand it to whatever renderer you have (GL/D3D/Vulkan/software). Distinct from ImGui in being plain C (FFI-friendly) and explicitly *not* relying on C++ statics for per-frame state — context is an explicit argument everywhere.

```c
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_IMPLEMENTATION
#include "nuklear.h"

struct nk_context ctx;
nk_init_default(&ctx, &font);
if (nk_begin(&ctx, "win", nk_rect(50,50, 220, 200),
             NK_WINDOW_BORDER|NK_WINDOW_TITLE|NK_WINDOW_MOVABLE)) {
    nk_layout_row_static(&ctx, 30, 80, 1);
    if (nk_button_label(&ctx, "OK")) { /* clicked */ }
}
nk_end(&ctx);
```

## References
- <https://github.com/Immediate-Mode-UI/Nuklear>
