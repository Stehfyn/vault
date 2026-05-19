<!-- generated-from-dump2 -->
# wcap — Minimal WGC + Media Foundation Recorder

Tiny (~3 KLOC) C screen recorder for Windows 10/11 that's a clean reference for the *modern* capture stack: **Windows.Graphics.Capture** (WGC, the WinRT API behind Win+G/Game Bar that lets you capture a single window without OBS's hooks) plus **Media Foundation** hardware-encoded H.264/H.265 output via **Sink Writer**. Same author as the build-angle / w32 recipes; the code is the minimum to demonstrate the pipeline end-to-end with no UI framework — a tray icon, a hotkey to start/stop, a configuration file. Read for an unusually clean WGC-to-MF integration: shared D3D11 texture as the GraphicsCaptureItem's destination, then handed straight to MF as an `IMFSample` without a CPU roundtrip.

```cpp
// Pipeline shape (real code: capture.c + encoder.c):
// 1. Pick what to capture: monitor or HWND via Graphics Capture Picker.
//    (Or programmatically: IGraphicsCaptureItemInterop::CreateForMonitor)
// 2. Create a frame pool with shared D3D11 device.
// 3. Per frame: Direct3D11CaptureFramePool::TryGetNextFrame()
//      - frame.Surface is an IDirect3DSurface (interop to ID3D11Texture2D).
// 4. Wrap that texture in an IMFSample (no copy) and SinkWriter::WriteSample.
// 5. SinkWriter is configured with MFT_FRIENDLY_NAME h264/hevc hardware
//    encoder; output goes to an MP4 sink.
```

## References
- <https://github.com/mmozeiko/wcap>
