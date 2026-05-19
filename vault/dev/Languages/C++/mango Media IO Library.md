<!-- generated-from-dump2 -->
# mango Media IO Library

t0rakka's "mango" - a C++ utility library focused on high-performance media I/O: SIMD-accelerated math, image codecs (PNG, JPEG, TGA, DDS, KTX, GIF, BMP, etc.), audio (WAV, MP3, OGG), and a thin filesystem abstraction. Distinguishing feature is that nearly every codec is a single-header implementation written for clarity + SIMD throughput, not pulled in from libpng/libjpeg/etc. Useful as a study of how to write SIMD image-decode loops without depending on the canonical libraries.

```cpp
#include <mango/image/image.hpp>

mango::filesystem::File file("input.png");
mango::image::Bitmap bmp(file);
// bmp.width, bmp.height, bmp.format (RGBA8, etc.)

// Save as KTX with BC7 compression
mango::image::ImageEncodeOptions opts;
mango::image::save("out.ktx", bmp.surface, opts);
```

## References
- <https://github.com/t0rakka/mango>
