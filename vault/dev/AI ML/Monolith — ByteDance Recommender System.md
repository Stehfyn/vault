<!-- generated-from-dump2 -->
# Monolith — ByteDance Recommender System

ByteDance's open-sourced production recommendation system — TensorFlow-based, designed for the kind of scale (billions of items, real-time updates) TikTok needs. Distinctive feature: *collisionless* embedding tables built on a custom hash-table op (not TF's `tf.feature_column`), and online training with per-worker parameter servers so model weights can update on hot items within minutes rather than hours.

```python
import monolith
from monolith.native_training import hash_table_ops

# Collisionless embedding: each unique sparse ID gets its own row,
# evicted by an LRU/LFU policy instead of mod-hashing into a fixed table.
emb = hash_table_ops.hash_table(
    name="user_id_emb",
    dim_size=64,
    initializer=tf.random_normal_initializer(stddev=0.01),
    eviction=monolith.EvictionPolicy.LFU,
)
embeddings = emb.lookup(user_ids)
```

## References
- <https://github.com/bytedance/monolith>
