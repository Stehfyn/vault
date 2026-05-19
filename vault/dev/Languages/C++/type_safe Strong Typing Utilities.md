<!-- generated-from-dump2 -->
# type_safe Strong Typing Utilities

Jonathan Müller's library of opt-in strong-typing utilities for C++. The headline types: `ts::integer<int32_t>` (forbids implicit conversion to/from other integers — so the classic `void foo(int width, int height); foo(h, w);` bug becomes a compile error if you use `ts::integer<int, struct Width_tag>`); `ts::boolean` (no implicit int→bool); `ts::flag_set<Enum>` (typed bitset over an enum class); `ts::optional<T>` with policy-based "what does 'nothing' look like" (so e.g. `optional<NonNullPtr<T>>` has the same layout as a raw pointer); `strong_typedef` (Boost.Strong_Typedef-equivalent). Zero runtime cost when optimized; loud compile errors when you would have implicitly converted. Recommended pairing with foonathan's other libraries (memory, lex, debug_assert).

```cpp
#include <type_safe/integer.hpp>
#include <type_safe/strong_typedef.hpp>

namespace ts = type_safe;

// Distinct strong typedefs over the same underlying int
struct Width  : ts::strong_typedef<Width,  int>, ts::strong_typedef_op::equality_comparison<Width>  {};
struct Height : ts::strong_typedef<Height, int>, ts::strong_typedef_op::equality_comparison<Height> {};

void resize(Width w, Height h);

resize(Width{640}, Height{480});      // OK
// resize(Height{480}, Width{640});   // compile error - swapped args
```

## References
- <https://github.com/foonathan/type_safe>
