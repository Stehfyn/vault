# libcamcapture - GDI Screen Capture

`libcamcapture` includes a GDI capture source that repeatedly blits from a screen/window DC into a memory surface. It is useful as a small, readable implementation of the old capture model: acquire DC, select bitmap into compatible DC, `BitBlt`, then hand the pixels to the rest of the pipeline.

The limits are the standard GDI limits. It sees the composited desktop as GDI exposes it, not protected content or every GPU overlay, and capture rate is bounded by CPU copies and format conversion. For simple webcam/desktop-source style inputs it is adequate; for modern low-latency capture, compare it with DXGI/WGC paths.

## Source Code Reading

`stevenhoving/libcamcapture/src/gdi_capture_source.cpp` is a clean GDI capture loop. The constructor stores the target `HWND`, obtains the source DC with `GetDC(hwnd)`, creates a compatible memory DC, configures a 32-bpp `BITMAPINFOHEADER`, and owns the selected capture bitmap. The destructor deletes the memory DC and releases the source DC, which is the first lifetime rule to preserve in a probe.

The frame path is:

```cpp
previous = SelectObject(memory_dc, bitmap_frame);
ok = BitBlt(memory_dc, 0, 0, width, height,
            desktop_dc, x, y, SRCCOPY | CAPTUREBLT);
SelectObject(memory_dc, previous);
if (!ok) return false;

lines = GetDIBits(desktop_dc, bitmap_frame,
                  0, height, sample.data(),
                  (BITMAPINFO*)&bitmap_info, DIB_RGB_COLORS);
```

The split matters: `BitBlt` captures into an HBITMAP selected into a memory DC; `GetDIBits` performs the CPU-readable extraction. A useful probe logs those two costs separately and toggles `CAPTUREBLT` to see whether layered windows are included on that machine. If pixels are vertically flipped or channel-swapped, the bug is in the DIB header/orientation/consumer interpretation, not in `BitBlt`.

Cursor drawing is not capture magic either: `_draw_cursor` reads `CURSORINFO`, obtains `ICONINFO`, draws/copies the icon, and deletes `hbmColor`/`hbmMask`. Keep cursor overlay as a separately measured stage.

## References
- <https://github.com/stevenhoving/libcamcapture/blob/master/src/gdi_capture_source.cpp> - concise GDI capture-source code.

## Connections
- `How to Capture the Screen.md` covers the generic pattern.
- `DX Crop Bitmap.md` touches compositor timing around capture/render loops.
