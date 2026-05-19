# Media Foundation Samples (Microsoft)

Microsoft's Media Foundation samples are the official map for Windows audio/video pipelines: capture engine, playback, SourceReader/SinkWriter, transcode API, custom MFTs, and hardware codec paths. They are heavier than focused third-party samples, but they show the supported contracts and edge cases that matter when shipping on varied Windows machines.

For graphics-adjacent work, the key bridge is GPU-backed video: screen capture into H.264/HEVC, DXGI surfaces converted to NV12, hardware encoders, and decode surfaces consumed by D3D/D2D rendering. Use this note with `Screen Capture to H.264.md` and `DXGI Output Duplication Capture.md` rather than treating MF as a separate media silo.

## References
- <https://github.com/microsoft/media-foundation>
