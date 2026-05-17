## References
- https://stackoverflow.com/questions/35884239/conceptual-ambiguity-between-md-mt-and-dll-lib/35884751#35884751

/MD links against the CRT import library (msvcrt/ucrt DLLs at runtime), while /MT links the CRT statically into the binary.

```bat
cl /MD /LD mylib.c   rem DLL that depends on CRT DLLs
cl /MT app.c         rem EXE with static CRT
```
