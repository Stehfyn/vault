<!-- generated-from-dump2 -->
# Twofloat — Double-Double Arithmetic

C++ implementation of **double-double** arithmetic — represent a high-precision number as a sum of two ordinary `double`s `(hi, lo)` where `|lo| <= 0.5 * ulp(hi)`. Effective precision is ~106 bits (about 32 decimal digits) but the cost per add/mul is ~10-20 cycles, not the ~1000+ of a software bignum, because every primitive uses only IEEE-754 hardware doubles with the Dekker/Knuth "error-free transformation" tricks (TwoSum/TwoProd). The interesting thing about *this* particular lib (TU Darmstadt) is that it implements the *recent* relative-error-tight algorithms from Joldes/Muller/Popescu (2017) rather than the older QD library's variants — tighter bounds, vectorizable. Useful for stable accumulation of long sums, sensitivity analysis, and as a stepping stone before going to MPFR.

```cpp
#include <twofloat/twofloat.h>
using namespace twofloat;

two<double> a = 1.0;
two<double> b = 1e-20;

two<double> c = a + b;     // hi=1.0, lo≈1e-20 -- both bits retained
// In plain double, 1.0 + 1e-20 == 1.0 (catastrophic cancellation in any sum that uses c).

double approx = c.hi + c.lo;  // collapse to double when done.
```

## References
- <https://github.com/esa-tu-darmstadt/twofloat>
