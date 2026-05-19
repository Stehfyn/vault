<!-- generated-from-dump2 -->
# QMapShack — GPX Route Planner

Qt-based GPX/route/track planner aimed at outdoor users (hiking, cycling, geocaching) — the spiritual successor to QLandkarte GT. Reads vector and raster map tiles (OpenStreetMap, Garmin IMG, OziExplorer, custom tile sources), talks to Garmin GPSr devices for upload/download, supports routing via BRouter (offline) or online services, and handles DEM-based elevation profiles. Not a full GIS in the QGIS sense — no analysis or styling pipeline — but it occupies the gap between "GPX viewer" and "QGIS" extremely well for non-professional use.

```text
Workflow: install -> add a map (OSM tiles or downloaded Garmin .img) and a DEM
(SRTM hgt files) -> plan a route by clicking waypoints -> let BRouter snap to
trails and compute climb -> export GPX to your watch or Garmin handheld.
Project files (.qms) keep the whole plan together.
```

## References
- <https://github.com/Maproom/qmapshack>
