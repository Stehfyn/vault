# OpenGL on DXGI Swapchain

Nicolas Guillemot's sample uses `WGL_NV_DX_interop2` to render with OpenGL while presenting through a DXGI swap chain. The important finding from the README is not just that it can work; it is that Windows 10 flip-model swap chains exposed driver-specific rough edges, especially when registering swap-chain buffers directly as GL objects. Older discard-model swap chains behaved more predictably in the sample.

The practical architecture is often safer if OpenGL renders into a shared D3D texture and D3D/DXGI owns the final present, rather than trying to wrap every swap-chain buffer directly. This note connects the GL interop files to DXGI adapter/presentation rules.

## Interop Skeleton

The WGL/DX bridge has three separate ownership steps: open the D3D device to WGL, register a specific D3D resource against a GL object, then lock/unlock around the API that currently owns access.

```cpp
HANDLE dx_device = wglDXOpenDeviceNV(d3d_device);

GLuint gl_tex = 0;
glGenTextures(1, &gl_tex);
glBindTexture(GL_TEXTURE_2D, gl_tex);

HANDLE dx_object = wglDXRegisterObjectNV(
    dx_device,
    d3d_texture,
    gl_tex,
    GL_TEXTURE_2D,
    WGL_ACCESS_WRITE_DISCARD_NV);

wglDXLockObjectsNV(dx_device, 1, &dx_object);
RenderWithOpenGL(gl_tex);
wglDXUnlockObjectsNV(dx_device, 1, &dx_object);

// D3D/DXGI owns presentation after GL releases the object.
swap_chain->Present(1, 0);
```

If the renderer needs deterministic adapter selection, start with `../(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md` and treat GL as a producer into a D3D/DXGI-owned presentation path. If the issue is frame phase rather than sharing, jump to `VSync (OpenGL).md`.

## Experiment Harness

Goal: verify whether failures come from WGL/DX interop ownership or from DXGI presentation policy.

Procedure:
1. Register one shared D3D texture as a GL texture and render a frame counter into it.
2. Lock, render, unlock, then present through DXGI; log every WGL and DXGI return value.
3. Compare discard-model and flip-model swap-chain variants only as separate runs.

```cpp
wglDXLockObjectsNV(dx_device, 1, &dx_object);
RenderCounterWithGL(gl_tex);
wglDXUnlockObjectsNV(dx_device, 1, &dx_object);
hr = swap_chain->Present(1, 0);
log(hr);
```

Metric: lock/unlock failures, present failures, frame counter monotonicity on screen, GPU adapter LUID, and latency versus a pure GL window.

Failure interpretation: lock/register failure usually means resource flags, format, or driver support. Correct GL render but bad present points at DXGI swap-chain setup. Failures only on flip-model buffers support the note's warning: use a shared texture producer and let DXGI own final presentation.

## Source Code Reading

`nlguillemot/OpenGL-on-DXGI/main.cpp` is the source that makes the ownership rules visible. It creates a normal WGL context first, loads `WGL_NV_DX_interop` entry points with `wglGetProcAddress`, creates a D3D11 device and DXGI swap chain, opens the D3D device to WGL with `wglDXOpenDeviceNV`, and then registers D3D resources as GL textures for the duration that GL needs access.

The render loop registers the current DXGI back buffer as a GL texture, locks both depth/stencil and render-target objects, renders with GL into an FBO, unlocks the objects, then presents with DXGI:

```cpp
dxDeviceHandle = wglDXOpenDeviceNV(d3d_device);
depthHandle = wglDXRegisterObjectNV(dxDeviceHandle, dxDepthBuffer,
                                    dsvNameGL, GL_TEXTURE_2D, READ_WRITE);

// Per back buffer.
rt = swapChain->GetBuffer(frameIndex);
rtHandle = wglDXRegisterObjectNV(dxDeviceHandle, rt, rtvNameGL,
                                 GL_TEXTURE_2D, READ_WRITE);
wglDXLockObjectsNV(dxDeviceHandle, 1, &depthHandle);
wglDXLockObjectsNV(dxDeviceHandle, 1, &rtHandle);
glBindFramebuffer(GL_FRAMEBUFFER, fbo);
DrawOpenGL();
wglDXUnlockObjectsNV(dxDeviceHandle, 1, &rtHandle);
wglDXUnlockObjectsNV(dxDeviceHandle, 1, &depthHandle);
swapChain->Present(0, 0);
```

When `USE_WIN10_SWAPCHAIN` is enabled, the sample also uses `DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT` and waits on `IDXGISwapChain2::GetFrameLatencyWaitableObject` before drawing. That gives a precise timing experiment: compare latency/jitter between waiting for the frame-latency object, blocking in `Present`, and adding DWM timing probes from `VSync (OpenGL).md`.

## References
- <https://github.com/nlguillemot/OpenGL-on-DXGI>

## Connections
- `WGL_NV_DX_interop Demo.md`
- `WGL_NV_DX_interop Register Object Discussion.md`
- `../(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md`
- `VSync (OpenGL).md`
- `GPU Device Selection.md`
