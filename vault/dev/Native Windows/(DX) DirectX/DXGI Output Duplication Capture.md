# DXGI Output Duplication Capture

ScreenEx is a concrete use of DXGI Output Duplication: acquire frames from an `IDXGIOutputDuplication`, inspect dirty/move rects, and copy the desktop image out of the GPU path. This is monitor capture, not HWND capture. It sees the post-composition output for an output, so it is the right primitive for screenshot/recording tools and the wrong primitive when you need a hidden or occluded window's independent surface.

That distinction connects it directly to DWM capture notes. `DwmGetDxSharedSurface Window Capture.md` targets per-window DWM redirection surfaces; Output Duplication targets the final output image. Capture-protected windows can also affect what duplication returns.

## API Skeleton

The source-shaped pattern is: choose the output on the same adapter as the D3D device, duplicate that output, acquire one desktop frame, read move/dirty metadata, copy the GPU texture, then release the frame before acquiring again.

```cpp
wil::com_ptr<IDXGIOutput1> output1;
output->QueryInterface(IID_PPV_ARGS(&output1));

wil::com_ptr<IDXGIOutputDuplication> duplication;
output1->DuplicateOutput(d3d_device.get(), &duplication);

DXGI_OUTDUPL_FRAME_INFO frame = {};
wil::com_ptr<IDXGIResource> desktop_resource;
HRESULT hr = duplication->AcquireNextFrame(16, &frame, &desktop_resource);
if (hr == DXGI_ERROR_WAIT_TIMEOUT) {
    return; // no new desktop image yet
}

wil::com_ptr<ID3D11Texture2D> desktop_tex;
desktop_resource->QueryInterface(IID_PPV_ARGS(&desktop_tex));

UINT bytes_required = 0;
duplication->GetFrameMoveRects(0, nullptr, &bytes_required);
std::vector<DXGI_OUTDUPL_MOVE_RECT> moves(bytes_required / sizeof(DXGI_OUTDUPL_MOVE_RECT));
if (!moves.empty()) {
    duplication->GetFrameMoveRects(bytes_required, moves.data(), &bytes_required);
}

bytes_required = 0;
duplication->GetFrameDirtyRects(0, nullptr, &bytes_required);
std::vector<RECT> dirty(bytes_required / sizeof(RECT));
if (!dirty.empty()) {
    duplication->GetFrameDirtyRects(bytes_required, dirty.data(), &bytes_required);
}

context->CopyResource(staging_or_encode_input.get(), desktop_tex.get());
duplication->ReleaseFrame();
```

## Decision Points

- Use this for **monitor capture** and recording: the frame is already the post-DWM desktop image for one output.
- Use `../(DWM) Desktop Window Manager/DwmGetDxSharedSurface Window Capture.md` for **HWND capture** when occlusion/visibility independence matters more than staying documented.
- Use `../(GDI) Graphics Device Interface/How to Capture the Screen.md` only when simple CPU capture is enough; it is easier to wire but worse for high-rate video.
- Feed `Screen Capture to H.264.md` after the copy/convert step; the hard boundary is usually BGRA-to-NV12 plus pacing, not `AcquireNextFrame` itself.

## Experiment Harness

Goal: measure monitor-frame capture behavior: cadence, dirty-rect usefulness, access-loss recovery, and copy cost.

Procedure:
1. Enumerate adapter/output pairs and create the D3D device on the same adapter as the chosen `IDXGIOutput1`.
2. Run a 10-second loop: `AcquireNextFrame(16)`, count move/dirty bytes, copy to either a staging texture or encoder input, then `ReleaseFrame`.
3. During the run, move a window, play video, change display mode, lock/unlock, and trigger Win+P topology changes.

```cpp
hr = duplication->AcquireNextFrame(16, &info, &resource);
log(hr, info.LastPresentTime, info.AccumulatedFrames,
    move_bytes, dirty_bytes, qpc_copy_cost);
if (hr == DXGI_ERROR_ACCESS_LOST) recreate_duplication();
```

