<!-- generated-from-dump2 -->
# msdf-atlas-gen — MSDF Font Atlas Tool

Command-line tool (and C++ library) that bakes a multi-channel signed distance field font atlas from a TTF/OTF, suitable for crisp scalable text in GL/Vulkan/D3D shaders. Built on Chlumsky/msdfgen; the atlas tool adds glyph packing, charset handling, and metadata export (JSON/CSV/binary). MSDF beats single-channel SDF at preserving sharp corners, which is why this is the standard choice for game-engine text rendering.

```bash
# 32 px MSDF atlas of ASCII printable + Unicode arrows, 4 px padding, JSON metadata.
msdf-atlas-gen -font Roboto-Regular.ttf -charset charset.txt \
    -type msdf -format png -imageout atlas.png \
    -size 32 -pxrange 4 -json atlas.json
```

## References
- <https://github.com/Chlumsky/msdf-atlas-gen>
