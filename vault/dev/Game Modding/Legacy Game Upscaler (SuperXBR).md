<!-- generated-from-dump2 -->
# Legacy Game Upscaler (SuperXBR)

Hooks GDI/DirectDraw/D3D9 inside legacy 2D games, redirects their back-buffer to an offscreen surface, then composites onto a resizable host window with a SuperXBR upscaler running on the GPU. Solves the "this 1998 game only opens a 640x480 borderless window" problem without DirectDraw wrapper hassles. Read for the hooking surface — `DirectDrawCreate`, `IDirectDraw7::CreateSurface`, `IDirect3DDevice9::Present` — and how each is redirected to a shared texture.

```cpp
// IDirect3DDevice9::Present hook redirects the swap-chain to an FBO,
// then SuperXBR upscales to the visible HWND.
HRESULT __stdcall HookPresent(IDirect3DDevice9* dev, const RECT* src, const RECT* dst,
                              HWND hwnd, const RGNDATA* rgn) {
    dev->StretchRect(gameBackBuffer, nullptr, offscreenRT, nullptr, D3DTEXF_POINT);
    UpscaleSuperXBR(offscreenRT, hostBackBuffer, gameW, gameH, hostW, hostH);
    return orig_Present(dev, src, dst, hwnd, rgn);
}
```

## References
- <https://github.com/Dwedit/GameStretcher>
