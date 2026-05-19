<!-- generated-from-dump2 -->
# Hazel — TheCherno's Pedagogical Engine

Yan Chernikov's pedagogical game engine — the codebase that backs his YouTube "Game Engine" series. Layered architecture (application -> layer stack -> ImGui layer + scene layer), event bus, ECS-style scene graph (via `entt`), abstracted renderer with OpenGL/D3D backends, runtime/editor split. Reference value is the *evolution* visible across the series, not any single technique. The "Hazel-dev" private fork is the more advanced version; the public repo is frozen at an earlier snapshot.

```cpp
class Sandbox : public Hazel::Application {
public:
    Sandbox() { PushLayer(new ExampleLayer()); }
};
Hazel::Application* Hazel::CreateApplication() { return new Sandbox(); }
```

## References
- <https://github.com/TheCherno/Hazel>
