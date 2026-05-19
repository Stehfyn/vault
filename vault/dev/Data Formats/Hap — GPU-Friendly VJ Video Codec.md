<!-- generated-from-dump2 -->
# Hap — GPU-Friendly VJ Video Codec

Hap is a video codec from VIDVOX (the company behind VDMX) designed specifically for live VJ / installation work: each frame is encoded with a GPU-friendly block-compressed format (DXT1/5/Snappy-on-top), so playback is "decode on the GPU" rather than CPU YUV->RGB conversion. Achieves ~4K@60Hz playback on integrated GPUs. The repo is the format spec + a reference encoder/decoder and a Quicktime/AVFoundation backend. Standard delivery format for projection mapping software.

```text
# Hap frame layout (simplified):
#   [4-byte little-endian length+type prefix]
#       length = uncompressed payload size (DXT1 bytes for the frame)
#       type   = 0xab (Hap), 0xae (Hap Alpha), 0xbb (Hap Q), 0xbe (Hap Q Alpha)
#   [optional Snappy-compressed DXT chunk]   if section type marks compressed
#
# Decode: 1) Snappy-decompress to DXT block stream, 2) glCompressedTexImage2D
# straight into a GPU texture; no per-frame CPU pixel work.
```

## References
- <https://github.com/Vidvox/hap>
