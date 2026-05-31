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

## Source Code Reading

Read these files first in `Maplespe/DWMBlurGlass`: `DWMBlurGlassExt/Backdrops/BackdropFactory.cpp`, `DWMBlurGlassExt/Backdrops/AeroBackdrop.hpp`, and then the specific backdrop headers (`BlurBackdrop.hpp`, `AcrylicBackdrop.hpp`, `MicaBackdrop.hpp`). The project is not just "apply a backdrop"; the useful code contribution is the material factory and the composition-effect graph it builds.

`BackdropFactory::GetOrCreateBackdropBrush` is the missing shape behind a fake helper like `ApplyBackdrop(hwnd)`. It keys brushes by active/inactive state, reads the current policy/configuration, and then dispatches by `effectType`: plain color, `BlurBackdrop::CreateBrush`, `AeroBackdrop::CreateBrush`, `AcrylicBackdrop::CreateBrush`, or `MicaBackdrop::CreateBrush`. That means an experiment should log three independent values: selected material type, effective tint/opacity, and whether the returned brush came from the active or inactive cache.

The `AeroBackdrop::CreateBrush` path is the most educational one because it decomposes "glass" into small DirectComposition/WinRT effect inputs:

```cpp
// Source-shaped pseudocode from AeroBackdrop.hpp.
backdrop = compositor.CreateBackdropBrush();
if (blurAmount > 0) {
    blur = GaussianBlurEffect("Backdrop", blurAmount, HARD_BORDER, SPEED);
    blurred = compositor.CreateEffectFactory(blur).CreateBrush();
    blurred.SetSourceParameter(L"Backdrop", backdrop);
} else {
    blurred = backdrop;
}

mainColor = ColorSourceEffect(color);
mainOpacity = OpacityEffect(mainColor, colorBalance);
blurOpacity = OpacityEffect(Source("BlurredBackdrop"), blurBalance);
fallbackOrBlack = TintEffect(Source("BlurredBackdrop"), fallbackTint);
composite = CompositeStepEffect(PLUS, fallbackOrBlack, mainOpacity, blurOpacity);
return compositor.CreateEffectFactory(composite).CreateBrush();
```

That code tells you what to probe. Vary blur amount, color balance, blur balance, and active/inactive state separately; capture before/after pixels over a checkerboard; then compare whether a failure is a source-parameter failure, an effect-factory failure, or simply a tint/opacity policy producing an apparently solid result. The cache also matters: if changing policy does not visually update, the first suspect is stale cached `CompositionBrush` state, not the blur shader.

The texture/noise path in `BackdropFactory.cpp` is another buried detail. `CreateMaterialTextureBrush` creates a WinRT composition drawing surface through `ICompositorInterop::CreateGraphicsDevice`, decodes a packaged resource with WIC, creates a D2D bitmap from the WIC bitmap, draws it into the composition surface, then wraps it in a `CompositionSurfaceBrush`. That is the decomposed form of "add noise":

```cpp
stream = SHCreateMemStream(resourceBytes);
decoder = wic.CreateDecoderFromStream(stream);
converter.Initialize(frame, GUID_WICPixelFormat32bppPBGRA);
surface = compositionGraphics.CreateDrawingSurface(size, B8G8R8A8, PREMULTIPLIED);
d2dContext->CreateBitmapFromWicBitmap(converter, &bitmap);
draw bitmap into composition surface;
noiseBrush = compositor.CreateSurfaceBrush(surface);
```

Safe probe: reproduce only the public WinRT/DComp effect-graph part in a normal process. Do not test the DWM detour mechanism when the question is "what does the material consist of?" Build a tiny HWND with a composition target, create the same `GaussianBlurEffect -> opacity/color/composite -> noise surface` graph, and verify alpha/tint/blur with controlled background pixels.

## References
- <https://github.com/Maplespe/DWMBlurGlass>
- Related: `OpenGlass (Aero Blur Restoration).md`, `DWM Internals Documentation.md`, `Title Bar Customization.md`
