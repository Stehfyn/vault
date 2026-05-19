# How to Know GPU Texture Unit Count

Query texture-unit limits from the current context with `glGetIntegerv`. `GL_MAX_TEXTURE_IMAGE_UNITS` is per fragment shader stage; `GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS` covers vertex sampling; `GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS` is the total across all shader stages. The current context matters because limits are driver/GPU/profile dependent.

The practical mistake is treating the number as "how many textures my renderer can have." It is only how many can be bound for one draw under that binding model. Modern GL can move some pressure to arrays, atlases, bindless textures, or multi-pass material sorting; D3D12-style bindless rendering is covered in the DirectX folder.

```c
GLint fragUnits = 0;
GLint combinedUnits = 0;
glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &fragUnits);
glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &combinedUnits);
```

## References
- <https://www.reddit.com/r/opengl/comments/z7v9s6/way_to_know_number_or_gpu_texture_units/>
