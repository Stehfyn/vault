<!-- generated-from-dump2 -->
# plutofilter — Single-Header SVG Filter Library

Single-header zero-allocation image filter library in C - the filter side of Sammy Cage's `plutovg`/`plutosvg` 2D ecosystem. Implements the SVG/CSS `filter` primitives (`feGaussianBlur`, `feColorMatrix`, `feComposite`, `feBlend`, `feMorphology`, `feFlood`, `feOffset`) on raw RGBA buffers with stack-only scratch space. Useful when you have a small renderer that doesn't want to drag in a full image library to do "blur this region by N px."

```c
#include "plutofilter.h"

// In-place 5px Gaussian blur on an RGBA image
plutofilter_blur(rgba, w, h, /*stride=*/ w*4, /*radius=*/ 5);

// Multi-step graph: blur, then color-shift, then composite over background
plutofilter_color_matrix(rgba, w, h, w*4, matrix);
plutofilter_composite(dst, src, w, h, PLUTOFILTER_COMP_OVER);
```

## References
- <https://github.com/sammycage/plutofilter>
