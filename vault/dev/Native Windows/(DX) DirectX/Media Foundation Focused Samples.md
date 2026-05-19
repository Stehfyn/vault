# Media Foundation Focused Samples

Aaron Clauson's samples are useful because they isolate one Media Foundation scenario per small program: capture, encode, decode, network streaming, transcode, or SourceReader/SinkWriter plumbing. That makes them faster to read than Microsoft's broad sample tree when the question is "how do I wire exactly this MF pipeline?"

The recurring pattern is SourceReader to get decoded/captured samples, optional transforms for conversion/encode, then SinkWriter for file/container output. Pair this with `Screen Capture to H.264.md` when the source frames come from GDI/DXGI capture and with Microsoft's samples when you need official coverage of capture engines or custom MFTs.

## References
- <https://github.com/sipsorcery/mediafoundationsamples>

## Connections
- `Media Foundation Samples (Microsoft).md`
- `Screen Capture to H.264.md`
