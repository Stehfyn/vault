<!-- generated-from-dump2 -->
# Lambda Calculus to C Toy Compiler

Toy compiler from untyped lambda calculus to C. Educational - walks `\x.\y.x y` style input, parses, does De Bruijn conversion, and emits C functions where every closure becomes a struct + a function pointer (the standard closure-conversion technique). Good starter reading if you want to understand "how do functional languages target a C-style runtime" without wading into a real compiler.

```text
# Example transformation (paraphrased):
#   input :  (\x. (\y. x y))
#   ANF   :  let f = \x. let g = \y. x y in g in f
#   C out :
#     struct env_g { lambda* x; };
#     value g(struct env_g* e, value y) { return apply(*e->x, y); }
#     value f(struct env_f* _, value x) {
#         struct env_g* e = alloc(sizeof *e); e->x = box(x);
#         return mk_lambda(g, e);
#     }
```

## References
- <https://github.com/rybla/lcc>
