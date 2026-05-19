# Direct2D and DirectWrite in MFC

These samples matter because MFC's doc/view paint model is not the same as the raw Win32 loop assumed by most Direct2D examples. A `CView::OnDraw` path has to create an HWND render target for the view, call `BeginDraw`/`EndDraw` in the right paint lifetime, and tear down device-dependent resources when `EndDraw` returns `D2DERR_RECREATE_TARGET`.

The key MFC nuance is resource classification. Text formats and geometries can survive device loss; render targets, brushes, and bitmaps tied to the device cannot. That is the detail that prevents "works until resize/driver reset" bugs in retrofitted MFC applications.

## References
- <https://github.com/ocucu/direct2d-directwrite-samples>

## Connections
- `(D2D) Direct2D.md`
- `Text Stack Side-by-Side Sampler.md`
