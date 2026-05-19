# emphasize - Tringi Win32 Utility Snippets

`tringi/emphasize` is a small Win32 utility collection worth mining for message-pump, theming, and DPI idioms rather than for a reusable framework. The DPI-relevant pattern is manifest-less opt-in: resolve modern USER32 functions at runtime, set the process or thread DPI awareness before creating windows, and relayout on `WM_DPICHANGED` using the suggested rectangle instead of inventing a new position.

The nearby `tringi/win32-dpi` repository is the deeper reference; `emphasize` is useful because it shows the same ideas embedded in practical utility code. That matters when retrofitting a native tool that already has custom controls, dark-mode shims, and manual layout: DPI awareness is not a single manifest switch, it is a contract for every font, margin, bitmap, hit-test rectangle, and owner-drawn control.

## References
- <https://github.com/tringi/emphasize> - compact Win32 snippets, including runtime DPI and theme handling patterns.

## Connections
- `Per-Monitor V2 DPI Reference.md` is the focused DPI implementation reference from the same author.
- `Dialog Units.md` in Common Controls explains the older font-relative sizing system that DPI-aware dialog code often still has to preserve.
