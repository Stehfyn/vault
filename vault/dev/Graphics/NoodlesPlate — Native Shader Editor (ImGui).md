<!-- generated-from-dump2 -->
# NoodlesPlate — Native Shader Editor (ImGui)

Native offline shader editor in C++/ImGui aimed at the Shadertoy/demoscene workflow but with features Shadertoy refuses to ship: multi-buffer ping-pong with arbitrary topologies (not just BufferA -> D), compute shaders, geometry buffers, mesh/instance/transform inputs, MIDI control surface bindings as shader uniforms, video/image/sound texture inputs, and offline 4K/8K render-to-EXR. Built by the same author as ImGuiFileDialog and ImCoolBar — code organization is a useful reference for an ImGui-only editor app. Reads/writes its own `.npl` project file and can import Shadertoy URLs via the JSON API.

```cpp
// Conceptual pipeline (project structure, not the literal API):
// 1. ShaderPass owns a GLSL program + N input bindings + output FBO.
// 2. The graph is just a topologically-sorted vector<ShaderPass*>.
// 3. Per frame: bind FBO, set uniforms (iTime, iResolution, iMouse, iMidi),
//    bind textures (including outputs of earlier passes), glDrawArrays.
//
// glUseProgram(pass->prog);
// for (auto& u : pass->uniforms) u.upload(pass->prog);
// for (auto& t : pass->textures) glBindTextureUnit(t.unit, t.id);
// glBindFramebuffer(GL_FRAMEBUFFER, pass->fbo);
// glViewport(0, 0, pass->w, pass->h);
// glDrawArrays(GL_TRIANGLES, 0, 3);  // fullscreen triangle
```

## References
- <https://github.com/aiekick/NoodlesPlate>
