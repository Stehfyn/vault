<!-- generated-from-dump2 -->
# Box2D — 2D Rigid Body Physics

The reference open-source 2D rigid-body physics engine, Erin Catto, ~20 years and counting. The lasting technical contributions (worth reading even if you never use it): the **sequential impulse** solver (constraint stabilization by warm-started impulse iteration instead of LCP), the **continuous collision detection** (CCD) for fast-moving bodies via time-of-impact, and the **island-based solver** that splits the simulation into disjoint constraint subgraphs to solve in parallel. The v3 branch is a major rewrite into a data-oriented C99 API (was C++); `b2World*` is replaced by handles and the simulation pieces are SIMD-vectorized. Catto's GDC slides each year on Box2D's internals are essentially the reference for game physics architecture.

```c
#include "box2d/box2d.h"

b2WorldDef worldDef = b2DefaultWorldDef();
worldDef.gravity = (b2Vec2){0.0f, -10.0f};
b2WorldId world = b2CreateWorld(&worldDef);

// Static ground
b2BodyDef ground = b2DefaultBodyDef();
ground.position = (b2Vec2){0.0f, -10.0f};
b2BodyId gid = b2CreateBody(world, &ground);
b2Polygon box = b2MakeBox(50.0f, 10.0f);
b2ShapeDef shape = b2DefaultShapeDef();
b2CreatePolygonShape(gid, &shape, &box);

// Dynamic box
b2BodyDef dyn = b2DefaultBodyDef();
dyn.type = b2_dynamicBody;
dyn.position = (b2Vec2){0.0f, 4.0f};
b2BodyId did = b2CreateBody(world, &dyn);
b2Polygon dbox = b2MakeBox(1.0f, 1.0f);
b2CreatePolygonShape(did, &shape, &dbox);

for (int i = 0; i < 60; i++)
    b2World_Step(world, /*dt=*/1.0f / 60.0f, /*subSteps=*/4);
```

## References
- <https://github.com/erincatto/box2d>
