# Button Right-Side Icon (Owner-Draw)

Putting an icon on the right side of a classic push button is a small owner-draw problem, not a separate control problem. With `BS_OWNERDRAW`, the parent receives `WM_DRAWITEM`, inspects `DRAWITEMSTRUCT::itemState`, paints the themed or custom background, lays out text, and draws the icon near the right edge. The nuance is state fidelity: pressed, disabled, focused, hot, and high-DPI image sizes all need explicit handling once you opt out of the stock renderer.

Use this pattern when the stock `BM_SETIMAGE` left-icon behavior is not enough. For broader styling, prefer `NM_CUSTOMDRAW` where the control supports it; full owner-draw means you own accessibility-adjacent visual cues as well as pixels.

## References
- <https://www.codeproject.com/Tips/5317407/Win32-Cplusplus-Add-Icon-to-Right-Side-of-Button-T> - narrow owner-draw button example with right-aligned icon layout.

## Connections
- `Rendering.md` covers `NM_CUSTOMDRAW` return codes.
- `Visual Styles.md` covers using UxTheme parts so owner-drawn controls still resemble the OS.
