<!-- generated-from-dump2 -->
# DDD Toolbox — Collaborative Modeling App

Web app that bundles the canonical Domain-Driven Design strategic-modeling exercises into a collaborative tool: Event Storming, Context Mapping, Domain Storytelling, Bounded Context Canvas. Real-time multi-user editing (WebSockets), exports to PNG/Markdown. Useful for distributed teams doing DDD discovery workshops; the previous norm was Miro/Mural with custom templates.

```text
# Self-host:
$ git clone https://github.com/poulainpi/ddd-toolbox
$ docker compose up
# -> visit http://localhost:3000, create a board (Event Storm / Context Map / ...)
#    and share the URL. Notes are SVG + JSON in Postgres.
```

## References
- <https://github.com/poulainpi/ddd-toolbox>
