<!-- generated-from-dump2 -->
# Mapnik Multithread Tile Rendering Demo

Demo/utility for batch-rendering OSM tiles with Mapnik across many CPU cores. The non-obvious complication is that Mapnik's `Map` object is **not** thread-safe — sharing it between rendering threads will crash or corrupt output. The pattern here is the standard one used by `polytile`, `tilerator`, and similar production batch-renderers: one `Map` per thread, each loading the same XML stylesheet independently, sharing only the *input* tile coordinate queue and the *output* sink. Useful as a minimal example of "how do you actually scale Mapnik horizontally without crashing it" — every team eventually re-derives this and it's worth having a reference.

```cpp
// Conceptual: per-thread Map; only the work queue is shared.
#include <mapnik/map.hpp>
#include <mapnik/agg_renderer.hpp>
#include <mapnik/image_util.hpp>

void worker(BlockingQueue<TileCoord>& q, std::string stylesheet, std::string outDir) {
    mapnik::Map m(256, 256);
    mapnik::load_map(m, stylesheet);                  // own copy per thread

    for (TileCoord c; q.pop(c); ) {
        m.zoom_to_box(tileBoundsToBox(c));
        mapnik::image_rgba8 img(256, 256);
        mapnik::agg_renderer<mapnik::image_rgba8> r(m, img);
        r.apply();
        mapnik::save_to_file(img, outDir + "/" + c.path(), "png");
    }
}
```

## References
- <https://github.com/gisupc/mapnik_multithread>
