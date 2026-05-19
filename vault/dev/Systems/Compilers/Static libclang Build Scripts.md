<!-- generated-from-dump2 -->
# Static libclang Build Scripts

CMake project that builds `libclang` as a fully static archive (no `libLLVM*.so` runtime dep), so language servers, code-generators, and Haskell/Rust bindings can ship a single self-contained binary. Pins specific LLVM versions and turns off rarely-used subsystems (orc-jit, MLIR, fuzzers) to shrink output.

```bash
git clone --recursive https://github.com/deech/libclang-static-build
cmake -S libclang-static-build -B build -G Ninja \
    -DLLVM_VERSION=18.1.8 -DCMAKE_BUILD_TYPE=Release
ninja -C build
# Produces build/lib/libclang.a (Linux) or libclang.lib (Windows).
```

## References
- <https://github.com/deech/libclang-static-build>
