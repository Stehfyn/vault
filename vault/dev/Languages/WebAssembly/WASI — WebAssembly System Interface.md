<!-- generated-from-dump2 -->
# WASI — WebAssembly System Interface

The WebAssembly System Interface — a standardized capability-based syscall surface for WASM modules running *outside* the browser. Without WASI, a WASM module has no way to read a file, open a socket, or read the clock; with WASI, those operations are imported as ordinary WASM functions (`wasi_snapshot_preview1.fd_read`, `wasi_snapshot_preview1.clock_time_get`, etc.) that the host runtime (wasmtime, wasmer, wasmedge, NodeJS) implements with policy. Capability-based: the host explicitly grants access to specific preopened directories and inheritable descriptors, so a WASM module compiled with `--target wasm32-wasi` can't reach beyond what was passed in. WASI Preview 1 is the deployed-everywhere version; Preview 2 / WASI 0.2 (2024) introduces the Component Model and resource handles — a much richer ABI that is the long-term replacement.

```bash
# Build a Rust binary targeting WASI
rustup target add wasm32-wasi
cargo build --target wasm32-wasi --release

# Run it under wasmtime, granting read-only access to /data
wasmtime run --dir=/data target/wasm32-wasi/release/myapp.wasm

# Or C/C++ with the WASI SDK
clang --target=wasm32-wasi --sysroot=$WASI_SDK/share/wasi-sysroot main.c -o main.wasm
```

## References
- <https://github.com/WebAssembly/WASI>
