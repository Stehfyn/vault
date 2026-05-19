# utf8.h -- Single-Header UTF-8 String Lib

Neil Henning's single-header UTF-8 string library. Roughly a drop-in `<string.h>` for `char*` buffers that you've explicitly decided to treat as UTF-8 rather than as ASCII or as some legacy code page. Provides codepoint-aware analogues of the C standard library: `utf8len` (codepoints, not bytes), `utf8size` (bytes including the trailing NUL), `utf8cmp` / `utf8casecmp`, `utf8chr` / `utf8rchr`, `utf8str` / `utf8casestr`, `utf8cpy` / `utf8cat`, `utf8codepoint` (iterator), `utf8nlen` for bounded length. Public-domain (Unlicense). On Windows it's a useful complement to `MultiByteToWideChar` when you'd rather keep your in-memory strings as UTF-8 throughout (the way most modern non-Win32 codebases prefer) and only widen at the API boundary.

## References
- <https://github.com/sheredom/utf8.h>
