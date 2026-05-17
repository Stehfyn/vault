1. https://stackoverflow.com/questions/3311388/how-to-speed-up-offscreen-opengl-rendering-with-large-textures-on-win32
2. Snippet (performance advice from SO):
```text
Use power-of-two textures (e.g., 1024x1024 instead of 1024x768) to avoid slow special-case paths.
Key limits: memory transfer rate, fill rate, texture read rate, shader cost.
```
3. Note: Prefer FBOs (or WGL pbuffers on legacy setups) for offscreen render targets to avoid readback stalls.
