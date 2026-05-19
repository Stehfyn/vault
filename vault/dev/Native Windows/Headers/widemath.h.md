# widemath.h

SDK-internal wide-integer arithmetic helpers -- the bigger sibling of `intsafe.h`. Provides 64-bit x 64-bit -> 128-bit multiply, 128-bit / 64-bit divide, 128-bit shifts, and similar operations the OS uses for high-resolution time math (`KeQueryPerformanceCounter` scaling), file-offset arithmetic, and cryptographic primitives. The public-SDK-equivalent intrinsics most people reach for instead are `_mul128`, `_umul128`, `_div128`, and `_udiv128` from `<intrin.h>` on MSVC, or `__int128` on GCC/Clang. `widemath.h` is not typically meant for external consumption and is not part of the standard public include set.

## References
- <https://learn.microsoft.com/en-us/cpp/intrinsics/umul128>
