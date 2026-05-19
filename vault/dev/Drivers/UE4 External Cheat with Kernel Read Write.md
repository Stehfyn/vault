<!-- generated-from-dump2 -->
# UE4 External Cheat with Kernel Read Write

External UE4 cheat split into a kernel driver (memory R/W via IOCTL) and a C++ user-mode client that walks the UObject array / GNames to enumerate actors, draw ESP, and inject input. Educational example of the "manual mapper + kernel R/W" pattern still common in EAC/BE-protected titles.

```cpp
// User-mode: pull an FName string from a remote UE4 process.
template<typename T> T RPM(uintptr_t addr) {
    T v{}; ReadKernel(g_TargetPid, addr, &v, sizeof(T)); return v;
}

uintptr_t gnames = RPM<uintptr_t>(uworld + OFFSET_GNAMES);
uintptr_t chunk = RPM<uintptr_t>(gnames + (idx / 0x4000) * sizeof(void*));
uintptr_t entry = RPM<uintptr_t>(chunk + (idx % 0x4000) * sizeof(void*));
```

## References
- <https://github.com/frankelitoc/UE4-c->
