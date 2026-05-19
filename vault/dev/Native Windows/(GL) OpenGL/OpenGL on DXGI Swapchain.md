# OpenGL on DXGI Swapchain

Nicolas Guillemot's sample uses `WGL_NV_DX_interop2` to render with OpenGL while presenting through a DXGI swap chain. The important finding from the README is not just that it can work; it is that Windows 10 flip-model swap chains exposed driver-specific rough edges, especially when registering swap-chain buffers directly as GL objects. Older discard-model swap chains behaved more predictably in the sample.

The practical architecture is often safer if OpenGL renders into a shared D3D texture and D3D/DXGI owns the final present, rather than trying to wrap every swap-chain buffer directly. This note connects the GL interop files to DXGI adapter/presentation rules.

## References
- <https://github.com/nlguillemot/OpenGL-on-DXGI>

## Connections
- `WGL_NV_DX_interop Demo.md`
- `WGL_NV_DX_interop Register Object Discussion.md`
- `../(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md`
