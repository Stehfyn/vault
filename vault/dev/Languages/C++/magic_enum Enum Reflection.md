<!-- generated-from-dump2 -->
# magic_enum Enum Reflection

Header-only enum reflection for C++17 — `to_string(MyEnum::Foo) == "Foo"`, `enum_cast<MyEnum>("Foo") == MyEnum::Foo`, `enum_values<MyEnum>()`, no codegen, no `X-macro`, no `enum_to_string` boilerplate. The implementation pulls the trick of stamping a templated function (`__PRETTY_FUNCTION__` / `__FUNCSIG__`) and parsing the compiler's pretty-printed string back into a name at compile time — so enumerators are bounded by a configurable range `[MAGIC_ENUM_RANGE_MIN, MAGIC_ENUM_RANGE_MAX]` (default `-128..128`). Caveat: that range bound is the headline gotcha; sparse or large enums need `magic_enum::customize` or a wider range, both of which raise compile time noticeably.

```cpp
#include <magic_enum.hpp>

enum class Color { Red = 1, Green = 7, Blue = 9 };

auto s   = magic_enum::enum_name(Color::Green);   // "Green"
auto c   = magic_enum::enum_cast<Color>("Blue");  // optional<Color>{Blue}
auto all = magic_enum::enum_values<Color>();      // {Red, Green, Blue}

for (auto [val, name] : magic_enum::enum_entries<Color>())
    std::cout << name << " = " << static_cast<int>(val) << '\n';
```

## References
- <https://github.com/Neargye/magic_enum>
