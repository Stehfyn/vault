# intsafe.h

Overflow-safe integer arithmetic from `kernel32` (and inlinable in headers). Family of `<srcT>To<dstT>` conversions (`UIntToULong`, `UIntPtrToULong`, `ULongLongToULong`, `Int32ToInt8`, ...) that return `S_OK` / `INTSAFE_E_ARITHMETIC_OVERFLOW` (`HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW)`), plus checked-arithmetic primitives (`UIntAdd`, `UIntSub`, `UIntMult`, `SIZETAdd`, `SizeTMult`, `ULongLongMult`). Pattern is identical to strsafe.h's: every function returns `HRESULT`, never sets `errno`, and on overflow sets the destination to a defined value (usually `*pdwResult = UINT_MAX`) so a buggy caller that ignores the return at least sees obviously-wrong output. Used throughout the Windows codebase to size allocations from external input (`COUNT * sizeof(STRUCT)` is a classic integer-overflow primitive when COUNT is attacker-controlled).

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/intsafe/>
