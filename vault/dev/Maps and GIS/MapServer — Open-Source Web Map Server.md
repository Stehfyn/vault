<!-- generated-from-dump2 -->
# MapServer — Open-Source Web Map Server

One of the original open-source web map servers, born at the University of Minnesota in the late 90s and now an OSGeo project. Renders maps server-side from a Mapfile config (the original .map text format predates anything XML-based) and serves them as WMS, WFS, WCS, WMTS, and GeoJSON. Pre-dates and overlaps with GeoServer (Java) — MapServer is C, faster per request on commodity hardware, with a smaller memory footprint, but a much more austere admin experience. Still very much in production at agencies that have been running it since 2003 and have no reason to migrate.

```text
# example.map — minimal Mapfile
MAP
  NAME "world"
  EXTENT -180 -90 180 90
  SIZE 800 400
  IMAGETYPE "png"
  LAYER
    NAME   "countries"
    TYPE   POLYGON
    DATA   "countries.shp"
    STATUS DEFAULT
    CLASS
      STYLE  COLOR 200 200 200  OUTLINECOLOR 0 0 0  END
    END
  END
END
# Render: shp2img -m example.map -o out.png
# Serve:  point your CGI at mapserv and pass map=/path/example.map
```

## References
- <https://github.com/MapServer/MapServer>
