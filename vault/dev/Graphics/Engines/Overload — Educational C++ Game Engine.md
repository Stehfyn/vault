<!-- generated-from-dump2 -->
# Overload — Educational C++ Game Engine

Educational C++ game engine with editor — split into static libraries (`OvCore`, `OvRendering`, `OvUI`, `OvAudio`, `OvPhysics`, `OvWindowing`, `OvEditor`) so you can study each subsystem independently. ECS-flavored scene model, Bullet physics, irrKlang audio, GLFW + ImGui editor, custom OpenGL renderer. Use it as a *reading* engine — the layering is unusually clean for hobby-scale engines.

```cpp
// Entry point: bootstrap the editor and run.
int main() {
    OvEditor::Core::Application app("Project");
    while (app.IsRunning()) app.Update();
    return 0;
}

// Adding a component in script-style ECS:
auto& actor = scene.CreateActor("Cube");
auto& xform = actor.AddComponent<OvCore::ECS::Components::CTransform>();
auto& mesh  = actor.AddComponent<OvCore::ECS::Components::CModelRenderer>();
mesh.SetModel(modelLibrary.Get("/Models/cube.obj"));
```

## References
- <https://github.com/Overload-Technologies/Overload>
