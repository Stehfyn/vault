# UniversalHookX - Universal Graphical Hook

UniversalHookX sits in the graphics-overlay branch of hooking: intercept rendering or presentation paths so an overlay can draw inside another graphical application's frame. These projects are useful because they expose a different hook surface from Win32 message hooks: DirectX/OpenGL/Vulkan swap chains, device contexts, present calls, input forwarding, and resize handling.

The cross-cutting problem is lifecycle. Render devices are lost and recreated, swap chains resize, windows move between monitors/DPI contexts, and hooks must avoid destabilizing the host render loop. Read it alongside DxWnd and MinHook to separate graphics-specific concerns from general inline-patching mechanics.

## Source Shape

Overlay hooks usually reduce to "intercept Present, lazily initialize the overlay for the swap chain, draw, then call the original."

```cpp
HRESULT STDMETHODCALLTYPE HookPresent(IDXGISwapChain *swap_chain,
                                      UINT sync_interval,
                                      UINT flags) {
    if (!overlay.ready) {
        overlay.Attach(swap_chain);
    }

    overlay.DrawFrame();
    return RealPresent(swap_chain, sync_interval, flags);
}
```

Resize and device-loss paths need equivalent hooks or the overlay will hold stale render targets.

## Connections
- `Hook Examples` maps DxWnd and other graphics/window hooks.
- MinHook covers the underlying function-interception primitive many overlay hooks rely on.
- `../DPI Awareness/Per-Monitor V2 DPI Reference.md` matters once an overlay window or swap chain crosses monitors.
- `../Input/libuiohook - Cross-Platform Input Hook.md` is the global-input branch often paired with overlays.

## References
- <https://github.com/bruhmoment21/UniversalHookX>
