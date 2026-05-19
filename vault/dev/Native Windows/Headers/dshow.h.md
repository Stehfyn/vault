# dshow.h

DirectShow's central COM header: filter graphs, pins, media types, capture graphs, sample grabbers, renderers, and control interfaces such as `IGraphBuilder`, `IMediaControl`, `IBaseFilter`, `IPin`, and `ICaptureGraphBuilder2`. It is legacy, but not dead: capture devices, old TV/DVR filters, webcam drivers, and codec packs still expose DirectShow filters even when Media Foundation is the preferred API. The conceptual trap is that DirectShow is a pull/push graph of COM objects with negotiated media types, not a simple "open file, decode frames" library; failures usually come from pin connection and allocator negotiation, not from the top-level graph call.

Connections: `mfreadwrite.h` is the replacement for ordinary decode/encode pipelines; `(DX) DirectX/Media Foundation Focused Samples.md` and `(DX) DirectX/Screen Capture to H.264.md` cover the modern route. Keep DirectShow for old hardware and filter-graph archaeology.

## References
- dshow.h
