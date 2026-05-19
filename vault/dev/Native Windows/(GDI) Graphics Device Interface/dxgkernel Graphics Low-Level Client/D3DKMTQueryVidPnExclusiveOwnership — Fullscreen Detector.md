# D3DKMTQueryVidPnExclusiveOwnership - Fullscreen Detector

`D3DKMTQueryVidPnExclusiveOwnership` asks the graphics kernel which process, if any, owns exclusive VidPN access for a source. That makes it useful for distinguishing normal DWM-composited presentation from true fullscreen-exclusive paths where GDI/DWM capture assumptions may fail. The returned owner process ID is the diagnostic payload.

This sits below normal display management. It is exported through the user-mode graphics stack but reflects dxgkrnl state, so use it for diagnostics and capture/overlay decisions, not for changing topology or modes. Fullscreen Optimizations and modern borderless presentation can blur the user-visible distinction, which is exactly why querying ownership is useful.

## References
- <https://github.com/Aetopia/D3DKMTQueryVidPnExclusiveOwnership> - small detector built around the D3DKMT query.

## Connections
- `../How to Capture the Screen.md` explains why exclusive ownership matters to capture.
- `dxgkernel Overview.md` explains the low-level client API family.
