# basestd.h

SDK-internal aliasing of `<stdint.h>`-style fixed-width integer types onto Windows' own type names. Predates the C99-style `<stdint.h>` adoption by MSVC and was kept in the SDK to avoid breaking compilation when the standard header was not yet available; effectively a compat shim mapping `int8_t` / `int16_t` / `int32_t` / `int64_t` / `uint*_t` onto `__int8` / `__int16` etc. Modern code should just `#include <cstdint>` (or `<stdint.h>`) -- there's no reason to pull `basestd.h` directly into your TU. You'll usually see it transitively included by other DDK / IFS headers that were written before `<stdint.h>` was usable on all the build configurations Microsoft cared about.

## References
- basestd.h
