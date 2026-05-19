<!-- generated-from-dump2 -->
# ExprTk Math Expression Parser

Single-header C++ math expression parser, compiler, and evaluator — feed it `"a*sin(b) + sqrt(c) > 0.5"` plus a binding for `a`, `b`, `c`, get a compiled expression you can re-evaluate cheaply in a loop with new variable values. Supports user functions, vectors, control flow (`if/else`, `while`, `for`), strings, and ternary, which puts it well past "expression evaluator" and into "tiny embedded scripting language for numeric configs". The standard pick for "I want users to type a formula into my CAD/simulation/spreadsheet app and have it run fast" without embedding Lua or Python.

```cpp
#include <exprtk.hpp>

typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>   expression_t;
typedef exprtk::parser<double>       parser_t;

double x = 0, y = 0;
symbol_table_t syms;
syms.add_variable("x", x);
syms.add_variable("y", y);
syms.add_constants();

expression_t expr;
expr.register_symbol_table(syms);
parser_t().compile("x*sin(y) + sqrt(abs(x))", expr);

for (x = 0; x < 10; ++x) { y = x * 0.1; std::cout << expr.value() << '\n'; }
```

## References
- <https://github.com/ArashPartow/exprtk>
