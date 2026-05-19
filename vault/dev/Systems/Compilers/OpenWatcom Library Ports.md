<!-- generated-from-dump2 -->
# OpenWatcom Library Ports

Ports of common C/C++ libraries to OpenWatcom; useful for 16-bit and DOS-era ABI quirks.

```cpp
// Watcom fastcall passes args in registers for some targets.
int __fastcall WatcomAdd(int a, int b) { return a + b; }
```

## References
- <https://github.com/kosmonautdnb/WatcomLibs>
