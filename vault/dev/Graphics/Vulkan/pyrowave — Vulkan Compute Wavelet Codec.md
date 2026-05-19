<!-- generated-from-dump2 -->
# pyrowave — Vulkan Compute Wavelet Codec

Themaister's experimental wavelet image codec running entirely as Vulkan compute shaders. Targets sub-millisecond decode of HD frames on a discrete GPU. Notable because traditional image codecs (libjpeg, libvpx) decode on the CPU then upload; pyrowave does the inverse wavelet transform + entropy decode in GPU compute, so the result lands directly in a sampled image - useful for high-frame-rate UI textures or low-latency video streaming. The compression isn't competitive with HEVC but the decode pipeline is.

```text
# High-level Vulkan pipeline:
#   stage 0: parse compressed bitstream into per-subband coefficient SSBOs
#   stage 1: dispatch inverse-quantization compute shader
#   stage 2: dispatch inverse-wavelet-lifting compute pass (CDF 9/7)
#            -> writes mip0 of an output VK_FORMAT_R8G8B8A8_UNORM image
#   present from that image directly (no CPU readback)
```

## References
- <https://github.com/Themaister/pyrowave>
