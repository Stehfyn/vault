<!-- generated-from-dump2 -->
# Matplot++ Plotting Library

C++ port of Python's matplotlib API with a near-identical surface (`plot`, `scatter`, `hist`, `surf`, `quiver`, `subplot`...). The non-obvious implementation choice: it doesn't render anything itself — it shells out to gnuplot. That keeps the lib tiny but means deploys need gnuplot on PATH and you trade some interactivity for the convenience of identical Python-mental-model code. Supports 3D plots, polar/parallel-coordinates/sankey, animations (gif/mp4), and SVG/PNG export. The CMake hookup is straightforward (`find_package(Matplot++)`); for header-only-ish use there's a single-include amalgamation.

```cpp
#include <matplot/matplot.h>
using namespace matplot;

std::vector<double> x = linspace(0, 2 * pi);
std::vector<double> y = transform(x, [](auto v) { return sin(v); });

plot(x, y);
title("sine");
xlabel("x"); ylabel("sin(x)");
show();           // pops a gnuplot window
// save("sine.png");
```

## References
- <https://github.com/alandefreitas/matplotplusplus>
