# bmptoascii - Single-Header BMP to ASCII

`bmptoascii` is a single-header C17 BMP parser that maps pixel luminance to a text ramp. The relevant implementation details are the same ones every BMP consumer must get right: BMP pixels are BGR/BGRA, rows are padded to four-byte boundaries, and positive `biHeight` means bottom-up storage. A parser that ignores stride or row direction will appear to work on square toy images and fail on real captures.

The wide-string output is a nice fit for Windows console or GDI text rendering, but the main value here is as a compact example of DIB walking without a heavyweight decoder. It pairs well with header-inspection tools when validating hand-written BMP emitters.

## References
- <https://github.com/anoban/bmptoascii> - dependency-light BMP-to-text converter.

## Connections
- `BmpHeaderViewer - DIB Header Forensics.md` helps validate headers before parsing pixels.
- `Saving a Bitmap to a File.md` covers producer-side BMP output.
