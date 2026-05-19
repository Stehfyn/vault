<!-- generated-from-dump2 -->
# nameof Variable and Type Name Operator

Header-only C++17 `nameof()` operator — `NAMEOF(my_var) == "my_var"`, `NAMEOF_TYPE(int) == "int"`, `NAMEOF_FULL_TYPE(std::string) == "std::__cxx11::basic_string<...>"`. Sister project to Neargye's `magic_enum`. The variable/function/macro forms are macros (necessary — you can't introspect the *name* of a local without source-level access); the type/short-type forms are constexpr functions backed by `__PRETTY_FUNCTION__` / `__FUNCSIG__` string parsing. Useful for logging, serialization, ImGui debug overlays — the kinds of places where you used to write `#define LOG(x) log(#x, x)` and accept the macro surface area.

```cpp
#include <nameof.hpp>

int      x        = 42;
auto&    name     = NAMEOF(x);                      // "x"
auto     fn_name  = NAMEOF(std::sort);              // "sort"
auto     type     = NAMEOF_TYPE(std::vector<int>);  // "std::vector<int>"
auto     enum_n   = NAMEOF_ENUM(Color::Red);        // "Red" (delegates to magic_enum)
```

## References
- <https://github.com/Neargye/nameof>
