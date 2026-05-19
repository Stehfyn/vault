<!-- generated-from-dump2 -->
# qlibs reflect — Minimal Static Reflection

Tiny (sub-1000-LOC) C++20 static reflection library by Kris Jusiak. Reflects aggregate types without `BOOST_HANA_DEFINE_STRUCT` or `REFL_AUTO` macro decoration — uses the structured-binding + parameter-pack tricks that became viable at C++17/20 to discover member count and (with the help of a tiny `__PRETTY_FUNCTION__` parse) member names. Aimed at being the smallest library that lets you write `reflect::for_each([](auto name, auto& field){ ... }, my_struct)` without giving up the right to compile in two seconds. Future-facing: meant to map cleanly onto P2996 / "Reflection for C++26" when it lands.

```cpp
#include <reflect>

struct Foo { int a; double b; const char* c; };
Foo foo{1, 2.5, "hi"};

reflect::for_each([&](auto I){
    std::cout << reflect::member_name<I>(foo)
              << " = " << reflect::get<I>(foo) << '\n';
}, foo);

// also: reflect::size<Foo> == 3
// also: reflect::type_name<Foo>() == "Foo"
```

## References
- <https://github.com/qlibs/reflect>
