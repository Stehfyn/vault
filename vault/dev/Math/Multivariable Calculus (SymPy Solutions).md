<!-- generated-from-dump2 -->
# Multivariable Calculus (SymPy Solutions)

Worked solutions to multivariable calculus textbook problems using SymPy — partial derivatives, gradients, divergence, curl, multiple integrals (double, triple, line, surface), Lagrange multipliers, change of variables / Jacobians. Notebook-style files where each problem statement is followed by the SymPy code that solves it symbolically (so the answer is the closed form, not a numerical approximation). Useful both as a SymPy cookbook ("how do I compute the Jacobian determinant of a polar-to-cartesian transform?") and as a study aid that lets you check your own pencil-and-paper work against a CAS without paying for Mathematica.

```python
import sympy as sp

x, y, z = sp.symbols("x y z", real=True)
f = x**2 * y + sp.sin(y*z)

# Gradient
grad = sp.Matrix([sp.diff(f, v) for v in (x, y, z)])

# Hessian
H = sp.hessian(f, (x, y, z))

# Double integral over a region
r, theta = sp.symbols("r theta", positive=True)
area = sp.integrate(sp.integrate(r, (r, 0, 1)), (theta, 0, 2*sp.pi))   # pi

# Lagrange multipliers: extremize f(x,y) = xy subject to x^2 + y^2 = 1
lam = sp.symbols("lam")
g   = x**2 + y**2 - 1
L   = x*y - lam*g
sols = sp.solve([sp.diff(L, x), sp.diff(L, y), sp.diff(L, lam)],
                [x, y, lam], dict=True)
```

## References
- <https://github.com/JialinC/Multivariable-Calculus>
