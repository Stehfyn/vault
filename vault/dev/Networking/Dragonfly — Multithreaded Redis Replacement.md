<!-- generated-from-dump2 -->
# Dragonfly — Multithreaded Redis Replacement

Drop-in Redis replacement that ditches Redis's single-threaded core for a shared-nothing multithreaded design — each core owns a shard of the keyspace, and commands targeting a key are routed to the owning thread by hashing. The non-obvious wins are: (a) commands that only touch keys in one shard run lock-free (most of them), (b) `MULTI`/transactions across shards use a custom 2-phase commit, and (c) the storage is a B+ tree (`PrimeTable` design) rather than Redis's hashtable, giving better locality and snapshot semantics — they can fork+iterate for `BGSAVE` without `COW` blowing up RAM. C++17, builds on Helio (their own io_uring-based runtime). Speaks the Redis RESP protocol so clients don't change.

```text
# Compatibility: Redis clients work unchanged.
$ redis-cli -p 6379
> SET k v
OK
> GET k
"v"

# Multi-key commands across shards are coordinated via the internal
# transactional layer; clients still see the same semantics as Redis.
> MSET a 1 b 2 c 3
OK
```

## References
- <https://github.com/dragonflydb/dragonfly>
