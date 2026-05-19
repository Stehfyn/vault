<!-- generated-from-dump2 -->
# Mapnik — Map Tile Rendering Engine

The C++ map-tile rendering engine behind OpenStreetMap's classic raster tiles for over a decade (now partly replaced by vector pipelines, but still the workhorse). Reads OSM/PostGIS/shapefile/geojson, applies a stylesheet in either Mapnik XML or CartoCSS, and rasterizes via AGG (Anti-Grain Geometry) or Cairo. The technically interesting features: a label-placement engine that does collision detection and follows curves (so road labels bend with the road), and the data-source plugin architecture that lets you point a `Map` at PostGIS for vector and GeoTIFF for raster in the same stylesheet. The Python bindings (`python-mapnik`) make it accessible from any tile renderer.

```cpp
#include <mapnik/map.hpp>
#include <mapnik/load_map.hpp>
#include <mapnik/agg_renderer.hpp>
#include <mapnik/image_util.hpp>

mapnik::Map m(800, 600);
mapnik::load_map(m, "stylesheet.xml");    // PostGIS layers + style rules

m.zoom_to_box(mapnik::box2d<double>(-180, -85, 180, 85));   // world

mapnik::image_rgba8 img(800, 600);
mapnik::agg_renderer<mapnik::image_rgba8> ren(m, img);
ren.apply();
mapnik::save_to_file(img, "world.png", "png");
```

## References
- <https://github.com/mapnik/mapnik>
