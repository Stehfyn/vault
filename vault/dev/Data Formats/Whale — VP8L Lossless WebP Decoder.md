<!-- generated-from-dump2 -->
# Whale — VP8L Lossless WebP Decoder

From-scratch decoder for the **VP8L** codec — the lossless half of WebP — designed as a single-file C library you can drop in instead of libwebp's much larger lossless decode path. VP8L is interesting because, unlike PNG (which is just zlib over a per-row delta predictor), it ships four image-transform primitives that the encoder can stack — predictor, color, subtract-green, and color-indexing — each of which decorrelates the pixel stream before a custom Huffman-coded LZ77 entropy coder. The decoder has to reverse the transforms in encoded order and demux multiple Huffman trees per meta-block. Read for an exceptionally clean implementation of "what does WebP actually do under the hood?"

```c
// Conceptual decode pipeline (see whale.c):
//   1. Parse RIFF/VP8L header -> width, height, alpha_used.
//   2. Read transform stack: while (read_bit() == 1) { transform_type = ...; }
//      Each transform stores parameters in the bitstream.
//   3. Decode the entropy-coded image: LZ77-style "back-reference" + "color-cache"
//      symbols using multiple Huffman trees for ARGB channels.
//   4. Apply each transform in REVERSE order on the decoded ARGB array:
//        predictor  - undo per-tile spatial predictor
//        color      - undo cross-channel color delta
//        subgreen   - add green back to R and B
//        indexing   - palette lookup
//   5. Emit ARGB pixels.
```

## References
- <https://github.com/fencl/whale>
