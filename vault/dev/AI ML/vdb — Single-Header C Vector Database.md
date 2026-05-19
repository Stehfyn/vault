<!-- generated-from-dump2 -->
# vdb — Single-Header C Vector Database

Single-header C vector database — flat brute-force scan over an in-memory float array, but with the niceties you actually want for embedding hacking: multiple distance metrics (cosine/L2/dot), save/load to disk, a `vdb_set_multithreaded` flag that fans the scan across pthreads, and a custom-allocator hook. No ANN index (no HNSW/IVF), so search is O(N*d) per query — fine for tens of thousands of vectors, painful at millions. Read for the API ergonomics and the trick of keeping everything header-only without dragging in BLAS.

```c
#include "vdb.h"

int main(void) {
    vdb_database *db = vdb_create(/*dim=*/128, VDB_METRIC_COSINE);
    vdb_set_multithreaded(db, 1);

    float embedding[128] = { /* ... */ };
    vdb_add_vector(db, embedding, "vec1", /*metadata=*/NULL);

    float query[128] = { /* ... */ };
    vdb_result_set *r = vdb_search(db, query, /*top_k=*/5);
    for (size_t i = 0; i < r->count; i++)
        printf("%s  d=%f\n", r->items[i].id, r->items[i].distance);

    vdb_free_result_set(r);
    vdb_destroy(db);
}
```

## References
- <https://github.com/abdimoallim/vdb>
