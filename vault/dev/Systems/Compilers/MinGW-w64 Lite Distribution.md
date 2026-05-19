<!-- generated-from-dump2 -->
# MinGW-w64 Lite Distribution

Minimal MinGW-w64 GCC distribution maintained by the Red Panda C++ IDE team. Build scripts strip down the official MinGW-w64 to fit on retro Windows (NT 4.0, 98) and produce small toolchain archives. Spiritual successor / fork in style to skeeto's `w64devkit`.

```bash
# Cross-build a tiny native MinGW toolchain (Linux host).
./build.sh --target x86_64-w64-mingw32 --variant lite
# Output: dist/mingw64-lite-15.x-x86_64.7z
```

## References
- <https://github.com/redpanda-cpp/mingw-lite>
