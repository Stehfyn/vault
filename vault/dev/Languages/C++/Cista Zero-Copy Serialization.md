<!-- generated-from-dump2 -->
# Cista Zero-Copy Serialization

Zero-copy serialization library for C++17 — mmap the file, cast the bytes to your struct, you're done. Two flavours: **raw** layout (faster but architecture-dependent: must match the layout you wrote with) and **offset** layout (uses `offset_ptr<T>` instead of raw pointers, so pointers survive memory remap to any base address). Provides drop-in replacements for the STL containers that store offsets instead of pointers: `cista::vector`, `cista::string`, `cista::hash_map`, all binary-stable. Uses the type-loophole reflection trick to walk fields automatically, so you don't write schemas. The killer use case is huge read-mostly data structures (the author wrote it for the German rail timetable engine MOTIS) where parsing JSON or protobuf for every cold start is unacceptable.

```cpp
#include <cista.h>
namespace data = cista::offset;   // pointer-relocatable layout

struct Edge {
    data::string name;
    int weight;
};
struct Graph {
    data::vector<Edge> edges;
};

Graph g;
g.edges.emplace_back(Edge{data::string{"AB"}, 5});

// Write whole structure to a file.
cista::buf<std::vector<uint8_t>> buf;
cista::serialize<cista::mode::WITH_VERSION | cista::mode::DEEP_CHECK>(buf, g);
// Later, in another run:
auto* loaded = cista::deserialize<Graph>(mapped_file_bytes);  // no parse, no copy
std::cout << loaded->edges[0].name.view();   // "AB"
```

## References
- <https://github.com/felixguendling/cista>
