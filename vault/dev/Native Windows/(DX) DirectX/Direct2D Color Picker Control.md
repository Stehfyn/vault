# Direct2D Color Picker Control

Michael Chourdakis' color picker is a useful custom-control reference because it uses Direct2D for the parts that GDI examples usually fake with per-pixel loops: hue/value gradients, DPI-independent geometry, and smooth redraw under resize. The control demonstrates how D2D helps when the widget is inherently vector/gradient-heavy rather than just a themed button.

The lesson is that custom controls need a full Win32 contract, not only drawing code: input capture, invalidation, DPI scaling, color-space conversion, and device-resource recreation. Read it beside `Title Bar Customization.md` in the DWM folder if the goal is system-looking custom chrome.

## References
- <https://github.com/WindowsNT/ColorPicker>

## Connections
- `(D2D) Direct2D.md`
- `../(DWM) Desktop Window Manager/Title Bar Customization.md`
