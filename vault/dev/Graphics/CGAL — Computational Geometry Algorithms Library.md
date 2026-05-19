<!-- generated-from-dump2 -->
# CGAL — Computational Geometry Algorithms Library

The Computational Geometry Algorithms Library — robust, exact-predicate geometry primitives in C++ (Delaunay/Voronoi, polygon mesh processing, Boolean ops on Nef polyhedra, alpha shapes, surface reconstruction, etc.). The non-obvious thing about CGAL is the kernel concept: you pick a number type (e.g., `Exact_predicates_inexact_constructions_kernel`) and every primitive becomes templated on it, so you trade speed against robustness explicitly at compile time.

```cpp
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> DT;

DT dt;
dt.insert({K::Point_2(0,0), K::Point_2(1,0), K::Point_2(0,1), K::Point_2(1,1)});
for (auto f = dt.finite_faces_begin(); f != dt.finite_faces_end(); ++f) { /* ... */ }
```

## References
- <https://github.com/CGAL/cgal>
