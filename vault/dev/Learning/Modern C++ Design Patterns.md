<!-- generated-from-dump2 -->
# Modern C++ Design Patterns

34 implementations of GoF + non-GoF design patterns and C++ idioms written in modern (C++17/20) style — Singleton, Factory, Builder, Visitor, Observer, Strategy, plus C++-specific idioms like CRTP, PImpl, type erasure, tag dispatch, policy-based design, and SFINAE / `requires`. Each pattern is a small standalone CMake target with both the "classic" and the "modern C++" formulation, which is where the value sits: it explicitly contrasts the 2001-vintage "use virtual + new + reference" approach against the modern "use `std::variant` + `std::visit`" or "CRTP + concepts" approach. Read alongside Iglberger's *C++ Software Design* book.

```cpp
// Example: classical Visitor vs std::variant + std::visit
// (representative of the comparison style throughout the repo)

// Classical:
struct Visitor { virtual void visit(Circle&) = 0; virtual void visit(Square&) = 0; };
struct Shape   { virtual void accept(Visitor&) = 0; virtual ~Shape() = default; };

// Modern:
struct Circle { double r; };
struct Square { double s; };
using Shape = std::variant<Circle, Square>;

double area(const Shape& sh) {
    return std::visit([](auto&& s){
        using T = std::decay_t<decltype(s)>;
        if constexpr (std::is_same_v<T, Circle>) return 3.14159 * s.r * s.r;
        else                                      return s.s * s.s;
    }, sh);
}
```

## References
- <https://github.com/MarioGalindoQ/Modern-CPP-Design-Patterns>
