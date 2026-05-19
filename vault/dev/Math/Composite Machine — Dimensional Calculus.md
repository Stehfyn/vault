<!-- generated-from-dump2 -->
# Composite Machine — Dimensional Calculus

"Automatic Calculus via Dimensional Arithmetic" - a small library / paper exploring whether physical dimensions can be encoded as a vector space so that differential/integral operations follow from arithmetic in that space. The point is that if `[velocity] = [length][time]^-1`, then differentiating w.r.t. time is "subtract 1 from the time exponent" - leverage this to mechanize unit-aware calculus without symbolic algebra. Niche; useful as inspiration if you're building a dimension-aware tensor library.

```text
# Concept: encode dimension as a tuple (L, M, T, ...).
#   distance: (1, 0, 0)
#   time:     (0, 0, 1)
#   velocity: distance - time = (1, 0, -1)
# Differentiation w.r.t. time:  dim(d/dt x) = dim(x) - (0,0,1)
# Implementation walks expressions, adjusts dimension tuples, and emits
# the right units on the result without ever doing symbolic algebra.
```

## References
- <https://github.com/tmilovan/composite-machine>
