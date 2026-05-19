<!-- generated-from-dump2 -->
# cmake-init — CMake Project Scaffolder

Opinionated Python CLI that scaffolds a new CMake project with sane defaults: presets, install/export, packaging, CI yamls, vcpkg/Conan integration, tests via Catch2/GoogleTest, dev mode vs consumer mode separation. Closer to a `cargo new` experience than the bare `cmake -P` template land.

```bash
pip install cmake-init
cmake-init my-app          # interactive prompts: exe vs lib, license, std, pkg manager
cd my-app && cmake --preset=dev && cmake --build --preset=dev
```

## References
- <https://github.com/friendlyanon/cmake-init>
