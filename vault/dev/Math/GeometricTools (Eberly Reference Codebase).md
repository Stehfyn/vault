<!-- generated-from-dump2 -->
# GeometricTools (Eberly Reference Codebase)

David Eberly's two-decade-old reference codebase covering computational geometry, CAGD/curve-surface, image analysis, mesh processing, and rigid-body physics — the implementations behind his book series "Geometric Tools for Computer Graphics" and the older Wild Magic engine. The unique value is breadth and rigor: distance/intersection routines for every pair of common primitives (line/segment/ray vs triangle/tetra/box/cylinder/torus...), often with the careful numerical-stability variants you don't find in casual one-off blog posts. Heavy on templated C++; modern reorganization is GTE/Mathematics. Many real engines (Bullet, PhysX docs, OpenVDB tools) cite Eberly for these algorithms.

```cpp
// Flavour: closest distance between two line segments in 3D, the
// reference implementation everyone copies. (See GTE/Mathematics/DistSegmentSegment.h)
#include <Mathematics/DistSegmentSegment.h>
using namespace gte;

Segment<3, double> s0({0,0,0}, {1,0,0});
Segment<3, double> s1({0,1,1}, {1,1,1});

DCPQuery<double, Segment<3,double>, Segment<3,double>> query;
auto result = query(s0, s1);
// result.distance, result.closest[0], result.closest[1]
```

## References
- <https://github.com/davideberly/GeometricTools>
