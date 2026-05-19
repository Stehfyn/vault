<!-- generated-from-dump2 -->
# rectpack2D — 2D Rectangle Packer

Header-only 2D rectangle packer used for texture atlases, sprite sheets, and lightmap packing. Implements a fast variant of the empty-space-list / guillotine algorithm with multi-bin support and configurable heuristics (best-area-fit, best-short-side-fit, etc.). Notable because it's used in Assassin's Creed and Snapchat — the underlying paper is by Jukka Jylanki.

```cpp
#include <rectpack2D/finders_interface.h>
using namespace rectpack2D;

std::vector<rect_xywh> rects = { {0,0, 64,64}, {0,0, 128,32}, {0,0, 16,16} };
auto report = find_best_packing<empty_spaces<false>>(
    rects,
    make_finder_input(/*max_side*/ 2048,
                      /*discard_step*/ 1,
                      /*on_success*/ [](rect_xywh&){ return callback_result::CONTINUE_PACKING; },
                      /*on_failure*/ [](rect_xywh&){ return callback_result::ABORT_PACKING; },
                      flipping_option::DISABLED));
// report.w / report.h give the chosen atlas dimensions.
```

## References
- <https://github.com/TeamHypersomnia/rectpack2D>
