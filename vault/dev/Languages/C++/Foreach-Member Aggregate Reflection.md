<!-- generated-from-dump2 -->
# Foreach-Member Aggregate Reflection

Header-only `foreachMember(s, fn)` that walks every field of an aggregate struct at compile time and calls a generic lambda on each one. Built on the pre-C++17 "magic get" pattern: a struct that converts to anything (`struct anything { template<class T> operator T(); };`) is used together with brace-init SFINAE to count members, then the count selects a structured-binding code path. The trade-off is the long list of constraints — struct must be standard layout, aggregate, no bitfields, no custom constructors, no default-member-initializers — which is exactly the same fence Boost.PFR / `boost::pfr` ended up landing behind. Useful as a teaching artifact for how aggregate reflection worked before C++26 reflection.

```cpp
#include "foreach_member.h"

struct A { char c; std::string s; int i; };

A a{'c', "test", 42};
foreachMember(a, [](auto&& v) {
    std::cout << v << ", ";
});
// prints: c, test, 42,
```

## References
- <https://github.com/Mizuchi/ForeachMember>
