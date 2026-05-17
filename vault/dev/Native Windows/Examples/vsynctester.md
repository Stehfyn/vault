Browser-based VSync timing tester that measures frame delivery jitter using `requestAnimationFrame` callbacks. It alternates red/cyan frames at 60 Hz; if any frame is dropped the color becomes visible to the eye, making synchronization problems immediately apparent. On the Win32 side, `DwmGetCompositionTimingInfo` provides equivalent VBlank interval data for native applications.

```cpp
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

// Measure VBlank intervals via DWM composition timing
DWM_TIMING_INFO ti = {};
ti.cbSize = sizeof(ti);
DwmGetCompositionTimingInfo(NULL, &ti);  // NULL = desktop window

// ti.qpcRefreshPeriod  -- QPC ticks per refresh cycle
// ti.qpcVBlank         -- QPC time of last VBlank
// ti.cRefresh          -- total refresh count since DWM start
// ti.cFrameComplete    -- frames completed by DWM

LARGE_INTEGER freq;
QueryPerformanceFrequency(&freq);
double refreshMs = (double)ti.qpcRefreshPeriod / freq.QuadPart * 1000.0;
printf("Refresh period: %.3f ms (%.2f Hz)\n", refreshMs, 1000.0 / refreshMs);
```

## References

- <https://www.vsynctester.com/manual.html>
