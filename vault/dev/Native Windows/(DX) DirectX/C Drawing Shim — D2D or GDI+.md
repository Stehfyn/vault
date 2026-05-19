# C Drawing Shim - D2D or GDI+

Martin Mitas' `windrawlib` is a plain-C drawing shim that chooses Direct2D when available and GDI+ on older Windows. The point is not abstraction for its own sake; it gives C Win32 code a small retained API surface without forcing COM class wrappers, while still letting a single binary run from XP-era systems through modern Windows.

This belongs near the Direct2D-in-C note, but the goals differ. `c_d2d_dwrite` exposes D2D/DWrite COM vtables directly to C; `windrawlib` hides the backend and trades control for portability. Use the former when you need exact D2D behavior, the latter when a control/library just needs lines, brushes, text, and bitmaps across old Windows versions.

## References
- <https://github.com/mity/windrawlib>

## Connections
- `Direct2D and DirectWrite in C.md`
- `(D2D) Direct2D.md`
