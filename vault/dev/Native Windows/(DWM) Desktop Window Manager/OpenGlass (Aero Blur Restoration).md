# OpenGlass (Aero Blur Restoration)

Resurrects Aero Glass blur-behind on Windows 10/11 by injecting into `dwm.exe` and intercepting the post-Win8 compositor's effect pipeline (uDWM.dll / dwmcore.dll), replacing the flat Mica/Acrylic backdrops with a real Gaussian blur + tint pass. Notable because it does not rely on the old `DwmEnableBlurBehindWindow` path (which Microsoft gutted after 8.1) — it patches the compositor itself, so it works on UWP, WPF, and legacy Win32 windows uniformly (cf. Maplespe/DWMBlurGlass for a sibling project, ALTaleX531/Win32Acrylic for the in-process WinRT route that doesn't need injection).

```cpp
// Conceptual: hook the symbol that builds the per-window effect graph in dwmcore.dll
// Real project resolves the function via PDB symbol lookup against the MS symbol server.
using CRenderingComposition_Build_t = HRESULT(__fastcall*)(void* self, void* visual);
CRenderingComposition_Build_t orig = nullptr;

HRESULT __fastcall HookedBuild(void* self, void* visual) {
    HRESULT hr = orig(self, visual);
    // Walk the visual tree, find the backdrop brush node, swap its
    // CBackdropEffectGroup for a Gaussian-blur + tint chain.
    InjectBlurEffect(visual, /*radius*/ 30.0f, /*tint*/ 0x80FFFFFF);
    return hr;
}

// MinHook-style detour installed from a DLL loaded into dwm.exe via
// SetWindowsHookEx(WH_GETMESSAGE, ...) or a debug-privilege CreateRemoteThread.
```

## Source Code Reading

Read `ALTaleX531/OpenGlass` as an engine split, not as a single hook. The useful files are `OpenGlass/GlassEngine.cpp`, `OpenGlass/GlassFrameHandler.cpp`, `OpenGlass/GlassFrameEnhancer.cpp`, `OpenGlass/GlassRealizer.cpp`, `OpenGlass/D3DGlassRealizer.cpp`, `OpenGlass/AeroEffect.cpp`, `OpenGlass/BlurEffect.cpp`, and `OpenGlass/AeroColorizationEffect.cpp`.

The conceptual chain is:

```cpp
// Source-shaped architecture, not a paste of project internals.
GlassEngine starts service/process integration.
GlassFrameHandler observes a target frame/window.
GlassFrameEnhancer decides which frame regions are glass-covered.
GlassRealizer / D3DGlassRealizer materializes those regions.
AeroEffect / BlurEffect / AeroColorizationEffect build the effect math.
GlassRenderer submits the realized material to the compositor-facing path.
```

This is the detail a reader needs: the "Aero" effect is not a single blur call. It is a region problem plus a material problem. `GlassCoverageSet` models where glass should exist; `GlassFrameDemodernizer` and `CaptionMetricsTweaker` are frame-geometry/policy code; `AeroColorizationEffect` handles the Windows colorization/tint side; `BlurEffect` is the blur operator; `GlassReflectionBrush`/`GlassReflectionHandler` add the old Aero reflection layer; and `MaterialRealizer`/`D3DGlassRealizer` turn that policy into actual GPU resources.

The probe shape should therefore be non-invasive and region-first:

```cpp
struct GlassProbe {
    RECT frame_bounds;
    RECT client_bounds;
    RECT caption_bounds;
    COLORREF colorization;
    float blur_radius;
    bool active;
};

// Verify the material independently:
// 1. Render a checkerboard into a D3D/D2D target.
// 2. Apply blur + tint + optional reflection to only caption_bounds.
// 3. Compare sampled pixels inside/outside GlassCoverageSet-style regions.
```

For code that will drive new work, copy the separation, not the detour. First implement a public-process `GlassMaterialProbe` that takes `GlassProbe`, renders a fixed backdrop through D2D/DirectComposition, and logs blur radius, tint matrix, region bounds, and output pixel hashes. Only after that is stable does it make sense to compare observable DWM behavior such as active/inactive frame color changes.

## References
- <https://github.com/ALTaleX531/OpenGlass>
- Related: `DWM Blur Glass (Aero Restoration).md`, `DWM Internals Documentation.md`, `DWM Colorization.md`

## Connections
- `DWM Internals Documentation.md` is the prerequisite before reading this as anything more than a patching project.
- `../Custom Frame/Acrylic Three Ways Comparison.md` and `../Custom Frame/Acrylic via WinRT Composition Interop.md` are the non-DWM-injection alternatives for backdrop effects.
- `../Hooks/MinHook - Minimal Hooking Library.md` and `../Shell/Explorer Patcher (Win11 Shell Restore).md` are adjacent examples of runtime detouring and version-keyed shell/DWM patching.
