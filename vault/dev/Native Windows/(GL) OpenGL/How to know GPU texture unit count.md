Query the number of texture units available on the current GPU using `glGetIntegerv`. `GL_MAX_TEXTURE_IMAGE_UNITS` is the limit per fragment shader stage; `GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS` is the total across all shader stages. OpenGL 3.x hardware typically reports 16 per-stage and 48+ combined.

```c
GLint maxTextureUnits = 0;
glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureUnits);
// GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS for total across all stages
GLint maxCombined = 0;
glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxCombined);
```

## References
- https://www.reddit.com/r/opengl/comments/z7v9s6/way_to_know_number_or_gpu_texture_units/
