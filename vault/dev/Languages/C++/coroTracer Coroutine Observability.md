<!-- generated-from-dump2 -->
# coroTracer Coroutine Observability

Observability layer for coroutine-based systems (C++20 coroutines, Go, Rust async) that records per-coroutine state transitions — created/suspended/resumed/awaited/completed — into an SPSC lock-free ring buffer in shared memory. The "cTP" protocol mentioned in the README is a wire format for those records that's shared across language bindings, so a Go program and a C++ program in the same process group can dump traces into the same consumer. Zero-copy meaning records are written in place at the boundary, no JSON serialization on the hot path. Useful when sampling profilers (perf, py-spy) can't see into the user-space scheduler that's managing the coroutines.

```cpp
// Conceptual instrumentation points (real API is in include/corotracer/*.h):
struct Tracer {
    SpscRing<TraceRecord> ring;   // mmap'd shared memory
};

// At the four lifecycle points the runtime / promise type calls:
inline void on_create(Tracer& t, uint64_t id, std::source_location loc) {
    t.ring.push({rdtsc(), id, EVENT_CREATE, loc.file_name(), loc.line()});
}
inline void on_suspend(Tracer& t, uint64_t id) {
    t.ring.push({rdtsc(), id, EVENT_SUSPEND, nullptr, 0});
}
// Consumer process maps the same shared region and drains records:
//   while (ring.try_pop(&rec)) export_to_chrome_trace(rec);
```

## References
- <https://github.com/lixiasky-back/coroTracer>
