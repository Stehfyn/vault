# strsafe.h

The "safe" string-manipulation family Microsoft added to head off the parade of `strcpy` / `strcat` / `sprintf` buffer overruns that defined CVE counts in the early 2000s. Two parallel families: `StringCch*` (count-of-CHARACTERS) and `StringCb*` (count-of-BYTES) -- pick one and stick with it, mixing them inside a function is how you get off-by-one truncation bugs. Every function: (a) always null-terminates the output, even on truncation; (b) returns `STRSAFE_E_INSUFFICIENT_BUFFER` (= `HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)`) on truncation rather than returning a length; (c) does not implicitly retry -- you must size the buffer yourself or use `StringCchPrintf` with a probe call. Note that the C11 Annex K `_s` functions (`strcpy_s`, `sprintf_s`) cover similar ground but with completely different semantics (`abort_handler_s`); on Windows the strsafe family is preferred because it integrates cleanly with `HRESULT`.

## Source Code Reading

The header's code contribution is not just bounds checking; it makes the unit explicit in the function name.

```c
WCHAR path[MAX_PATH];
HRESULT hr = StringCchPrintfW(path, ARRAYSIZE(path),
                              L"%ls\\%ls", dir, file);
if (hr == STRSAFE_E_INSUFFICIENT_BUFFER) {
    // truncated but null-terminated; decide whether truncation is acceptable
}
```

Use `StringCch*` when the size variable is a character count and `StringCb*` when the size variable is bytes. Code review should reject wrappers that accept `sizeof(buffer)` and then call `StringCch*`; that is the classic "safe API, unsafe unit" bug.

Claim -> source/probe -> interpretation:
- Claim: "`strsafe.h` prevents string bugs."
- Probe: compile a harness that passes `sizeof(wchar_buffer)` to `StringCchCopyW` and a second harness that passes `ARRAYSIZE(wchar_buffer)`.
- Interpretation: the API helps only when the caller supplies the correct unit and checks `HRESULT`.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/strsafe/>
- <https://learn.microsoft.com/en-us/windows/win32/menurc/strsafe-ovw>
