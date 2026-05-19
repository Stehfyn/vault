<!-- generated-from-dump2 -->
# RisingWave — Streaming SQL Database

RisingWave - Apache-2-licensed distributed streaming database (think materialized views over Kafka, evaluated continuously, queryable via Postgres-compatible SQL). Differentiator vs Materialize: pushes state into S3-compatible object storage rather than node-local disks, so storage and compute scale independently and a node failure doesn't require state recovery. Targets the same use-cases as Flink + KSQL but with one SQL surface and a relational state model.

```sql
-- Conceptual: declare a source, then a streaming materialized view.
CREATE SOURCE clicks (user_id INT, ts TIMESTAMP) WITH (
    connector = 'kafka', topic = 'clicks', properties.bootstrap.server = '...'
) FORMAT PLAIN ENCODE JSON;

CREATE MATERIALIZED VIEW clicks_per_min AS
SELECT user_id,
       window_start,
       count(*) AS clicks
FROM TUMBLE(clicks, ts, INTERVAL '1' MINUTE)
GROUP BY user_id, window_start;

-- Query from any Postgres client - RW is wire-protocol compatible.
SELECT * FROM clicks_per_min WHERE user_id = 42;
```

## References
- <https://github.com/risingwavelabs/risingwave>
