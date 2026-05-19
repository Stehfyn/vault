<!-- generated-from-dump2 -->
# jebp — Single-Header WebP Decoder

stb-style single-header WebP decoder for C — drop one `jebp.h` into your project, `#define JEBP_IMPLEMENTATION` in one TU, and you can `jebp_decode("image.webp", &w, &h)` without touching libwebp. Handles both lossy (VP8 keyframe) and lossless (VP8L) WebP subsets in one header at ~few-thousand-lines total — much smaller than libwebp + libsharpyuv. The trade-off is no animation, no extended chunks, no alpha-only optimizations — just a static image decode that returns an `RGBA8` buffer. Useful as a hard dependency-free PNG/JPEG-class alternative in game engines / toy renderers, and as a readable reference for the WebP format itself.

```c
#define JEBP_IMPLEMENTATION
#include "jebp.h"

int main(void) {
    jebp_image_t img;
    if (jebp_read(&img, "input.webp") != JEBP_OK) return 1;

    // img.width, img.height, img.pixels is uint32_t* in RGBA order.
    printf("%dx%d\n", img.width, img.height);
    jebp_free_image(&img);
    return 0;
}
```

## References
- <https://github.com/matanui159/jebp>
