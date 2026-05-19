<!-- generated-from-dump2 -->
# vcpkg — C and C++ Package Manager

C/C++ package manager from Microsoft. Two modes: classic (`vcpkg install <pkg>` into a shared root) and manifest mode (`vcpkg.json` per project, restored at CMake configure via the toolchain file). Triplets (`x64-windows`, `x64-windows-static`, `arm64-osx`, ...) select architecture/linkage; ports are CMake-based and live in `ports/<name>/portfile.cmake`.

```bash
# Manifest-mode workflow.
git clone https://github.com/microsoft/vcpkg && ./vcpkg/bootstrap-vcpkg.sh
cat > vcpkg.json <<'EOF'
{ "name": "app", "version": "0.1.0", "dependencies": ["fmt", "zlib"] }
EOF
cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake \
  -DVCPKG_TARGET_TRIPLET=x64-windows-static
```

## References
- <https://github.com/microsoft/vcpkg>
