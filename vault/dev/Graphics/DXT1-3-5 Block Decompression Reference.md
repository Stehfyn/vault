<!-- generated-from-dump2 -->
# DXT1/3/5 Block Decompression Reference

Small reference C++ implementation of DXT1/DXT3/DXT5 block decompression — useful when you need to read DDS textures without pulling in a full image library. Each 4x4 block is decoded by reconstructing the two endpoint RGB565 colors, building a 4-entry palette, then looking up per-texel 2-bit indices. DXT3 prepends 4-bit explicit alpha per texel, DXT5 prepends a 64-bit interpolated alpha block analogous to the color block.

```cpp
// Decode one DXT1 4x4 block to 16 RGBA texels.
// (Signature mirrors the project's API style — see header for exact names.)
void DecodeDXT1Block(const std::uint8_t* src, std::uint32_t* outRGBA) {
    std::uint16_t c0 = src[0] | (src[1] << 8);
    std::uint16_t c1 = src[2] | (src[3] << 8);
    // RGB565 -> RGB888 endpoints, then build 4-color palette in c0 > c1 mode.
    // 32-bit index block follows: 2 bits per texel, row-major.
}
```

## References
- <https://github.com/Anteru/dxt-decompress>
