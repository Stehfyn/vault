<!-- generated-from-dump2 -->
# AeonProfiler — Native Windows Sampler

Instrumented sampling profiler for native Windows applications. Authors mark functions with macros that record entry/exit timestamps via `QueryPerformanceCounter`; the viewer shows hierarchical call counts, inclusive/exclusive time, and per-thread breakdowns. Aimed at game engines where Tracy/VTune feel heavyweight.

```cpp
#include "AeonProfiler.h"

void Tick() {
    AEON_PROFILE_FUNCTION();
    {
        AEON_PROFILE_SCOPE("Physics");
        StepPhysics();
    }
    {
        AEON_PROFILE_SCOPE("Render");
        RenderFrame();
    }
}
```

## References
- <https://github.com/botman99/AeonProfiler>
