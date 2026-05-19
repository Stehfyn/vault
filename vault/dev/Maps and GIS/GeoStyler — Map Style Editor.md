<!-- generated-from-dump2 -->
# GeoStyler — Map Style Editor

TypeScript/React component for editing map cartography styles in a renderer-agnostic way. The actually useful thing is the **GeoStyler Style** intermediate format: an in-memory JSON model of layers / rules / symbolizers that has bidirectional **parsers** to and from every major styling format the GIS ecosystem uses — OGC SLD/SE (used by GeoServer, MapServer), Mapbox/MapLibre GL JSON, QGIS QML, OpenLayers, Mapfile. So you wire up the React component once and your users can edit a style and export it to any renderer they're using. Sister repos (`geostyler-sld-parser`, `geostyler-mapbox-parser`, etc.) implement the translations. Useful as a reference for "how do these styling formats actually map onto each other," which is annoyingly underdocumented.

```typescript
import GeoStylerStyle from 'geostyler-style';
import SldParser from 'geostyler-sld-parser';
import MapboxParser from 'geostyler-mapbox-parser';

// Read SLD (e.g. from a GeoServer-published layer)
const sldParser = new SldParser();
const { output: style }: { output: GeoStylerStyle } =
    await sldParser.readStyle(sldXml);

// Re-emit as MapLibre GL JSON
const mapboxParser = new MapboxParser();
const { output: mbStyle } = await mapboxParser.writeStyle(style);
// Now drop mbStyle into a MapLibre map.
```

## References
- <https://github.com/geostyler/geostyler>
