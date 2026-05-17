## References
- https://learn.microsoft.com/en-us/windows/win32/devnotes/baseflushappcompatcache

BaseFlushAppcompatCache flushes the application compatibility cache (admin required), so it’s typically resolved dynamically.

```c
HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
auto BaseFlushAppcompatCache =
    reinterpret_cast<BOOL (WINAPI*)(void)>(GetProcAddress(ntdll, "BaseFlushAppcompatCache"));
// Requires admin
if (BaseFlushAppcompatCache) {
    BaseFlushAppcompatCache();
}
```
