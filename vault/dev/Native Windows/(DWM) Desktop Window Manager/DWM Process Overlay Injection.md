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
