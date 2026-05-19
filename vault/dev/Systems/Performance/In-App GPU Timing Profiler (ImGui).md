<!-- generated-from-dump2 -->
# In-App GPU Timing Profiler (ImGui)

In-app GPU profiler that renders a hierarchical timing view inside a Dear ImGui window. Backends for OpenGL (`glQueryCounter`/`GL_TIMESTAMP`) and Vulkan (`vkCmdWriteTimestamp` + query pools) issue GPU timestamps around scoped regions; the UI bars are stacked per-frame so you can drag a marker and inspect any historical frame.

```cpp
#include "InAppGpuProfiler.h"
iagp::Init(); // create context, query pools

// In your render loop:
iagp::BeginFrame();
{
    iagp::ScopedZone z("Shadow Pass");
    DrawShadows();
}
{
    iagp::ScopedZone z("GBuffer");
    DrawGBuffer();
}
iagp::EndFrame();

iagp::DrawImGui(); // shows per-zone GPU ms history
```

## References
- <https://github.com/aiekick/InAppGpuProfiler>
