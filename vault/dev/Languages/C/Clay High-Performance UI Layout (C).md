<!-- generated-from-dump2 -->
# Clay High-Performance UI Layout (C)

High-performance UI layout library in pure C - single-header, zero-allocation, fully retained-mode-like declarative syntax via clever C macros. The unusual design points: (1) layout is computed in a single pass over a fixed-size arena that you preallocate, no heap; (2) the syntax uses statement-expression macros (`CLAY({...attrs}, { CLAY_TEXT("hi"); })`) to make C feel like JSX; (3) renders by emitting a flat list of `Clay_RenderCommand` for any back-end (SDL, raylib, even ASCII). Fast enough to compete with most immediate-mode UI libraries for static layouts.

```c
#include "clay.h"

uint64_t arena_size = Clay_MinMemorySize();
void* mem = malloc(arena_size);
Clay_Arena arena = Clay_CreateArenaWithCapacityAndMemory(arena_size, mem);
Clay_Initialize(arena, (Clay_Dimensions){800, 600},
                (Clay_ErrorHandler){HandleError});

Clay_BeginLayout();
CLAY(CLAY_ID("root"),
     CLAY_LAYOUT({ .padding = {16, 16},
                   .childGap = 8,
                   .layoutDirection = CLAY_TOP_TO_BOTTOM }))
{
    CLAY_TEXT(CLAY_STRING("Hello"),
              CLAY_TEXT_CONFIG({ .fontSize = 18 }));
    CLAY(CLAY_LAYOUT({ .sizing = { .width = CLAY_SIZING_GROW(0) }}),
         CLAY_RECTANGLE({ .color = {255,0,0,255} })) {}
}
Clay_RenderCommandArray cmds = Clay_EndLayout();
// hand cmds to your renderer
```

## References
- <https://github.com/nicbarker/clay>
