## References
- https://www.reddit.com/r/cpp/comments/1f561x3/honey_i_shrunk_fmt_bringing_binary_size_to_14k/

Favor size-optimization and link-time optimization so unused functions and duplicate sections are removed.

```bat
cl /Os /GL /Gy /Gw main.c
link /LTCG /OPT:REF /OPT:ICF /DEBUG:NONE
```

https://downloads.ctfassets.net/9pcn2syx7zns/1WZnLuQfJlIcjRR8GeJRM2/857dc5743f68461a7e0e39a5faabfd87/c-run-time-reference.pdf
C runtime reference PDF covering all CRT functions, their signatures, and startup behaviors. Key for understanding which functions pull in the full CRT vs. which are intrinsics.
```cpp
// Safe string functions that are CRT-light (compiler intrinsics in practice)
// memcpy, memset, memcmp are often intrinsic - zero CRT overhead
// strncpy_s, wcsncpy_s require CRT; replace with manual loops in no-CRT builds
static void* SafeCopy(void* dst, const void* src, size_t n) {
    __movsb((unsigned char*)dst, (const unsigned char*)src, n);
    return dst;
}
```
