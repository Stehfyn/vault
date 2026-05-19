<!-- generated-from-dump2 -->
# Rust Cross-Toolchain Docker Images

Set of pre-built Docker images carrying a Rust toolchain plus the C/C++ sysroot + linker needed to cross-compile from x86_64 Linux to every common embedded / mobile target — aarch64, riscv32/64, mips, powerpc, wasm, Android NDK, etc. Underpins `taiki-e/upload-rust-binary-action` and `taiki-e/install-action`, two of the most-used GitHub Actions in the Rust release-engineering world. Differentiator vs `cross-rs/cross`: cross also ships images but for fewer targets and with older sysroots; taiki-e's images track stable Rust closely and include newer LLVM/clang versions, which matters for `linux-musl` and `*-none-eabi` targets that have historically rotted.

```bash
# Build a Rust binary for aarch64-musl entirely inside the image
docker run --rm -v $PWD:/work -w /work \
    ghcr.io/taiki-e/rust-cross-toolchain:aarch64-unknown-linux-musl \
    cargo build --release --target aarch64-unknown-linux-musl

# In CI (GitHub Actions), taiki-e/setup-cross-toolchain-action wraps this
# - uses: taiki-e/setup-cross-toolchain-action@v1
#   with:
#     target: aarch64-unknown-linux-musl
```

## References
- <https://github.com/taiki-e/rust-cross-toolchain>
