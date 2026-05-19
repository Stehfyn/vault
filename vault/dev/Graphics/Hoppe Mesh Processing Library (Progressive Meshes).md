<!-- generated-from-dump2 -->
# Hoppe's Mesh Processing Library (Progressive Meshes)

Hugues Hoppe's personal mesh-processing C++ codebase that backed his seminal SIGGRAPH papers from 1992-1998 — surface reconstruction from point clouds (1992), mesh optimization, **progressive meshes** (1996, the lossless mesh LOD scheme that everyone calls "edge collapse simplification"), and view-dependent refinement. Microsoft re-open-sourced it. The code is mostly historical — the algorithms are textbook now, libraries like CGAL/OpenMesh/libigl have cleaner APIs — but reading the original implementation is unusually instructive because Hoppe wrote it before any of those existed and you can see the half-edge data structure (`GMesh`), the quadric error metric, and the priority queue of edge collapses *as they were originally invented*. Useful read for "where did this idea come from."

```text
# Notable programs in the repo (each is its own binary):
#   Recon            - surface reconstruction from unorganized 3D points (1992)
#   MeshSimplify     - quadric-error edge-collapse simplification (PM build)
#   FilterPM         - load a progressive mesh, simplify/refine to a target face count
#   Filtermesh       - smoothing / re-meshing toolkit
#
# Half-edge structure (GMesh) is the workhorse - real mesh-processing libs all
# settle on some variant of half-edge for the same reasons:
#   - O(1) access to incident faces/vertices/edges from any half-edge
#   - clean Euler operators (edge collapse, vertex split) needed by PM
```

## References
- <https://github.com/microsoft/Mesh-processing-library>
