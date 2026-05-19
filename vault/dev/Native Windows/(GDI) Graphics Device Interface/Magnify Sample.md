# Magnify Sample

Magnify10 uses the Windows Magnification API, not raw GDI blitting. The host creates a `WC_MAGNIFIER` child window, sets a source rectangle with `MagSetWindowSource`, and applies scale through `MagSetWindowTransform`. The API handles the capture/display loop for the magnified lens, while the app supplies hotkeys, window placement, and refresh behavior.

This is the right reference when you need a desktop lens rather than a screenshot. It also has the usual desktop-capture caveats: secure surfaces, protected content, and composition details may not appear the way a naive screen DC capture suggests.

## References
- <https://github.com/chrishermans/magnify> - lightweight Magnification API sample with hotkeys.

## Connections
- `How to Capture the Screen.md` is the lower-level GDI capture alternative.
