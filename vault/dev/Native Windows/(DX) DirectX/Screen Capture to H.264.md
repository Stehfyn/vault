# Screen Capture to H.264

CaptureToH264 is useful because it joins two normally separate problems: frame acquisition and encode. Its README describes GDI/DXGI screen capture feeding FFmpeg/x264 to produce H.264 video, so the architectural question is where the copies happen: desktop frame to CPU memory, color conversion, encoder input, then bitstream output. A Windows-native variant would often replace the encoder side with Media Foundation Sink Writer or an H.264 MFT to keep more of the path in platform APIs.

Read this beside `DXGI Output Duplication Capture.md` for the capture side and the Media Foundation notes for hardware encode. The hard parts are frame pacing, BGRA/NV12 conversion, and avoiding a readback bottleneck that destroys 60 fps capture.

## Pipeline Shape

The useful code route is a staged ownership handoff. Do not hide the conversion point; it decides whether the pipeline is GPU-bound, CPU-bound, or copy-bound.

```cpp
// 1. Acquire desktop frame.
DXGI_OUTDUPL_FRAME_INFO info = {};
wil::com_ptr<IDXGIResource> frame_resource;
duplication->AcquireNextFrame(timeout_ms, &info, &frame_resource);

// 2. Copy/convert BGRA desktop texture into encoder input format.
// GPU path: shader/video processor -> NV12 texture.
// CPU path: Map staging texture -> swscale/libyuv -> encoder buffer.
ConvertBgraFrameToNv12(frame_resource.get(), nv12_input.get());

// 3. Submit to encoder and release duplication frame promptly.
SubmitH264Frame(nv12_input.get(), info.LastPresentTime);
duplication->ReleaseFrame();
```

Route to `Media Foundation Samples (Microsoft).md` when replacing FFmpeg/x264 with a Windows encoder MFT, and to `../(MMCSS) Multimedia Class Scheduler Services/MMCSS Research.md` when capture/convert/encode threads show scheduler jitter under load.

## Experiment Harness

Goal: locate the capture pipeline bottleneck before choosing GPU conversion, CPU conversion, FFmpeg, or Media Foundation.

Procedure:
1. Instrument four stages separately: acquire, copy/readback, BGRA->NV12 conversion, encode submit.
2. Run three variants: no encode, encode with synthetic frames, and full capture->convert->encode.
3. Add a bounded queue between stages and log queue depth; do not allow unbounded buffering to hide dropped frames.

```cpp
t0 = qpc(); acquire_frame();
t1 = qpc(); convert_bgra_to_nv12();
t2 = qpc(); submit_encoder();
t3 = qpc(); log(t1-t0, t2-t1, t3-t2, queue_depth);
```

Metric: stage milliseconds, dropped/duplicated frames, encoder input latency, output bitrate stability, and audio/video timestamp drift if audio is added.

Failure interpretation: capture-only success with full-pipeline drops means conversion or encode is the bottleneck. Rising queue depth means latency is being accumulated, not solved. Stable encode with synthetic frames but unstable real frames points at DXGI duplication, readback, or color conversion.

## Source Code Reading

`LampsAsarum/CaptureToH264` decomposes the pipeline into source files that map directly to probe stages:

- `CaptureToH264/CaptureToH264/DXGICapture.cpp`: D3D11/DXGI output-duplication capture and GPU-to-CPU readback.
- `CaptureToH264/CaptureToH264/Convert.cpp`: RGB/BGRA to BMP and YUV420 conversion; the 32-bpp path calls `libyuv::ARGBToI420`.
- `CaptureToH264/CaptureToH264/X264Encoder.cpp`: x264 configuration and NAL extraction.
- `CaptureToH264/CaptureToH264/GDICapture.cpp`: alternate GDI capture path for CPU-only comparison.

The code path worth copying into a probe is not "capture then encode"; it is four measured stages:

```cpp
bgra = dxgi.AcquireCopyMap();          // AcquireNextFrame + CopyResource + Map
yuv  = Convert::Rgb32ToYUV420(bgra);  // libyuv ARGBToI420, width/height/stride sensitive
nals = x264.EncodeFrame(yuv);         // ultrafast + zerolatency, I420 input
write_or_stream(nals);                // each x264_nal_t payload appended in order
```

`X264Encoder.cpp` configures the encoder with `x264_param_default_preset(..., "ultrafast", "zerolatency")`, sets `i_csp = X264_CSP_I420`, uses a fixed `25/1` frame rate, disables B-frames with `i_bframe = 0`, and opens with `x264_encoder_open`. `EncodeFrame` assigns the planar pointers as `Y = base`, `U = base + width * height`, `V = base + width * height * 5 / 4`, then calls `x264_encoder_encode` and copies each returned NAL payload into one output buffer.

That gives you the exact experiment checklist:

1. Timestamp `AcquireNextFrame`, `CopyResource`, `Map`, conversion, and `x264_encoder_encode` independently.
2. Validate `MappedSurface.Pitch`; do not assume CPU rows are tightly packed.
3. Force keyframes every N seconds and log NAL sizes so spikes are visible.
4. Compare `DXGICapture.cpp` against `GDICapture.cpp` at the same resolution to isolate capture cost from encode cost.
5. Treat frame pacing as an input: duplication may return no frame on a static desktop while x264 still expects monotonically increasing presentation order.

## References
- <https://github.com/LampsAsarum/CaptureToH264>

## Connections
- `DXGI Output Duplication Capture.md`
- `Media Foundation Samples (Microsoft).md`
- `Media Foundation Focused Samples.md`
- `../(MMCSS) Multimedia Class Scheduler Services/MMCSS Research.md`
