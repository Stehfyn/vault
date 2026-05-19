<!-- generated-from-dump2 -->
# simple_enum Bounded Enum Reflection

C++20 enum-reflection library that competes with `magic_enum` but trades convenience for compile time. The key design choice: enums must declare their bounds explicitly (either via `first`/`last` enumerators inside the enum, or an ADL hook `enum_bounds_v<E>`), so the library doesn't have to scan every integer value in the underlying type to find the live ones. The author cites concrete numbers — for a 104-value enum, compile cost drops from ~200 ms (magic_enum) to ~12 ms. Provides `enum_name`, `enum_cast<E>(string)`, `enum_view<E>`, plus drop-ins for Glaze JSON, `std::format`/`fmt`, and `std::error_code`. Worth picking if magic_enum is showing up on your build-time profile.

```cpp
#include <simple_enum/simple_enum.hpp>

enum struct Color { Red = 1, Green, Blue, first = Red, last = Blue };

static_assert(simple_enum::enum_name(Color::Green) == "Green");

if (auto v = simple_enum::enum_cast<Color>("Blue")) {
    Color c = *v;  // Color::Blue
    (void)c;
}

for (auto c : simple_enum::enum_view<Color>{})
    std::cout << simple_enum::enum_name(c) << '\n';
```

## References
- <https://github.com/arturbac/simple_enum>
