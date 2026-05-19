# Flicker-Free Drawing

Classic GDI flicker usually comes from two paints: USER erases the background, then the app paints content. If your `WM_PAINT` redraws the whole invalid region, return nonzero from `WM_ERASEBKGND` and paint into a memory DC backed by a compatible bitmap or DIB section, then `BitBlt` once to the window DC. Also avoid resizing/moving child windows one at a time without batching.

Layered windows solve a different problem: per-pixel top-level alpha through `UpdateLayeredWindow` or whole-window opacity through `SetLayeredWindowAttributes`. They can eliminate some flicker because presentation is atomic, but they change hit testing, redirection, capture behavior, and composition cost. Do not use them merely because a control repaints badly.

## References
- <https://stackoverflow.com/a/20959649> - practical GDI double-buffering pattern.
- <https://learn.microsoft.com/en-us/dotnet/desktop/winforms/advanced/using-double-buffering?view=netframeworkdesktop-4.8> - managed overview, useful for the same erase/paint model.

## Connections
- `Common Controls/Rendering.md` covers custom draw and resize flicker.
- `Transparent Window GDI.md` covers layered-window alpha.
