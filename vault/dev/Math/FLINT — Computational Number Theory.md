<!-- generated-from-dump2 -->
# FLINT — Computational Number Theory

C library for fast computational number theory — what GMP is to bignum arithmetic, FLINT is one level up: polynomials over ZZ, QQ, ZZ/nZZ, p-adics; matrices over those; factorization, linear algebra, lattice reduction (LLL), elliptic curves. The notable engineering bit is that all the arithmetic routines have asymptotic crossover heuristics baked in — small multiplications use schoolbook, mediums use Karatsuba, large jumps to FFT (Schoenhage-Strassen via their `fmpz` representation that switches between native long and mpz under the hood). FLINT is the backbone of Arb (interval arithmetic) and got rolled into SageMath. Use it when GMP is too low-level (you want polynomials, not just integers) and Sage/Pari is too heavy.

```c
#include <flint/fmpz_poly.h>

fmpz_poly_t a, b, c;
fmpz_poly_init(a);
fmpz_poly_init(b);
fmpz_poly_init(c);

// a = x^2 + 1
fmpz_poly_set_str(a, "3  1 0 1");   // length=3, coeffs lowest-first
// b = x + 5
fmpz_poly_set_str(b, "2  5 1");

fmpz_poly_mul(c, a, b);             // c = (x^2+1)(x+5) = x^3 + 5x^2 + x + 5

char* s = fmpz_poly_get_str_pretty(c, "x");
puts(s);                            // x^3+5*x^2+x+5

flint_free(s);
fmpz_poly_clear(a);
fmpz_poly_clear(b);
fmpz_poly_clear(c);
```

## References
- <https://github.com/flintlib/flint>
