# BmpHeaderViewer - DIB Header Forensics

BmpHeaderViewer is useful because BMP is not one format in practice; it is a file header followed by one of several DIB header generations plus optional masks, palettes, ICC/profile data, gaps, and padded pixels. A viewer that exposes `BITMAPCOREHEADER`, `BITMAPINFOHEADER`, `BITMAPV4HEADER`, `BITMAPV5HEADER`, masks, gamma, color space, and alpha fields quickly answers why GDI, WIC, and an image editor disagree about the same file.

Use it when the bug is "my bitmap loads but alpha/color/stride is wrong." The header-size discriminator and pixel offset are usually more important than the nominal `.bmp` extension.

## References
- <https://github.com/Electron-x/BmpHeaderViewer> - BMP/DIB header inspection tool.

## Connections
- `32-bit BMP.md` covers alpha and header-variant ambiguity.
- `bmptoascii - Single-Header BMP to ASCII.md` is the consumer-side parsing counterpart.
