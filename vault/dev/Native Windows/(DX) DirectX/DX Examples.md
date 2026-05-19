# DX Examples

This note is a triage list for small DirectX examples, not a tutorial index. `Hello-Cube-Windows` is useful for the bare Win32 + D3D11 path: create device/swap chain, allocate a render target view, bind pipeline state, and present. `RenderHost.cpp` is more valuable for UI integration because it treats a renderer as a child/control surface and handles `WM_PAINT`/`WM_SIZE` without letting GDI erase the backbuffer. The mmozeiko interop gist is the bridge into the OpenGL folder: `WGL_NV_DX_interop` lets a D3D texture and an OpenGL texture name refer to the same resource after explicit register/lock/unlock steps.

## D3D11 Window Loop

The cube and tutorial links contribute the minimal D3D11 frame shape. The important boundary is that resize invalidates render-target views backed by the swap chain.

```cpp
DXGI_SWAP_CHAIN_DESC sd = {};
sd.BufferCount = 2;
sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
sd.OutputWindow = hwnd;
sd.SampleDesc.Count = 1;
sd.Windowed = TRUE;

D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
                              nullptr, 0, D3D11_SDK_VERSION,
                              &sd, &swap_chain, &device, nullptr, &context);
```

## Hosted Renderer and GL Interop

`RenderHost.cpp` contributes the child-window hosting problem: suppress background erase and resize the graphics target deliberately. The WGL interop gist contributes the explicit register/lock/unlock boundary between D3D and OpenGL.

```cpp
case WM_ERASEBKGND:
    return 1;
case WM_SIZE:
    context->OMSetRenderTargets(0, nullptr, nullptr);
    render_target_view.Reset();
    swap_chain->ResizeBuffers(0, LOWORD(lParam), HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
    return 0;
```

```cpp
HANDLE shared = wglDXRegisterObjectNV(dx_device, d3d_texture,
                                      gl_texture, GL_TEXTURE_2D,
                                      WGL_ACCESS_READ_WRITE_NV);
wglDXLockObjectsNV(dx_device, 1, &shared);
// GL sees the D3D-backed texture while locked.
wglDXUnlockObjectsNV(dx_device, 1, &shared);
```

## References

- <https://github.com/mindaptiv/Hello-Cube-Windows> - minimal D3D11 cube with Win32 swap-chain setup.
- <https://gist.github.com/mmozeiko/c99f9891ce723234854f0919bfd88eae> - D3D11/OpenGL texture sharing via `WGL_NV_DX_interop`.
- <https://github.com/Jaykul/Windows7APICodePack/blob/master/Samples/DirectX/UtilitiesLibrary/Controls/RenderHost.cpp#L41> - DirectX renderer hosted as a Win32 control.
- <http://www.directxtutorial.com/lesson.aspx?lessonid=111-4-3> - classic D3D11 device/swap-chain setup reference.

## Connections

- `WGL_NV_DX_interop Demo.md`
- `No-Flicker D3D11 Window Resize.md`
- `DirectX VS Project Templates.md`
