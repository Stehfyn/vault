# stralign.h

Misaligned-wide-string helpers from the Alpha / IA64 era. On Alpha AXP and IA64 (Itanium), unaligned `WCHAR` accesses either trapped to a kernel emulation handler (catastrophically slow) or generated wrong results outright, so the SDK provides `ua_wcscpy`, `ua_wcslen`, `ua_wcscmp`, `WSTR_ALIGNED_STACK_COPY` and macros like `UALIGN_INC`/`UALIGN_DEC` that copy to a properly-aligned stack buffer before operating. On x86 / x64 / ARM64 -- every Windows architecture still shipping -- unaligned WCHAR reads are perfectly fine, so these collapse to plain `wcscpy` etc. via macros. Practically dead surface; you only encounter it if you maintain code that still compiles for IA64.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/stralign/>
