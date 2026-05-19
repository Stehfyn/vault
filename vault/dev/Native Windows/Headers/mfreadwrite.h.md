# mfreadwrite.h

The pragmatic Media Foundation header: `IMFSourceReader` and `IMFSinkWriter` collapse the full topology/session model into "read decoded samples from a source" and "write encoded samples to a sink." It is the right layer for file transcode tools, webcam capture prototypes, screen-recording encode paths, and simple audio/video pipelines where you do not need to author a custom MF topology. The main trap is that the simplified API still speaks Media Foundation types: async callbacks, `IMFSample` timestamps in 100 ns units, media-type negotiation, hardware MFT quirks, and D3D manager plumbing for GPU surfaces.

Connections: replaces many DirectShow use cases in `dshow.h`; pairs with `(DX) DirectX/Screen Capture to H.264.md`, `(DX) DirectX/Media Foundation Samples (Microsoft).md`, and DXGI output-duplication notes when turning GPU frames into H.264 without a CPU readback.

## References
- mfreadwrite
