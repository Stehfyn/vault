<!-- generated-from-dump2 -->
# libvips — Streaming Image Processing Library

The image-processing library you reach for when ImageMagick runs out of RAM on a 50000x50000 TIFF. libvips' core trick is **demand-driven, streamed processing**: it represents an image as a *pipeline of operations* against region-by-region sources, not as a fully-materialized pixel buffer, so a 10-step pipeline on a gigapixel image only needs the working-set memory of a single horizontal scanline (or band of scanlines) at a time. Threaded by default at the region level. C library with C++/Ruby/Python/Node bindings; the Node binding (`sharp`) is what makes most images on the modern web fly through resize. Format support is huge (TIFF/PNG/JPEG/WebP/HEIF/AVIF/JP2/SVG/PDF/raw).

```c
#include <vips/vips.h>

int main(int argc, char** argv) {
    VIPS_INIT(argv[0]);
    VipsImage* in;
    if (vips_image_new_from_file("input.tif", &in,
                                 "access", VIPS_ACCESS_SEQUENTIAL, NULL))
        return 1;

    VipsImage* out;
    if (vips_thumbnail("input.tif", &out, 1024, NULL))
        return 1;

    if (vips_image_write_to_file(out, "thumb.jpg", "Q", 85, NULL))
        return 1;

    g_object_unref(in);
    g_object_unref(out);
    return 0;
}
```

```bash
# CLI usage — same engine, scriptable:
vips thumbnail input.tif thumb.jpg 1024 --crop centre
```

## References
- <https://github.com/libvips/libvips>
