<!-- generated-from-dump2 -->
# librg — Game State Replication Library

ZPL's librg - small C library for "replicate game state across N clients" without writing the netcode by hand. The model is "entities with components": you flag certain components as `LIBRG_NETWORKED` and the library handles serialization, delta-compression, area-of-interest filtering (entities far from a client aren't sent), and the entity-spawn / entity-update / entity-despawn message framing. Roughly the lower-level "thing inside a multiplayer game's loop" rather than a full engine. Used in indie multiplayer games.

```c
#include "librg.h"

librg_world *world = librg_world_create();
librg_world_userdata_set(world, my_app);

// Server side: register entities + per-tick "send updates"
for (Entity* e : networked_entities) {
    librg_entity_track(world, e->id);
    librg_entity_owner_set(world, e->id, e->ownerClient);
    librg_entity_chunk_set(world, e->id, e->chunkId);    // for AoI
}
// Each tick:
char buf[4096];
size_t n = sizeof(buf);
librg_world_write(world, clientId, /*radius=*/2, buf, &n, NULL);
send_to_client(clientId, buf, n);

// Client side: librg_world_read decodes incoming buf and fires
// entity_create/update/remove callbacks you register up front.
```

## References
- <https://github.com/zpl-c/librg>
