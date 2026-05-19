<!-- generated-from-dump2 -->
# LLVM Fork with Improved MSVC Compatibility

LLVM fork that improves Clang's drop-in compatibility with `cl.exe`/MSVC 2022: supports more MSVC pragmas, ABI quirks (SEH on x64 specifically), and intrinsics that upstream Clang either rejects or miscompiles. Popular in the reverse-engineering / obfuscation community for building Windows kernel drivers and protected user-mode code with Clang's optimizer.

```bash
# Build the fork.
git clone https://github.com/backengineering/llvm-msvc
cmake -S llvm-msvc/llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS="clang;lld" \
    -DCMAKE_BUILD_TYPE=Release
ninja -C build clang lld

# Use as a cl.exe drop-in.
clang-cl /c /O2 /GS- mydriver.c
```

## References
- <https://github.com/backengineering/llvm-msvc>
