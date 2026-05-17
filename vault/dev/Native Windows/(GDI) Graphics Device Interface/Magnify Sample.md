Magnify10 is a lightweight Windows magnifier using the Magnification API with global hotkeys and a periodic refresh timer for the lens.

```cpp
#include <magnification.h>
#pragma comment(lib, "magnification.lib")

MagInitialize();
HWND hwndMag = CreateWindowEx(0, WC_MAGNIFIER, L"", WS_CHILD | WS_VISIBLE,
    0, 0, 300, 200, hwndHost, nullptr, hInstance, nullptr);

RECT rc = { x, y, x + sourceWidth, y + sourceHeight };
MagSetWindowSource(hwndMag, rc);

// MagSetWindowTransform for zoom factor
MAGTRANSFORM transform;
memset(&transform, 0, sizeof(transform));
transform.v[0][0] = 2.0f; // 2x zoom
transform.v[1][1] = 2.0f;
transform.v[2][2] = 1.0f;
MagSetWindowTransform(hwndMag, &transform);
```

## References
1. https://github.com/chrishermans/magnify
