<!-- generated-from-dump2 -->
# LiquidFun — 2D Fluid Physics (Box2D Fork)

Google's 2D physics engine — a Box2D fork (Erin Catto's API kept) with an added **particle system** for fluid, soft body, and elastic simulation, all driven by the same constraint solver. The particle dynamics aren't proper SPH; they're a fast approximation using discrete particle-particle constraints in the existing Box2D world, so you get plausible liquid behaviour at game frame rates instead of physically-accurate simulation. Used in Google Maps Driving Mode (the rain), Sketcher, and various educational tools. Unmaintained since ~2017 — the technique is still worth reading even though more modern alternatives (PhysX FleX, Splishsplash) exist.

```cpp
#include "Box2D/Box2D.h"

b2World world(b2Vec2(0.0f, -10.0f));

// Add a particle system attached to the world.
b2ParticleSystemDef psDef;
psDef.radius = 0.035f;
b2ParticleSystem* ps = world.CreateParticleSystem(&psDef);

// Emit a "water box": ~thousands of particles in a region.
b2PolygonShape shape;
shape.SetAsBox(2.0f, 2.0f, b2Vec2(0, 4), 0);
b2ParticleGroupDef groupDef;
groupDef.shape = &shape;
groupDef.flags = b2_waterParticle;
ps->CreateParticleGroup(groupDef);

for (int i = 0; i < 60; ++i) world.Step(1.0f / 60.0f, 8, 3);
```

## References
- <https://github.com/google/liquidfun>
