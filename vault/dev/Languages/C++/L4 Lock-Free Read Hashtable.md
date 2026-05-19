<!-- generated-from-dump2 -->
# L4 Lock-Free Read Hashtable

L4 stands for "Lock-Free on Read" — a fixed-size hashtable for arbitrary byte-stream keys/values, designed for many readers + one writer using an epoch-based reclamation scheme (the "Epoch Queue") so lookups never take a lock. Pairs a Clock page-replacement eviction policy with optional shared-memory layout for cross-process lookup tables. Niche but a clean reference if you ever need to roll your own lock-free read-mostly index instead of reaching for `concurrent_unordered_map`. Header lives under `inc/L4`, sample under `Examples/main.cpp` (see README).

```cpp
// Sketch: epoch-based safe read. Reader registers in the current epoch,
// performs lookup against an immutable snapshot, then leaves the epoch so
// the writer's deferred reclamation can free old buckets.
#include <L4/HashTable/Cache/HashTableService.h>
L4::EpochManagerConfig epochCfg{};
L4::CacheTableService svc{epochCfg};
auto idx   = svc.AddHashTable(L4::HashTableConfig{"myTable", L4::HashTableConfig::Setting{1000u}});
auto ctx   = svc.GetContext();        // reader joins the current epoch
auto& tbl  = ctx[idx];
L4::IReadOnlyHashTable::Value val{};
tbl.Get(L4::IReadOnlyHashTable::Key{/*data,size*/}, val); // lock-free
// ctx destruction marks epoch exit; writer reclaims when no reader remains.
```

## References
- <https://github.com/microsoft/L4>
