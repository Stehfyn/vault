# DX Crop Bitmap

The linked DirectX cropping discussion is really about synchronizing a host window's movement with a rendered crop of another surface. During `WM_MOVING`, the proposed rectangle arrives in `lParam`; using that rectangle avoids querying stale window bounds. `DwmFlush` can reduce visible lag by waiting for the compositor boundary before rendering the next cropped frame.

This sits at the edge between GDI-era window messages and GPU presentation. If the source is the desktop or another window, prefer DXGI output duplication or DWM-related capture paths for modern code. Use GDI `BitBlt` only when the capture constraints are simple and compositor artifacts are acceptable.

## References
- <https://stackoverflow.com/questions/65714442/direct-x-cropping-bitmap-based-on-window-position-and-rendering-it-back-to-windo> - crop bounds tied to `WM_MOVING` and compositor timing.

## Connections
- `How to Capture the Screen.md` covers GDI capture.
- DirectX/DXGI capture entries elsewhere in Native Windows are the modern GPU-side path.
