# DeviceCaps

`GetDeviceCaps` reports capabilities of a device context: pixel dimensions, bit depth, logical DPI, printer margins, raster capabilities, palette behavior, and more. It is still useful for printer DCs and legacy GDI decisions, but display DPI values such as `LOGPIXELSX` are virtualized depending on process DPI awareness and are not a modern substitute for `GetDpiForWindow`.

The linked sample is a broad capability dump. Read it as a diagnostic tool, not as an endorsement of choosing layout metrics from a random screen DC. For window layout, prefer per-window DPI APIs; for bitmap allocation, prefer the actual target rectangle and pixel format you intend to render.

## References
- <https://github.com/MrCsabaToth/DeviceCaps> - sample that enumerates many `GetDeviceCaps` indices.

## Connections
- `DPI Awareness/Per-Monitor V2 DPI Reference.md` covers modern DPI queries.
- `Saving a Bitmap to a File.md` and `Read Pixels with GetDIBits().md` use explicit DIB metadata rather than inferred device caps.
