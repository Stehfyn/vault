<!-- generated-from-dump2 -->
# Modern CMake Example Projects

Numbered, intentionally-minimal CMake project samples (`01-hello`, `02-library`, `03-options`, ...) demonstrating modern usage: targets over variables, `PUBLIC`/`PRIVATE`/`INTERFACE` propagation, `target_compile_features`, `FetchContent`, presets. Better starter than reading the official tutorial because every example is a runnable directory.

```cmake
# 02-library shape: build a static lib and link it into an exe with usage requirements.
cmake_minimum_required(VERSION 3.20)
project(02-library LANGUAGES CXX)

add_library(greet STATIC src/greet.cpp)
target_include_directories(greet PUBLIC include)
target_compile_features(greet PUBLIC cxx_std_17)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE greet)
```

## References
- <https://github.com/pr0g/cmake-examples>
