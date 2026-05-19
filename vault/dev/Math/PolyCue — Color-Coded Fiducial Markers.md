<!-- generated-from-dump2 -->
# PolyCue — Color-Coded Fiducial Markers

Designs printable fiducial markers that survive harsh photogrammetry conditions where ChArUco / AprilTag bit grids fail (motion blur, glare, low-DPI prints). The novel idea is encoding ID in multicolor regions rather than black-and-white bit cells: each marker is a small polygon whose vertices carry independent color codes, so the detector can recover both pose (geometry) and ID (color permutation) even when ~half the marker is unreadable. Useful for outdoor scanning rigs, SLAM ground truth, and museum/archaeology scans where you can't repaint the scene.

```text
# Conceptual pipeline (Python prototype in repo):
#   1. Capture image -> find candidate polygons in HSV space.
#   2. For each polygon, sample interior color near each vertex.
#   3. Quantize sampled colors against the codebook to get a vertex-color tuple.
#   4. Look up tuple in the ID dictionary; if found, solvePnP using polygon
#      corners (known marker geometry) to get the camera pose.
```

## References
- <https://github.com/Chrismofer/PolyCue>
