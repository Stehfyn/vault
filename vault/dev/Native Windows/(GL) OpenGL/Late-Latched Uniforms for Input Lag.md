# Late-Latched Uniforms for Input Lag

The LateLatching demo compares ordinary per-frame uniform updates with a late-latched path where the latest mouse state is written into a persistently mapped buffer as late as possible before the draw that consumes it. The payoff is latency, not throughput: when the frame is already queued or GPU-bound, sampling the input later can remove roughly a frame of perceived lag for cursor/flash-style feedback.

This belongs with the DWM/vblank notes because late latching only helps if you understand the queue between input, command submission, present, compositor, and scanout. It is not a replacement for frame pacing; it is a targeted technique for data that can be safely updated after most of the frame has been built.

## References
- <https://github.com/nlguillemot/LateLatching>

## Connections
- `../(DWM) Desktop Window Manager/Lagless VSYNC ON via Beam Racing.md`
- `VSync (OpenGL).md`
