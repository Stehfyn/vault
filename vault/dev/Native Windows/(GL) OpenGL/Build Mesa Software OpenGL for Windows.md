# Build Mesa Software OpenGL for Windows

mmozeiko's build scripts produce Mesa software OpenGL binaries for Windows, typically used by placing `opengl32.dll` beside an executable so the app loads Mesa instead of the system ICD path. This is useful for deterministic software rendering, CI, debugging driver-specific failures, or running GL code on machines with broken/absent hardware drivers.

The key Windows detail is DLL search order. This does not install a system ICD; it overrides the process-local OpenGL loader. Pair it with `Mesa3D Pre-built Windows Drivers.md`: one note is the build-from-source path, the other is the packaged distribution path.

## References
- <https://github.com/mmozeiko/build-mesa>
