# DWM Blur Glass (Aero Restoration)

The interesting one in the blur-restoration cluster (cf. ALTaleX531/OpenGlass #13, seiftnesse/DWM_Hook #58, Maplespe/ExplorerBlurMica #66, ahmed605/10Mica #61). Two modes: a "SystemBackdrop" path that uses documented Mica/Acrylic and a "CustomBlur" path that reverse-engineers `dwmcore.dll` and hooks the DWM render pipeline via minhook to inject Aero-style blur on Win10/11 system title bars. Unlike MicaForEveryone, it does *not* modify the target application's rendering — the hook lives inside `dwm.exe`, so any window with a standard non-client area inherits the effect, which is why it's compatible with apps that would otherwise reject `DwmEnableBlurBehindWindow`/`SetWindowCompositionAttribute`. Depends on `AcrylicEverywhere` (the upstream of the CustomBlur method) and WIL. Brittle by construction — any DWM update can break the offsets — which is exactly why it's worth reading.

```cpp
// Conceptual: minhook into a dwmcore.dll routine that builds the visual tree
// for non-client area, then graft in a blur effect node before commit.
#include <MinHook.h>
using PFN_BuildNcVisuals = HRESULT (WINAPI*)(void* /*pWindowData*/, void* /*pBuilder*/);
PFN_BuildNcVisuals g_orig = nullptr;
HRESULT WINAPI Hook_BuildNcVisuals(void* w, void* b) {
    HRESULT hr = g_orig(w, b);
    if (SUCCEEDED(hr)) InjectBlurNode(w, b);   // attach IDCompositionGaussianBlurEffect
    return hr;
}
// Offsets/symbol names vary per dwmcore.dll build — see DWMBlurGlass's symbol DB.
MH_Initialize();
MH_CreateHook(/*resolved fn*/ nullptr, &Hook_BuildNcVisuals,
              reinterpret_cast<LPVOID*>(&g_orig));
MH_EnableHook(MH_ALL_HOOKS);
```

## References
- <https://github.com/Maplespe/DWMBlurGlass>
- Related: `OpenGlass (Aero Blur Restoration).md`, `DWM Internals Documentation.md`, `Title Bar Customization.md`
