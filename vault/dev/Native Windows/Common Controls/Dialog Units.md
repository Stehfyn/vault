# Dialog Units

Dialog units are font-relative layout units used by Win32 dialog templates: horizontal units are based on one quarter of the dialog font's average character width, and vertical units on one eighth of its height. `MapDialogRect` converts a DLU rectangle to pixels using the dialog's current font, which is why changing `DS_SETFONT` changes the apparent geometry of the whole dialog.

DLUs are not obsolete just because DPI APIs exist. Legacy dialogs, property sheets, and resource templates still express sizes this way, and DPI-aware code often has to preserve that behavior while mixing in pixel-based custom controls. Convert at the boundary, after the dialog font is set, and do not cache DLU-to-pixel results across font or DPI changes.

## References
- <https://github.com/andlabs/windlgunits/blob/master/main.c> - compact experiment showing how dialog-unit conversion behaves.

## Connections
- `DPI Awareness/Per-Monitor V2 DPI Reference.md` explains the modern DPI notification layer.
