# libcamcapture - GDI Screen Capture

`libcamcapture` includes a GDI capture source that repeatedly blits from a screen/window DC into a memory surface. It is useful as a small, readable implementation of the old capture model: acquire DC, select bitmap into compatible DC, `BitBlt`, then hand the pixels to the rest of the pipeline.

The limits are the standard GDI limits. It sees the composited desktop as GDI exposes it, not protected content or every GPU overlay, and capture rate is bounded by CPU copies and format conversion. For simple webcam/desktop-source style inputs it is adequate; for modern low-latency capture, compare it with DXGI/WGC paths.

## References
- <https://github.com/stevenhoving/libcamcapture/blob/master/src/gdi_capture_source.cpp> - concise GDI capture-source code.

## Connections
- `How to Capture the Screen.md` covers the generic pattern.
- `DX Crop Bitmap.md` touches compositor timing around capture/render loops.
