<!-- generated-from-dump2 -->
# cheap HTML Element Generator

Tiny C++ HTML element generator — `cheap::div { cheap::p{"hi"}, cheap::span{"there"} }`. Uses C++20 designated initialization and aggregate-init `std::initializer_list` to give you a DSL that writes HTML by composing values, no string concatenation. The output is generated at compile time when used with `consteval` so static pages cost nothing at runtime.

```cpp
#include "cheap.h"
using namespace cheap;

auto page = html{
  head{ title{"hi"} },
  body{ div{ {{"class","wrap"}}, p{"hello"}, a{ {{"href","/"}}, "home" } } }
};
std::cout << page.get_string();
// <html><head><title>hi</title></head><body><div class="wrap">
//   <p>hello</p><a href="/">home</a></div></body></html>
```

## References
- <https://github.com/s9w/cheap>
