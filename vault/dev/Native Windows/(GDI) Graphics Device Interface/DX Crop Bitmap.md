# DX Crop Bitmap

The linked DirectX cropping discussion is really about synchronizing a host window's movement with a rendered crop of another surface. During `WM_MOVING`, the proposed rectangle arrives in `lParam`; using that rectangle avoids querying stale window bounds. `DwmFlush` can reduce visible lag by waiting for the compositor boundary before rendering the next cropped frame.

This sits at the edge between GDI-era window messages and GPU presentation. If the source is the desktop or another window, prefer DXGI output duplication or DWM-related capture paths for modern code. Use GDI `BitBlt` only when the capture constraints are simple and compositor artifacts are acceptable.

## References
- <https://stackoverflow.com/questions/65714442/direct-x-cropping-bitmap-based-on-window-position-and-rendering-it-back-to-windo> - crop bounds tied to `WM_MOVING` and compositor timing.

## Discussion Claim To Verify

The Stack Overflow resolution makes two testable claims: using the `RECT*` supplied in `WM_MOVING` avoids stale geometry from `GetWindowRect`, and `DwmFlush` removes flicker because it waits at the compositor boundary. Verify them independently; otherwise a reader may cargo-cult both calls when only one matters.

```cpp
case WM_MOVING: {
    RECT from_lparam = *reinterpret_cast<RECT*>(lParam);
    RECT from_query = {};
    GetWindowRect(hwnd, &from_query);

    if (variant == UseLParam) crop = from_lparam;
    if (variant == UseGetWindowRect) crop = from_query;

    if (variant_has_dwm_flush) DwmFlush();
    RenderCrop(crop);
    log(qpc_now(), from_lparam, from_query, variant);
    return 0;
}
```

Expected interpretation: if `from_query` lags `from_lparam` during live dragging, the geometry claim survives. If `DwmFlush` reduces visible judder but increases handler duration by a refresh interval, it is acting as a phase fence, not as a faster render path. If `DwmFlush` does nothing once `lParam` geometry is used, the earlier flicker was stale geometry rather than compositor timing.

## Connections
- `How to Capture the Screen.md` covers GDI capture.
- DirectX/DXGI capture entries elsewhere in Native Windows are the modern GPU-side path.
