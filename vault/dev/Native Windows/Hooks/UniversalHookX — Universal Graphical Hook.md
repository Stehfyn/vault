# UniversalHookX - Universal Graphical Hook

UniversalHookX sits in the graphics-overlay branch of hooking: intercept rendering or presentation paths so an overlay can draw inside another graphical application's frame. These projects are useful because they expose a different hook surface from Win32 message hooks: DirectX/OpenGL/Vulkan swap chains, device contexts, present calls, input forwarding, and resize handling.

The cross-cutting problem is lifecycle. Render devices are lost and recreated, swap chains resize, windows move between monitors/DPI contexts, and hooks must avoid destabilizing the host render loop. Read it alongside DxWnd and MinHook to separate graphics-specific concerns from general inline-patching mechanics.

## Connections
- `Hook Examples` maps DxWnd and other graphics/window hooks.
- MinHook covers the underlying function-interception primitive many overlay hooks rely on.

## References
- <https://github.com/bruhmoment21/UniversalHookX>
