<!-- generated-from-dump2 -->
# Tokyo Cabinet — Embedded KV Database

Mirror of Mikio Hirabayashi's **Tokyo Cabinet**, the embedded key-value/B+tree/hash database that was the LevelDB-equivalent in the mid-2000s before LevelDB existed. Five storage flavours selectable by API: hash database (`tchdb`, on-disk Robin-Hood hash), B+ tree (`tcbdb`, ordered range scans), fixed-record (`tcfdb`, array of fixed-width slots), table (`tctdb`, schemaless rows with secondary indexes), and in-memory map (`tcmap`). Successor is Kyoto Cabinet by the same author. Historically important for embedded persistence — used by mixi, by various distributed key-value gateways, and as the storage layer behind Tokyo Tyrant — but largely supplanted by LevelDB/RocksDB/LMDB in modern code. Read it for an unusually clean C API for KV with multiple disk shapes side by side.

```c
#include <tcutil.h>
#include <tchdb.h>

TCHDB* db = tchdbnew();
tchdbopen(db, "casket.tch", HDBOWRITER | HDBOCREAT);

tchdbput2(db, "foo", "hello");
tchdbput2(db, "bar", "world");

char* v = tchdbget2(db, "foo");        // "hello"
puts(v);
tcfree(v);

tchdbclose(db);
tchdbdel(db);
```

## References
- <https://github.com/hthetiot/Tokyo-Cabinet>
