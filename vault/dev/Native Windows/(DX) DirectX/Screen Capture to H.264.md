# Screen Capture to H.264

CaptureToH264 is useful because it joins two normally separate problems: frame acquisition and encode. Its README describes GDI/DXGI screen capture feeding FFmpeg/x264 to produce H.264 video, so the architectural question is where the copies happen: desktop frame to CPU memory, color conversion, encoder input, then bitstream output. A Windows-native variant would often replace the encoder side with Media Foundation Sink Writer or an H.264 MFT to keep more of the path in platform APIs.

Read this beside `DXGI Output Duplication Capture.md` for the capture side and the Media Foundation notes for hardware encode. The hard parts are frame pacing, BGRA/NV12 conversion, and avoiding a readback bottleneck that destroys 60 fps capture.

## References
- <https://github.com/LampsAsarum/CaptureToH264>
