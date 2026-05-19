<!-- generated-from-dump2 -->
# edge264 — Minimal H.264 Decoder

Minimalist H.264/AVC decoder in plain C99 - single repo, no FFmpeg dependency. Implements a working subset of the standard targeted at "decode IP-camera streams cheaply on edge devices": Baseline + Main profiles, in-loop deblocking, CABAC entropy decoding. Useful as study material for H.264 internals; readable in a way the FFmpeg codebase is not, because there's no codec-selection abstraction layer.

```c
#include "edge264.h"
Edge264Context ctx;
edge264_init(&ctx);

while (read_nal_unit(&buf, &len)) {
    Edge264Frame frame;
    int got = edge264_decode_NAL(&ctx, buf, len, &frame);
    if (got == 1) {
        // frame.planes[Y, Cb, Cr], frame.stride, frame.width/height
        present(&frame);
    }
}
edge264_free(&ctx);
```

## References
- <https://github.com/tvlabs/edge264>
