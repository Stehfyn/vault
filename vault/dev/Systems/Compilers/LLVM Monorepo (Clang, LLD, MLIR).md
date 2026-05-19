<!-- generated-from-dump2 -->
# LLVM Monorepo (Clang, LLD, MLIR)

The LLVM monorepo: Clang, LLD, LLDB, libc++/libc++abi, compiler-rt, libc, MLIR, BOLT, Polly, OpenMP, Flang. Single source of truth since the 2019 monorepo migration; release/X.x branches every six months. Almost every other entry in this directory is a fork, plugin, or downstream consumer.

```bash
# Bootstrap a release Clang + LLD on the host toolchain.
git clone --depth 1 https://github.com/llvm/llvm-project
cmake -S llvm-project/llvm -B build -G Ninja \
    -DLLVM_ENABLE_PROJECTS="clang;lld;clang-tools-extra" \
    -DLLVM_ENABLE_RUNTIMES="compiler-rt;libcxx;libcxxabi" \
    -DCMAKE_BUILD_TYPE=Release
ninja -C build install
```

## References
- <https://github.com/llvm/llvm-project>
