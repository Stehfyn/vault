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

## Source Code Reading

`Maplespe/Win32CustomAcrylic` goes beyond the SWCA snippet. `Win32CustomAcrylic/CustomAcrylic.cpp` builds a WinRT Composition effect brush over a backdrop:

- `CustomAcrylic::Initialize(HWND)` creates a `DispatcherQueueController` and `Compositor`.
- It obtains `ICompositorDesktopInterop` and calls `CreateDesktopWindowTarget(hwnd, false, ...)`.
- `CreateD2DResource` creates D2D, D3D11, DXGI, WIC, and `ICompositionGraphicsDevice`.
- It creates a virtual drawing surface and surface brush for `Noise_256X256.png`.
- `CreateEffects` assigns the final brush to the root `SpriteVisual`.

Reduced effect graph:

```text
Backdrop -> GaussianBlur(40, Hard)
Blur -> Saturation(2.0)
Noise texture -> Border(Wrap) -> Opacity(0.03)
SaturatedBackdrop * NoiseOpacity -> root.Brush
```

`Win32CustomAcrylic.cpp` creates a `WS_EX_LAYERED | WS_POPUPWINDOW` HWND. Painting uses GDI+ into a memory DC and pushes alpha via `UpdateLayeredWindow`. `WM_SIZE` rebuilds the backing DC and repaints; `WM_LBUTTONDOWN` forwards to `WM_NCLBUTTONDOWN/HTCAPTION` to preserve dragging.

### Discussion Claim -> Probe

Claim from the Stack Overflow link: mimicking acrylic in ordinary Win32 is possible through `SetWindowCompositionAttribute`, but it is undocumented and visually fragile. Probe it by testing the SWCA snippet alone with different ABGR alpha values, then compare against Maplespe's composition graph while resizing and dragging. Interpretation: SWCA validates the DWM accent route; the composition graph validates whether blur/noise/tint can be owned and tuned by your app.

Claim from Maplespe's README / dotnet WPF issue link: composition-rendered acrylic can create airspace problems. Probe it by hosting WPF content above a composition-backed acrylic surface, then inspect HWND boundaries and screenshot z-order. Interpretation: if z-order breaks at the HWND/composition boundary, fix architecture; changing blur constants will not solve it.

## References
- https://github.com/Maplespe/Win32CustomAcrylic
- https://github.com/Maplespe/Win32CustomAcrylic/blob/main/Win32CustomAcrylic/Win32CustomAcrylic.cpp
- https://stackoverflow.com/questions/44000217/mimicking-acrylic-in-a-win32-app
- https://github.com/ALTaleX531/Win32Acrylic?tab=readme-ov-file
- https://github.com/ALTaleX531/OpenGlass
