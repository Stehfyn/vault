# intsafe.h

Overflow-safe integer arithmetic from `kernel32` (and inlinable in headers). Family of `<srcT>To<dstT>` conversions (`UIntToULong`, `UIntPtrToULong`, `ULongLongToULong`, `Int32ToInt8`, ...) that return `S_OK` / `INTSAFE_E_ARITHMETIC_OVERFLOW` (`HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW)`), plus checked-arithmetic primitives (`UIntAdd`, `UIntSub`, `UIntMult`, `SIZETAdd`, `SizeTMult`, `ULongLongMult`). Pattern is identical to strsafe.h's: every function returns `HRESULT`, never sets `errno`, and on overflow sets the destination to a defined value (usually `*pdwResult = UINT_MAX`) so a buggy caller that ignores the return at least sees obviously-wrong output. Used throughout the Windows codebase to size allocations from external input (`COUNT * sizeof(STRUCT)` is a classic integer-overflow primitive when COUNT is attacker-controlled).

## Source Code Reading

`intsafe.h` is most valuable directly before allocation and pointer arithmetic.

```c
SIZE_T bytes = 0;
HRESULT hr = SizeTMult(count, sizeof(MY_RECORD), &bytes);
if (FAILED(hr)) return HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW);

MY_RECORD* p = (MY_RECORD*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, bytes);
```

The code pattern is "compute checked size, then allocate." Do not allocate first and check later; by then the overflow has already selected the wrong allocation size.

Claim -> source/probe -> interpretation:
- Claim: "64-bit `size_t` makes overflow irrelevant."
- Probe: set `count = SIZE_MAX / sizeof(MY_RECORD) + 1`, run raw multiplication and `SizeTMult`.
- Interpretation: 64-bit increases range; it does not remove wraparound. The checked helper makes overflow an error path.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/intsafe/>
