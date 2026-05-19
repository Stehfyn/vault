<!-- generated-from-dump2 -->
# Boost.Hana Metaprogramming Library

C++14 metaprogramming library by Louis Dionne — the "we can finally stop using `mpl::vector` and `Boost.Fusion`" library. The key insight: instead of computing on *types* with template recursion, Hana computes on *values whose type encodes the information*, so you write near-ordinary functional code (`hana::transform`, `hana::filter`, `hana::fold_left`) that the compiler evaluates at compile time. Result: heterogeneous tuples, type-level set/map, compile-time string literals, all with comprehensible error messages instead of 800-line MPL screams. Now that C++20 has `constexpr` and parameter packs everywhere, Hana is less load-bearing — but it remains the cleanest demonstration of "metaprogramming as ordinary programming."

```cpp
#include <boost/hana.hpp>
#include <iostream>
#include <string>
namespace hana = boost::hana;
using namespace hana::literals;

struct Person {
    BOOST_HANA_DEFINE_STRUCT(Person,
        (std::string, name),
        (int,         age)
    );
};

int main() {
    Person p{"Ada", 36};

    // Print every (name, value) pair without writing reflection by hand
    hana::for_each(hana::members(p), [](auto&& m) { std::cout << m << '\n'; });

    // Compile-time tuple manipulation
    auto xs   = hana::make_tuple(1, "two", 3.0);
    auto strs = hana::filter(xs, [](auto&& x) {
        return hana::traits::is_convertible(hana::typeid_(x),
                                            hana::type_c<std::string>);
    });
}
```

## References
- <https://github.com/boostorg/hana>
