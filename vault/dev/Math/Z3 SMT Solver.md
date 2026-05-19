<!-- generated-from-dump2 -->
# Z3 SMT Solver

Microsoft Research's SMT (satisfiability modulo theories) solver and the de-facto industry standard for any problem of the form "find values satisfying these constraints over ints/bitvectors/reals/arrays/strings, or prove none exist." Used as a backend by symbolic execution engines (angr, KLEE), program verifiers (Dafny, F*, Boogie), constraint-based test generators, type-system designers, and a long tail of academic tools. Has solid C/C++/Python/.NET/Java/OCaml bindings; the Python binding (`z3-solver` on PyPI) is what 90% of users actually touch. Performance varies enormously by theory and encoding — bitvector and linear arithmetic are well-tuned, nonlinear real arithmetic and strings are best-effort.

```python
from z3 import Int, Solver, sat

x, y = Int('x'), Int('y')
s = Solver()
s.add(x + y == 10, x - y == 4)
if s.check() == sat:
    m = s.model()
    print(m[x], m[y])  # 7 3
```

## References
- <https://github.com/Z3Prover/z3>
