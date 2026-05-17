# Accent Colorizer

Read the current system accent color and apply it to a custom acrylic/blur layer via `ACCENT_POLICY`.

```cpp
#include <windows.h>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

enum ACCENT_STATE {
    ACCENT_DISABLED = 0,
    ACCENT_ENABLE_ACRYLICBLURBEHIND = 4
};

struct ACCENT_POLICY {
    int AccentState;
    int AccentFlags;
    DWORD GradientColor; // AABBGGRR
    int AnimationId;
};

struct WINDOWCOMPOSITIONATTRIBDATA {
    int Attrib; // WCA_ACCENT_POLICY = 19
    PVOID pvData;
    SIZE_T cbData;
};

using pfnSetWindowCompositionAttribute =
    BOOL (WINAPI*)(HWND, WINDOWCOMPOSITIONATTRIBDATA*);

DWORD color = 0;
BOOL opaque = FALSE;
DwmGetColorizationColor(&color, &opaque);

ACCENT_POLICY policy = { ACCENT_ENABLE_ACRYLICBLURBEHIND, 0, color, 0 };
WINDOWCOMPOSITIONATTRIBDATA data = { 19, &policy, sizeof(policy) };

auto setWca = (pfnSetWindowCompositionAttribute)
    GetProcAddress(GetModuleHandleW(L"user32.dll"), "SetWindowCompositionAttribute");
if (setWca) setWca(hwnd, &data);
```

## References
- https://github.com/krlvm/AccentColorizer
