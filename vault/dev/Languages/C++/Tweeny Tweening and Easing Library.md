<!-- generated-from-dump2 -->
# Tweeny Tweening and Easing Library

Header-only modern C++ tweening (interpolation between keyframes) library — `tween::from(0).to(100).during(1000).via(easing::quadraticIn).onStep(...)`. Tracks an arbitrary list of typed values and steps them forward based on elapsed milliseconds, calling user callbacks per step. Common shipping companion in custom-rendered apps (Dear ImGui, raylib, SDL games) where you want UI animations — sliding panels, fading icons, animated easing curves — without pulling in a whole UI framework. Supports the standard Penner easing set (`linear`, `quadraticIn/Out/InOut`, `bounceOut`, etc.) plus per-step callbacks for chaining.

```cpp
#include <tweeny.h>
auto tween = tweeny::from(0.0f, 0.0f)
    .to(800.0f, 600.0f)
    .during(1000)                       // 1 second
    .via(tweeny::easing::quadraticInOut)
    .onStep([](tweeny::tween<float,float>& t, float x, float y){
        draw_sprite(x, y);
        return false;                   // keep going
    });

while (running) {
    auto dt = frame_ms();
    tween.step((int)dt);
    if (tween.progress() >= 1.0f) break;
}
```

## References
- <https://github.com/mobius3/tweeny>
