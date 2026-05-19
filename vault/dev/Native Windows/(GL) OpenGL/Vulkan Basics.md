# Vulkan Basics

Vulkan is included here as the explicit-API contrast to OpenGL: instance, physical device, logical device, queues, swap chain, command buffers, synchronization, and resource lifetime are all application-owned. There is no implicit context and no hidden global state machine comparable to classic GL.

For Native Windows work, the useful comparison is with D3D12 and DXGI. Vulkan owns rendering explicitly, but presentation still goes through a window-system integration layer (`VK_KHR_win32_surface` on Windows), so swap-chain and display behavior remain platform concerns.

## References
- <https://www.howtovulkan.com/>

## Connections
- `../(DX) DirectX/(DX12) DirectX12.md`
- `../(DX) DirectX/Cauldron — D3D12 and Vulkan Prototyping.md`
