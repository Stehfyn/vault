<!-- generated-from-dump2 -->
# emhash Flat Hash Table Family

Flat hash table family for C++ (`emhash5/6/7/8`) competing with `absl::flat_hash_map`, `robin_hood::unordered_map`, `boost::unordered_flat_map`. Different variants trade lookup vs insert vs memory: emhash5 (linear probing + control bytes), emhash7 (Robin Hood backwards-shift), emhash8 (separate chaining with intrusive list, beats Abseil on huge maps with bad hash distribution). Useful as a benchmark suite — the included `bench.cpp` runs the same workload against all major flat-map implementations and dumps a table.

```cpp
#include "hash_table7.hpp"  // emhash7

emhash7::HashMap<std::string, int> m;
m.emplace("answer", 42);
m["count"] += 1;
auto it = m.find("answer");
if (it != m.end()) std::cout << it->second << "\n"; // 42
```

## References
- <https://github.com/ktprime/emhash>
