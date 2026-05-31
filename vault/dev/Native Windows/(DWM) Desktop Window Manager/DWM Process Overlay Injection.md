# DWM Process Overlay Injection

Injects into `dwm.exe` to draw a custom overlay on top of the composited desktop, riding the same hook surface as the Maplespe cluster (cf. Maplespe/DWMBlurGlass, Maplespe/ExplorerBlurMica). The trick is that DWM owns the final framebuffer, so anything you render from inside its process sits above every window without needing a topmost click-through HWND and without the tearing you get from layered-window overlays. The cost is fragility: every Windows feature update reshuffles DWM's internals, the loader has to bypass PPL/anti-tamper on `dwm.exe`, and a crash takes the desktop with it.

```cpp
// Conceptual: hook a DWM render entrypoint after DLL injection.
// Real offsets/vtable indices vary per Windows build — resolve at runtime.
using PresentFn = HRESULT(__stdcall*)(IDXGISwapChain*, UINT, UINT);
PresentFn g_origPresent = nullptr;

HRESULT __stdcall HookedPresent(IDXGISwapChain* sc, UINT sync, UINT flags) {
    ID3D11Texture2D* back = nullptr;
    sc->GetBuffer(0, IID_PPV_ARGS(&back));
    DrawOverlay(back); // user D2D/D3D draw onto DWM's backbuffer
    back->Release();
    return g_origPresent(sc, sync, flags);
}
```

## References
- <https://github.com/MapleSwan/dwm-overlay>
- Related: `DWM Overlay WndProc Hook.md`, `DWM Blur Glass (Aero Restoration).md`, `OpenGlass (Aero Blur Restoration).md`

## Discussion Claim To Verify

The only safe claim to carry forward from DWM overlay discussions is observational: drawing inside the compositor process can appear above ordinary HWND overlays because the compositor owns the final composed surface. Verify that boundary without documenting loader bypasses or offsets.

```cpp
// Observation-only probe shape.
record_screen_with_known_routes();
log_window_stack(GetWindow(GW_HWNDPREV), topmost_hwnds);
log_dwm_state(DwmIsCompositionEnabled, DwmGetCompositionTimingInfo);
compare_pixels("topmost layered HWND", "DWM-internal overlay source");
```

Interpretation: if a normal topmost layered window tears or falls below exclusive/compositor content while a DWM-internal overlay does not, the layering claim is plausible. If both paths show the same capture/latency/flicker behavior, the DWM-internal route is not buying anything except fragility. Treat crashes, black frames, or build-specific breakage as evidence that this belongs in reverse-engineering notes, not production UI architecture.
