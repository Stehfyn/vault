<!-- generated-from-dump2 -->
# Anyness Reflective Container Library

C++23 reflective-container library — generic `Any`, `Map`, `Trait`, `Block` types that are both *type-erased* (can hold any type at runtime) and *templated* (zero-cost when the contained type is known statically). Part of the larger Langulus engine project; the interesting design choice is unifying RTTI-style polymorphism with template specialization via a custom reflection layer (`RTTI::MetaData`) that every Langulus type registers into. Result: you can write code that operates uniformly on heterogeneous data (think Lua tables) and the compiler folds away the type-erasure when types are known. Heavy template machinery; deep learning curve.

```cpp
#include <Anyness/Any.hpp>
using namespace Langulus;
using namespace Langulus::Anyness;

Any storage;
storage << 42 << 3.14 << "hi"_text;     // heterogeneous push

storage.ForEach([](const auto& x) {
    std::cout << x << '\n';              // typed callback per element
});

// Or get a typed container with zero erasure:
TAny<int> ints;
ints << 1 << 2 << 3;
```

## References
- <https://github.com/Langulus/Anyness>
