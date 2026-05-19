<!-- generated-from-dump2 -->
# flecs — Archetype ECS (C99)

Archetype-based ECS in C99 (with C++ wrapper) — entities are sparse-set IDs, components are stored in tightly packed column arrays grouped by archetype (the set of component types an entity has), and systems iterate over matching archetypes. Notable for relationships (e.g. `ChildOf`, `IsA`), prefabs, queries as first-class entities, and a built-in REST/web inspector. Mature, used in shipping games.

```c
ecs_world_t* w = ecs_init();
ECS_COMPONENT(w, Position);
ECS_COMPONENT(w, Velocity);

ecs_entity_t e = ecs_new_id(w);
ecs_set(w, e, Position, {0, 0});
ecs_set(w, e, Velocity, {1, 2});

ECS_SYSTEM(w, Move, EcsOnUpdate, Position, Velocity);
void Move(ecs_iter_t* it) {
    Position* p = ecs_field(it, Position, 0);
    Velocity* v = ecs_field(it, Velocity, 1);
    for (int i = 0; i < it->count; i++) { p[i].x += v[i].x; p[i].y += v[i].y; }
}
ecs_progress(w, 0);
```

## References
- <https://github.com/SanderMertens/flecs>
