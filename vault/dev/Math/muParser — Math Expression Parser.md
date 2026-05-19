<!-- generated-from-dump2 -->
# muParser — Math Expression Parser

Ingo Berg's expression parser — give it a string like `sin(x)*exp(-x/10)` plus variable bindings and it builds a bytecode that you can re-evaluate cheaply in a loop. The classic use case is letting end-users type formulas into graphing/plotting/CAD apps without you writing a parser; gnuplot-clones, scientific GUIs, and ROOT-style data tools all reach for muparser or a fork. Single binary, dual-licence, no template metaprogramming weirdness, and the bytecode path is fast enough that you can re-evaluate millions of points per second for plotting.

```cpp
#include <muParser.h>
double x = 0.0;
mu::Parser p;
p.DefineVar("x", &x);
p.SetExpr("sin(x) * exp(-x/10)");
for (x = 0.0; x < 10.0; x += 0.01) {
    double y = p.Eval();  // re-uses bytecode; no re-parse
    // plot (x, y)
}
```

## References
- <https://github.com/beltoforion/muparser>