Metric: acquired frames/sec, `DXGI_ERROR_WAIT_TIMEOUT` rate, `DXGI_ERROR_ACCESS_LOST` count, dirty/move rect bytes per frame, GPU-copy or readback milliseconds, and end-to-end encode queue depth.

Failure interpretation: `E_INVALIDARG` from `DuplicateOutput` often means the D3D device was created on the wrong adapter. Repeated `WAIT_TIMEOUT` can be normal on a static desktop. `ACCESS_LOST` means recreate after desktop switch, mode change, DWM transition, or fullscreen scenario. High copy cost means the experiment is testing readback/conversion more than duplication.

References: Desktop Duplication guide below; add `IDXGIOutput1::DuplicateOutput` and `IDXGIOutputDuplication::AcquireNextFrame` when implementing the harness.

## Source Code Reading

Read `LampsAsarum/CaptureToH264/CaptureToH264/CaptureToH264/DXGICapture.cpp` as the compact version of the documented Desktop Duplication loop. The source creates a D3D11 device, queries it to `IDXGIDevice`, walks back to `IDXGIAdapter`, enumerates output zero with `EnumOutputs`, queries `IDXGIOutput1`, calls `DuplicateOutput`, and then loops `AcquireNextFrame -> QueryInterface(ID3D11Texture2D) -> CopyResource -> Map -> memcpy -> Unmap -> ReleaseFrame`.

The important detail is that the sample maps through an intermediate copy buffer:

```cpp
// Source-shaped from DXGICapture.cpp.
D3D11CreateDevice(..., &device, ..., &context);
device->QueryInterface(IDXGIDevice, &dxgi_device);
dxgi_device->GetParent(IDXGIAdapter, &adapter);
adapter->EnumOutputs(0, &output);
output->QueryInterface(IDXGIOutput1, &output1);
output1->DuplicateOutput(device, &dupl);

hr = dupl->AcquireNextFrame(20, &info, &desktop_resource);
if (hr == DXGI_ERROR_WAIT_TIMEOUT) { dupl->ReleaseFrame(); return false; }
desktop_resource->QueryInterface(ID3D11Texture2D, &desktop_tex);
device->CreateTexture2D(staging_readback_desc, nullptr, &copy_buffer);
context->CopyResource(copy_buffer, desktop_tex);
copy_buffer->QueryInterface(IDXGISurface, &surface);
surface->Map(&mapped, DXGI_MAP_READ);
memcpy(rgbBuffer, mapped.pBits, rgbBufferSize);
surface->Unmap();
dupl->ReleaseFrame();
```

That sample is intentionally simple but exposes the bottleneck: once you call `Map`, the probe is no longer only measuring duplication. It is measuring GPU-to-CPU readback, row pitch handling, and CPU copy. A better probe logs `MappedSurface.Pitch` and copies row-by-row instead of assuming `width * height * bytes_per_pixel` is contiguous with the desired stride.

`MurkyYT/ScreenEx` is a useful contrast, not a DXGI duplication implementation. Its `CaptureWindow.cpp` and `Bitmap.cpp` are a snipping-overlay/GDI path: it creates a fullscreen overlay, filters real windows with `DwmGetWindowAttribute(DWMWA_CLOAKED)` and `DWMWA_EXTENDED_FRAME_BOUNDS`, captures monitors with `CreateCompatibleDC`, `CreateCompatibleBitmap`, and `BitBlt`, then wraps the `HBITMAP` with `Gdiplus::Bitmap::FromHBITMAP`. Use it to compare UX/window-bound calculations against DXGI output identity, not as the duplication loop.

## References
- <https://github.com/MurkyYT/ScreenEx>
- <https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/desktop-dup-api> - Microsoft Desktop Duplication API guide.
- <https://learn.microsoft.com/en-us/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-duplicateoutput> - output/device adapter contract.
- <https://learn.microsoft.com/en-us/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-acquirenextframe> - frame acquisition results and recovery cases.

## Connections
- `../(DWM) Desktop Window Manager/DwmGetDxSharedSurface Window Capture.md`
- `Screen Capture to H.264.md`
- `../(DWM) Desktop Window Manager/Capture-Protected Window (Sprite Hack).md`
