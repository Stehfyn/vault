# No-Flicker D3D11 Window Resize

This sample addresses a real Win32/D3D11 bug: during resize, USER/GDI can erase the background or Windows can show a stretched stale backbuffer before the swap chain has content at the new size. The fix is two-part: return nonzero from `WM_ERASEBKGND` so GDI does not paint the class brush, and handle `WM_SIZE` by resizing buffers, recreating RTVs, rendering, and presenting before returning.

The nuance is message timing. If you defer all rendering until the next main-loop tick, the user can see an intermediate blank or stretched frame during interactive resize. This belongs beside DXGI notes because `ResizeBuffers`, flip-model behavior, and HWND paint policy meet at this exact seam.

## References
- <https://github.com/bigfatbrowncat/noflicker_directx_window>

## Connections
- `(DXGI) Microsoft DirectX Graphics Infrastructure.md`
- `DirectX VS Project Templates.md`
