<!-- generated-from-dump2 -->
# zero — Cross-Platform Pixel Framebuffer Header

Single-header C lib for "put a pixel on the screen" across Win32 GDI, X11, Linux framebuffer, OpenGL, Canvas, WebGL, and PNG out. Modeled on the demoscene-era **TinyPTC** (Gaffer-on-Games-era "pixel-tracer canvas"). The interesting bit is the cross-platform tactic: same `zero_open` / `zero_update(uint32_t* fb)` API across radically different backends, each backend implemented as a tiny shim — Windows blits an ARGB DIB via `StretchDIBits` per frame, Linux fb just `mmap`s `/dev/fb0`, Canvas via Emscripten copies into `ImageData`. Great teaching scaffold for software rasterizers, raytracers, CA toys — anything where you want to drop a 32-bit framebuffer in front of yourself with zero engine ceremony.

```c
#include "zero.h"
#define W 640
#define H 480
static uint32_t fb[W*H];

int main(void) {
    zero_open("hello", W, H);
    for (uint32_t t = 0; zero_event() != ZERO_EVENT_CLOSE; t++) {
        for (int y = 0; y < H; ++y)
            for (int x = 0; x < W; ++x)
                fb[y*W + x] = (uint32_t)((x ^ y) + t) | 0xFF000000;
        zero_update(fb);
    }
    zero_close();
}
```

## References
- <https://github.com/feiss/zero>
