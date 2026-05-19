# strsafe.h

The "safe" string-manipulation family Microsoft added to head off the parade of `strcpy` / `strcat` / `sprintf` buffer overruns that defined CVE counts in the early 2000s. Two parallel families: `StringCch*` (count-of-CHARACTERS) and `StringCb*` (count-of-BYTES) -- pick one and stick with it, mixing them inside a function is how you get off-by-one truncation bugs. Every function: (a) always null-terminates the output, even on truncation; (b) returns `STRSAFE_E_INSUFFICIENT_BUFFER` (= `HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)`) on truncation rather than returning a length; (c) does not implicitly retry -- you must size the buffer yourself or use `StringCchPrintf` with a probe call. Note that the C11 Annex K `_s` functions (`strcpy_s`, `sprintf_s`) cover similar ground but with completely different semantics (`abort_handler_s`); on Windows the strsafe family is preferred because it integrates cleanly with `HRESULT`.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/strsafe/>
- <https://learn.microsoft.com/en-us/windows/win32/menurc/strsafe-ovw>
