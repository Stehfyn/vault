<!-- generated-from-dump2 -->
# CMake Multi-Target Project Skeleton

Skeleton repo demonstrating a multi-target CMake layout: a shared library, an executable that links it, a GoogleTest harness, and Boost-flavored conventions. Pre-wired Bash bootstrap (`./bin/build`) and out-of-source `build/` discipline; clone-and-rename starting point rather than a generator.

```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloWorld VERSION 1.0.0 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/release-1.12.1.zip)
FetchContent_MakeAvailable(googletest)

add_subdirectory(lib)
add_subdirectory(bin)
enable_testing()
add_subdirectory(test)
```

## References
- <https://github.com/kigster/cmake-project-template>
