<!-- generated-from-dump2 -->
# json.cpp — Old-School C++ JSON Library

Justine Tunney's JSON library written in deliberately old-school C++ — no exceptions, no RTTI, no `<filesystem>`, no fancy template metaprogramming, builds on the same boring compilers Cosmopolitan does. Sits opposite nlohmann/json (modern, header-only, exception-using, ergonomic but heavyweight) and RapidJSON (fast, SAX or DOM, custom allocators). The point is that you get a JSON parser/serialiser that you can drop into anything from a 90s-vintage Unix to an embedded build without bringing in a runtime library that won't link there. Strict UTF-8 handling and care about edge cases (numeric precision, surrogate pairs, NaN/Inf) is one of the things Justine consistently gets right.

```cpp
// API shape per the repo. Consult the header for exact spellings.
#include "json.h"

std::string text = R"({"name":"test","values":[1,2,3]})";
Json j = Json::parse(text);
if (j.isObject()) {
    std::string name = j["name"].getString();
    for (const Json& v : j["values"].getArray()) {
        // v.getNumber() -> 1, 2, 3
    }
}
std::string out = j.toString();  // serialise back
```

## References
- <https://github.com/jart/json.cpp>
