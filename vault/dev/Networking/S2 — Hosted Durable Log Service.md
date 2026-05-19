<!-- generated-from-dump2 -->
# S2 — Hosted Durable Log Service

S2 - "Streams 2" - a hosted durable log / streaming API designed as a "Kafka but billed per byte" service from the S2.dev team. The repo contains client SDKs and protocol definitions. Differentiator vs Kafka/Pulsar: schema is fixed at "ordered byte stream of records," consumer state (per-consumer offsets) is server-side, and producers append directly over an HTTP-style API (no broker connection pool). Targets serverless and edge workloads where the operational cost of running Kafka is prohibitive.

```text
# Conceptual usage via the s2 CLI:
$ s2 stream create my-events
$ s2 append my-events --record 'click {"user":1,"item":42}'
$ s2 read my-events --from-start --follow
# server keeps offsets per consumer-group; client just resumes by group name.
```

## References
- <https://github.com/s2-streamstore/s2>
