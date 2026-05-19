<!-- generated-from-dump2 -->
# GMP (MSVC Build of GNU MP)

ShiftMediaProject's repackaging of GNU MP with native MSVC project files, sidestepping the upstream's autotools-only build. Same code, same `gmp.h`, same `mpz_t`/`mpq_t`/`mpf_t` types — but you get a `.vcxproj` instead of having to drag MSYS2 or WSL into a Windows build. Useful when you're shipping a Windows app that depends on GMP transitively (FFmpeg, Nettle/GnuTLS, certain cryptographic or symbolic-math libraries) and don't want to wrestle with cross-compilation. Pair with the rest of ShiftMediaProject (FFmpeg, x264/x265, libvpx, etc.) when building media stacks on MSVC.

```cpp
#include <gmp.h>

mpz_t a, b, r;
mpz_inits(a, b, r, NULL);
mpz_set_str(a, "12345678901234567890", 10);
mpz_set_str(b, "98765432109876543210", 10);
mpz_mul(r, a, b);
gmp_printf("%Zd\n", r);  // 1219326311370217952237463801111263526900
mpz_clears(a, b, r, NULL);
```

## References
- <https://github.com/ShiftMediaProject/gmp>
