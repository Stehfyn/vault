## References
- https://devblogs.microsoft.com/oldnewthing/20231229-00/?p=109204

Mapping the same file mapping twice gives two virtual addresses backed by the same physical pages; writes in one view are immediately visible in the other.

```c
HANDLE hfm = CreateFileMapping(INVALID_HANDLE_VALUE, NULL,
                               PAGE_READWRITE, 0, sizeof(DWORD), NULL);
LPDWORD pdw1 = (LPDWORD)MapViewOfFile(hfm, FILE_MAP_WRITE, 0, 0, sizeof(DWORD));
LPDWORD pdw2 = (LPDWORD)MapViewOfFile(hfm, FILE_MAP_WRITE, 0, 0, sizeof(DWORD));
*pdw1 = 42; // pdw2 observes the same value
```
