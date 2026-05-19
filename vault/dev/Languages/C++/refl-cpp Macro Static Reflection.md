<!-- generated-from-dump2 -->
# refl-cpp Macro Static Reflection

C++17 static reflection library — slightly older approach than `qlibs/reflect`: requires macro registration (`REFL_AUTO((field, a), (field, b))`) but in return gives you proxy types, attribute decoration, base-class walking, and overload sets, not just "list of members". Lets you build serializers, ORMs, and editor-property inspectors without runtime cost. The macro overhead is the cost of supporting non-aggregates and inheritance; aggregate-only macro-free libraries (PFR, qlibs/reflect) can't see private members or base classes. Pick this one if you need real reflection (attributes, polymorphism) on C++17.

```cpp
#include <refl.hpp>

struct Point { int x, y; };

REFL_AUTO(
    type(Point),
    field(x),
    field(y)
)

refl::runtime::debug(std::cout, Point{3, 4});   // Point { x = 3, y = 4 }

for_each(refl::reflect<Point>().members, [](auto m){
    std::cout << get_display_name(m) << '\n';   // "x", then "y"
});
```

## References
- <https://github.com/veselink1/refl-cpp>
