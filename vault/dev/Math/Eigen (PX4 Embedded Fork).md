<!-- generated-from-dump2 -->
# Eigen (PX4 Embedded Fork)

PX4 Autopilot's fork of Eigen, pinned to a known-good revision and stripped/patched for the embedded flight-controller use case (no exceptions, no RTTI, controlled allocations, Cortex-M friendly). Eigen itself is the default C++ linear-algebra library — expression-template based, header-only, BLAS/LAPACK-compatible, and central to anything doing Kalman filters, SLAM, control, or computer vision. PX4 cares about the fork because upstream Eigen sometimes regresses on tiny-matrix performance or on architectures the autopilot targets (STM32H7, Snapdragon Flight, etc.).

```cpp
#include <Eigen/Dense>
using namespace Eigen;

// Tiny dense linear solve, the bread-and-butter case
Matrix3f A; A << 1, 2, 3,  4, 5, 6,  7, 8, 10;
Vector3f b; b << 3, 3, 4;
Vector3f x = A.colPivHouseholderQr().solve(b);

// Quaternion rotation, used everywhere in aerospace
Quaternionf q = AngleAxisf(M_PI/4, Vector3f::UnitZ());
Vector3f v_rot = q * Vector3f(1, 0, 0);
```

## References
- <https://github.com/PX4/eigen>
