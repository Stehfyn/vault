# Dump2 - Systems and Tools

Starred repositories related to build systems, allocators, static analysis, profiling, and low-level C/C++ tooling.

---

## microsoft/mimalloc
https://github.com/microsoft/mimalloc

Microsoft's compact general-purpose allocator (12.9k stars). Faster than the CRT heap for multi-threaded apps because it uses per-thread free lists (no lock on the fast path), segment-based arenas, and NUMA awareness. Drop-in replacement: link `mimalloc.lib` and call `mi_malloc`/`mi_free`, or override CRT `malloc`/`free` by including `mimalloc-override.h`. Key design: "deferred free" allows cross-thread frees without contention.

```cpp
// Option 1: use mimalloc directly
#include <mimalloc.h>
void* p = mi_malloc(1024);
mi_free(p);

// Option 2: override malloc/free globally (MSVC)
#include <mimalloc-override.h>  // must be first include in one .cpp file

// Option 3: replace Windows heap (mimalloc-redirect)
// Link mimalloc-redirect.lib -- intercepts HeapAlloc/HeapFree at load time

// Stats at program exit:
mi_stats_print(nullptr); // prints throughput, peak, fragmentation stats
```

---

## michaelforney/samurai
https://github.com/michaelforney/samurai

Ninja-compatible build tool written in C (1012 stars). Implements the full Ninja build protocol but in ~3000 lines of clean C. Key property: samurai (samu) is statically linkable with zero dependencies, making it easy to bundle with a project. Reads `build.ninja` exactly as Ninja would, supports deps files, phony rules, and `$in`/`$out` variable substitution.

```ninja
# build.ninja equivalent that samu processes identically to ninja
rule cc
  command = cl /c /Fo$out $in
  deps = msvc

rule link
  command = link /OUT:$out $in

build main.obj: cc main.c
build app.exe: link main.obj
```

---

## skeeto/dcmake
https://github.com/skeeto/dcmake

CMake debugger by skeeto (74 stars). Prints a step-by-step trace of CMake variable values, function calls, and include chains as CMake processes your `CMakeLists.txt`. Useful when `message(STATUS ...)` isn't enough and you need to understand why a variable is being set or unset mid-configure.

```bash
# Run dcmake instead of cmake -- same arguments
./dcmake -S . -B build

# Output shows each variable assignment with its source location:
# [cmake_minimum_required] line 1: set CMAKE_MINIMUM_REQUIRED_VERSION = 3.20
# [project] line 3: set CMAKE_PROJECT_NAME = MyApp
# [find_package] line 5: searching for OpenGL in /usr/lib ...
```

---

## NASA-SW-VnV/ikos
https://github.com/NASA-SW-VnV/ikos

NASA's IKOS static analyzer (3148 stars) -- C/C++ analysis based on Abstract Interpretation. Unlike Clang's scan-build (bug checkers), IKOS proves the absence of errors (buffer overflows, null dereferences, integer overflows) within bounded analysis parameters. Operates on LLVM IR. Output is a SQLite database of analysis results queryable by file/line.

```bash
# Run IKOS on a C file
ikos main.c -o main.db

# Query results
ikos-report main.db
# Output: main.c:42: error: buffer overflow on array access
#         index: [0, 1024], array size: 256

# The key insight: IKOS computes all possible program states
# using widening/narrowing operators on abstract domains (intervals, octagons).
# False negatives possible; false positives are not (sound analysis).
```

---

## grafana/pyroscope
https://github.com/grafana/pyroscope

Grafana's continuous profiling platform (11.4k stars). Collects CPU, memory, goroutine profiles continuously and stores them in a time-series database. For C/C++ programs use the eBPF profiler or the `spy` agent. Key differentiator vs. periodic profiling: captures rare performance regressions correlated to deployment events.

```go
// Integrate pyroscope in a Go service
import "github.com/grafana/pyroscope-go"

pyroscope.Start(pyroscope.Config{
    ApplicationName: "my-service",
    ServerAddress:   "http://pyroscope:4040",
    ProfileTypes: []pyroscope.ProfileType{
        pyroscope.ProfileCPU,
        pyroscope.ProfileInuseObjects,
        pyroscope.ProfileAllocObjects,
    },
})
```

---

## kosmonautdnb/WatcomLibs
https://github.com/kosmonautdnb/WatcomLibs

Useful C++ libraries ported to OpenWatcom, the open-source Watcom compiler. Relevant for DOS/16-bit development and understanding how libraries must be adapted when the ABI and calling convention differ significantly. Includes stb_image, miniz, and others. Demonstrates `__cdecl` vs `__pascal` annotation requirements under Watcom.

```cpp
// Watcom calling convention annotations
// __cdecl is default for most Win32 code but Watcom has its own register-based convention
#pragma aux push_button = \
    "push eax"            \
    parm [eax]            \
    modify [eax];

// Watcom register argument passing (faster than stack):
// first 4 args go in EAX, EDX, EBX, ECX by default
int __fastcall WatcomAdd(int a, int b) { return a + b; }
// Compiled as: mov eax, [EAX+EDX] style depending on optimization
```

---

## Frankie-PellesC/fSDK
https://github.com/Frankie-PellesC/fSDK

Up-to-date SDK headers for the Pelles C compiler suite. Pelles C is a freeware Windows-only C compiler with its own linker, IDE, and assembler -- useful for lightweight C development without MSVC. The fSDK extends the built-in headers with up-to-date Win32 API definitions, COM interfaces, and DirectX headers to match recent Windows SDK coverage.

```c
// Pelles C minimal Win32 program (no CRT startup overhead)
#include <windows.h>
#pragma comment(lib, "user32.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
    MessageBoxW(NULL, L"Hello from Pelles C!", L"Test", MB_OK);
    return 0;
}
// Compile: pocc /Ze /MT main.c
// Link:    polink /SUBSYSTEM:WINDOWS main.obj user32.lib
```

---

## RagnarGrootKoerkamp/quickheap
https://github.com/RagnarGrootKoerkamp/quickheap

Claims to be the fastest priority queue (SIMD, Rust). Uses SIMD instructions to compare multiple keys in parallel during push/pop, reducing the number of comparisons vs. a binary heap. The key paper insight: a 4-ary or 8-ary heap reduces tree height and improves cache locality; with SIMD you compare all children simultaneously.

```rust
// quickheap usage (Rust)
use quickheap::QuickHeap;
let mut heap = QuickHeap::<u64>::new();
heap.push(42);
heap.push(7);
heap.push(100);
let min = heap.pop(); // returns 7 (min-heap)

// Compared to BinaryHeap in std: ~2-3x faster for large heaps
// due to SIMD child comparison (AVX2 _mm256_min_epu64)
```
