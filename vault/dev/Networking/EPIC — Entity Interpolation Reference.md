<!-- generated-from-dump2 -->
# EPIC — Entity Interpolation Reference

Jon Watte's reference C++ implementation of **client-side entity interpolation** — the netcode pattern in Quake/Source-engine multiplayer where remote entities are shown 100-150 ms in the past so the renderer can smoothly interpolate between received snapshots rather than guessing where they are now (extrapolation jitters and rubber-bands when the network delivers out-of-order). The actually clever bit, well explained here, is the interaction with **client-side prediction** for your own player: local controls are predicted forward in real time, *remote* entities are interpolated backward in the past, and the renderer composites both — so you feel responsive while seeing a coherent (slightly old) view of everyone else. Read alongside Valve's "Source Multiplayer Networking" article; the EPIC code is the smallest standalone implementation worth studying.

```cpp
// Conceptual interpolation buffer (the EPIC pattern in ~30 lines):
struct Snapshot { double t; Vec3 pos; Quat rot; };

void recv(Snapshot s) {
    history.push_back(s);                          // ordered by t
    while (history.size() > MAX_HIST) history.pop_front();
}

void render(double now) {
    double t = now - INTERP_DELAY;                 // 100ms behind wall clock
    auto it = std::find_if(history.begin(), history.end(),
                           [&](const Snapshot& s){ return s.t >= t; });
    if (it == history.end()) return;
    auto next = *it;
    auto prev = (it == history.begin()) ? next : *(it - 1);
    double alpha = (t - prev.t) / std::max(1e-6, next.t - prev.t);
    Vec3 pos = lerp(prev.pos, next.pos, alpha);    // interpolate, never extrapolate
    Quat rot = slerp(prev.rot, next.rot, alpha);
    draw(pos, rot);
}
```

## References
- <https://github.com/jwatte/EPIC>
