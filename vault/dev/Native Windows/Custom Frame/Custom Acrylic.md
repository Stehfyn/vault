# Custom Acrylic

Classic Win32 acrylic can be approximated using the undocumented `SetWindowCompositionAttribute` with an `ACCENT_POLICY`.

```cpp
#include <windows.h>

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

auto setWca = (pfnSetWindowCompositionAttribute)
    GetProcAddress(GetModuleHandleW(L"user32.dll"), "SetWindowCompositionAttribute");

ACCENT_POLICY policy = { ACCENT_ENABLE_ACRYLICBLURBEHIND, 0, 0xCC202020, 0 };
WINDOWCOMPOSITIONATTRIBDATA data = { 19, &policy, sizeof(policy) };
if (setWca) setWca(hwnd, &data);
```

## References
- https://github.com/Maplespe/Win32CustomAcrylic
- https://github.com/Maplespe/Win32CustomAcrylic/blob/main/Win32CustomAcrylic/Win32CustomAcrylic.cpp
- https://stackoverflow.com/questions/44000217/mimicking-acrylic-in-a-win32-app
- https://github.com/ALTaleX531/Win32Acrylic?tab=readme-ov-file
- https://github.com/ALTaleX531/OpenGlass
