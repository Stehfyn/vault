<!-- generated-from-dump2 -->
# BinGCD — Fast Modular Inversion

Thomas Pornin's optimized Binary GCD for modular inversion - drop-in replacement for the modular inversion step in elliptic curve cryptography (and any other place you compute `a^-1 mod p`). The technique is the "approximate divsteps" variant by Bernstein-Yang, generalized; on Curve25519-class primes it runs in constant-time and is 2-3x faster than the classic extended Euclidean algorithm. Reference code is meant to be copy-pasted into crypto libraries; reading it is the fastest way to grok the divsteps algorithm.

```c
// API surface (paraphrased - see header for exact types):
//   void bingcd_mod_inv(uint64_t *out, const uint64_t *a, const uint64_t *p);
//
// Internally:
//   1. Represent (u, v) as (a, p), (f, g) as (1, 0).
//   2. Repeat for ~k iterations:
//        compute approximation (~62 bits) of u, v
//        run "divsteps62" on the approximation -> (P00,P01,P10,P11) matrix
//        update (u, v, f, g) <- P * (u, v, f, g) with full-width arithmetic
//   3. After enough iters, f holds a * gcd(a,p)^-1 mod p == a^-1 (gcd=1)
```

## References
- <https://github.com/pornin/bingcd>
