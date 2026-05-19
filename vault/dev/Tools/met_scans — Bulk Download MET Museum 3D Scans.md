<!-- generated-from-dump2 -->
# met_scans — Bulk Download MET Museum 3D Scans

Quick Python scraper that walks the Metropolitan Museum of Art's Open Access search API, filters to entries with attached 3D scans (Sketchfab/CDN-hosted GLB), and downloads the binary glTF assets in bulk. Useful as a starting corpus for photogrammetry / mesh-processing pipelines or VR scenes when you don't want to hand-click through the MET's web UI. The Met's API itself is undocumented for the 3D field; the script's value is mostly knowing which JSON key holds the GLB URL.

```python
# Sketch (real entry point is the single script in the repo):
import requests, pathlib
SEARCH = "https://collectionapi.metmuseum.org/public/collection/v1/search"
OBJECT = "https://collectionapi.metmuseum.org/public/collection/v1/objects/{}"
ids = requests.get(SEARCH, params={"q": "*", "hasImages": "true"}).json()["objectIDs"]
for oid in ids:
    obj = requests.get(OBJECT.format(oid)).json()
    glb = obj.get("additionalImages3D") or obj.get("modelUrl")  # field name varies
    if glb:
        pathlib.Path(f"out/{oid}.glb").write_bytes(requests.get(glb).content)
```

## References
- <https://github.com/InconsolableCellist/met_scans>
