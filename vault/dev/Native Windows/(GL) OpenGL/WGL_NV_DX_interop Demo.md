# WGL_NV_DX_interop Demo

The Halogenica demo is a compact example of sharing DirectX resources with OpenGL through `WGL_NV_DX_interop`: open the D3D device to WGL, register a D3D resource against a GL texture/renderbuffer name, lock it before GL access, unlock it before D3D access. The extension is explicit because both APIs need ownership boundaries.

Use this as the minimal interop shape, then read `OpenGL on DXGI Swapchain.md` for the presentation-level caveats. The hard bugs are usually not the first registration call; they are adapter mismatch, format mismatch, and missing lock/unlock synchronization.

## References
- <https://github.com/halogenica/WGL_NV_DX>

## Connections
- `WGL_NV_DX_interop Register Object Discussion.md`
- `OpenGL on DXGI Swapchain.md`
- `../(DX) DirectX/DX Examples.md`
