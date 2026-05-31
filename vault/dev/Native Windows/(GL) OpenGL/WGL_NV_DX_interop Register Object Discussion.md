# WGL_NV_DX_interop Register Object Discussion

The Reddit thread addresses a common misunderstanding: `wglDXRegisterObjectNV` is not optional ceremony. It binds a specific D3D resource to a specific GL object name with an access mode, creating the object-level relationship that later lock/unlock calls operate on. Opening the D3D device with `wglDXOpenDeviceNV` only establishes the device bridge.

Registration is also where many failures surface: unsupported resource type/format, wrong adapter, wrong target, or a driver that does not support the extension path you expected. For dynamic swap-chain buffers, repeated registration can become both fragile and expensive; shared intermediate textures are often easier to reason about.

## Discussion Claim To Verify

The discussion's implicit performance claim is that repeated `wglDXRegisterObjectNV` for dynamic resources is not free and may be avoidable. The source-backed demo in `OpenGL on DXGI Swapchain.md` registers the current back buffer and locks/unlocks it for GL access, which is a direct test case.

Probe matrix:

```cpp
// A: register/unregister current back buffer each frame.
rt = swapchain.GetBuffer(frameIndex);
h = wglDXRegisterObjectNV(dxDevice, rt, glName, GL_TEXTURE_2D, WGL_ACCESS_READ_WRITE_NV);
wglDXLockObjectsNV(dxDevice, 1, &h);
DrawGL();
wglDXUnlockObjectsNV(dxDevice, 1, &h);
wglDXUnregisterObjectNV(dxDevice, h);

// B: keep a shared intermediate texture registered, copy to swap-chain buffer in D3D.
```

Measurement that matters: registration/unregistration microseconds, lock wait time, present interval variance, GPU copy cost in variant B, and failure rate by texture format/sample count/adapter. If A and B have the same timing and failure behavior, the repeated-registration warning is overstated for that driver. If A spikes or fails on resize/back-buffer rotation while B stays stable, the discussion's guidance is actionable.

Verification route: do not time only CPU calls. Add GPU timestamp queries around the D3D copy path and GL timer queries around the draw path, then correlate them with CPU QPC spans for `wglDXLockObjectsNV` and `wglDXUnlockObjectsNV`. A slow register call can be a real driver allocation, but a slow lock often means the GPU is waiting on ownership transition or previous use.

```cpp
CpuSpan register_span("wglDXRegisterObjectNV");
HANDLE interop = wglDXRegisterObjectNV(dx_device, resource, gl_name,
                                       GL_TEXTURE_2D, WGL_ACCESS_READ_WRITE_NV);

CpuSpan lock_span("wglDXLockObjectsNV");
wglDXLockObjectsNV(dx_device, 1, &interop);
glBeginQuery(GL_TIME_ELAPSED, gl_timer);
DrawGLUsingRegisteredTexture();
glEndQuery(GL_TIME_ELAPSED);
wglDXUnlockObjectsNV(dx_device, 1, &interop);
```

Failure cases to preserve in the log: wrong adapter, multisampled resource, format not accepted by the extension, resize/back-buffer rotation invalidating the registered object, and driver-specific behavior. If the shared-intermediate variant adds a predictable GPU copy but removes long-tail lock/register spikes, the discussion claim becomes a design rule for UI/video pipelines rather than a micro-optimization.

## References
- <https://www.reddit.com/r/opengl/comments/uiu87k/wgl_nv_dx_interop_do_i_really_have_to_register/>

## Connections
- `WGL_NV_DX_interop Demo.md`
- `OpenGL on DXGI Swapchain.md`
