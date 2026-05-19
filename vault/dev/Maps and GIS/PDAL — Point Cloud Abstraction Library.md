<!-- generated-from-dump2 -->
# PDAL — Point Cloud Abstraction Library

PDAL is to point clouds what GDAL is to raster/vector geospatial data — a C++ library plus CLI for reading, transforming, filtering, and writing point clouds across the format zoo (LAS/LAZ, COPC, EPT, E57, PLY, PCD, vendor formats, and database backends like PostgreSQL Pointcloud). The pipeline-of-stages model (readers -> filters -> writers, configured in JSON) is the central abstraction; everything from classification, outlier removal, ground filtering (SMRF/PMF), and HAG normalisation to gridding into rasters and re-projecting is just a filter. Used as plumbing inside QGIS, Entwine, Untwine, and most academic lidar workflows.

```json
{
  "pipeline": [
    "input.laz",
    {
      "type": "filters.reprojection",
      "out_srs": "EPSG:3857"
    },
    {
      "type": "filters.smrf"
    },
    {
      "type": "filters.range",
      "limits": "Classification[2:2]"
    },
    {
      "type": "writers.gdal",
      "resolution": 1.0,
      "output_type": "idw",
      "filename": "ground_dtm.tif"
    }
  ]
}
```

```bash
pdal pipeline ground-to-dtm.json
```

## References
- <https://github.com/PDAL/PDAL>
