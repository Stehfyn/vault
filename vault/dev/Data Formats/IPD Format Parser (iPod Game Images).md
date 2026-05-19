<!-- generated-from-dump2 -->
# IPD Format Parser (iPod Game Images)

Parser for the `.ipd` image container used by iPod-era games. The file starts with a 16-byte header (little-endian) describing width, height, color mode, and bits-per-pixel; the rest is raw pixel data. Supports indexed-color (1/2/4/8-bit palette) and a handful of RGB/grayscale layouts. Useful as a tiny reference of how legacy game-console image containers are typically structured (no compression, palette table inline, pixel rows packed LSB-first).

```python
# Conceptual: header layout used by ipd.py
# offset 0: u16 magic? (varies)
# offset 2: u16 width
# offset 4: u16 height
# offset 6: u8  color_mode  (0 = gray, 1 = rgb, 2 = indexed, ...)
# offset 7: u8  bits_per_pixel
# offset 8: u64 reserved / palette offset
import struct, sys
data = open(sys.argv[1], "rb").read()
_, w, h, mode, bpp = struct.unpack_from("<HHHBB", data, 0)
print(f"{w}x{h} mode={mode} bpp={bpp}")
```

## References
- <https://github.com/760ceb3b9c0ba4872cadf3ce35a7a494/ipd>
