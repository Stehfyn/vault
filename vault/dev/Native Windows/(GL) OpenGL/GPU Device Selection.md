# GPU Device Selection

Classic WGL does not give OpenGL the same clean adapter-selection story as DXGI. The pixel format and ICD are tied to the window/DC path, and on hybrid systems the driver may choose the GPU through vendor policy rather than an app-owned adapter object. Vendor affinity extensions such as `WGL_NV_gpu_affinity` can create an affinity DC for a selected GPU, but they are not a portable cross-vendor solution.

If adapter choice is central, compare this with DXGI's `EnumAdapterByGpuPreference`. For OpenGL-on-Windows projects that need deterministic GPU selection, an interop/presentation architecture using D3D/DXGI may be more controllable than pure WGL.

## References
- <https://community.khronos.org/t/how-to-use-opengl-with-a-device-chosen-by-you/63017/9>

## Connections
- `OpenGL on DXGI Swapchain.md`
- `../(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md`
