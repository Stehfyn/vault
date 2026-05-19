<!-- generated-from-dump2 -->
# dimeta Template-Metaprogrammed Logic Simulator

Full-timing gate-level logic simulator written entirely in C++ templates — instantiating the simulator produces a circuit whose evaluation is the compiler's TMP engine. Useful as a curiosity and as a small benchmark of how far template instantiation can be pushed; not practical for real circuits beyond a few hundred gates because the template recursion blows up compile time. The non-obvious bit is the temporal encoding: each "time step" is another instantiation depth, so simulating N steps means N levels of template recursion.

```cpp
// Conceptual sketch — actual code is dense template metaprogramming.
template <bool A, bool B>            struct AND_  { static constexpr bool v = A && B; };
template <bool A, bool B>            struct OR_   { static constexpr bool v = A || B; };
template <bool A>                    struct NOT_  { static constexpr bool v = !A; };

template <bool A, bool B, bool Cin>
using FullAdderSum = AND_<NOT_<AND_<A,B>::v>::v, OR_<A,B>::v>; // sketch
// stack instantiations across "time steps" to evolve registers, etc.
```

## References
- <https://github.com/notfoundry/dimeta>
