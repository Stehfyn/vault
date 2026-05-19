<!-- generated-from-dump2 -->
# Graphiti — Bitemporal Agent Knowledge Graph

Python framework for building bitemporal knowledge graphs that an LLM agent can maintain over time as it observes new facts. The non-obvious design choices vs. naive vector-DB RAG: (1) **bitemporal** — every edge stores both the time it was *valid in the world* and the time it was *recorded in the graph*, so you can ask "what did the agent believe about X on Tuesday?" or "what was true about X on Tuesday regardless of when we learned it"; (2) hybrid retrieval — semantic embedding *plus* graph traversal *plus* BM25 keyword, instead of dumping a single similarity-top-k blob into context; (3) updates are *incremental* — new facts get reconciled against the existing graph rather than re-indexing from scratch. Built on Neo4j as the storage backend with the same team's Zep memory product behind it.

```python
from graphiti_core import Graphiti
from datetime import datetime

g = Graphiti(neo4j_uri="bolt://localhost:7687",
             neo4j_user="neo4j", neo4j_password="...")

await g.build_indices_and_constraints()

# Add an "episode" — a natural-language chunk plus a reference time
await g.add_episode(
    name="meeting_2026_05_17",
    episode_body="Alice joined the platform team. She'll work with Bob on the storage migration.",
    source_description="meeting notes",
    reference_time=datetime(2026, 5, 17),
)

# Query: hybrid (semantic + graph + BM25)
results = await g.search("Who works on storage?", num_results=10)
```

## References
- <https://github.com/getzep/graphiti>
