<!-- generated-from-dump2 -->
# Mapnik Reference — Style Spec JSON

Versioned machine-readable spec of every Mapnik style property and every datasource parameter, expressed as JSON. Used by anything that needs to validate or generate Mapnik XML/MML without depending on Mapnik itself: CartoCSS compilers (the original Mapbox stack), Carto/Carto-CSS, Tilemill, Kosmtik, and various web tile-server admin UIs. The interesting bit historically: this is the schema that let "design your map in CSS-like syntax and compile it down to Mapnik XML" work, which was the dominant OSM cartography workflow before vector tiles and Mapbox GL Style Spec took over circa 2015.

```jsonc
// Excerpt of the shape — actual file is much larger and versioned per
// Mapnik release.
{
  "version": "3.0.22",
  "style": {
    "line-color":        { "type": "color",  "default-value": "black" },
    "line-width":        { "type": "float",  "default-value": 1.0 },
    "line-opacity":      { "type": "float",  "default-value": 1.0, "range": [0,1] },
    "line-cap":          { "type": "keyword","values": ["butt","round","square"] }
  },
  "datasources": {
    "postgis": {
      "host":     { "type": "string" },
      "dbname":   { "type": "string", "required": true },
      "table":    { "type": "string", "required": true }
    }
  }
}
```

## References
- <https://github.com/mapnik/mapnik-reference>
