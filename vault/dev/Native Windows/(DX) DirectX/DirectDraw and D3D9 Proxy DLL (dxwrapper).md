# DirectDraw and D3D9 Proxy DLL (dxwrapper)

`dxwrapper` is a legacy-game compatibility shim: place proxy DLLs such as `ddraw.dll`, `d3d8.dll`, or `d3d9.dll` beside an old executable, forward calls to the real system DLL, and patch behavior on the way through. That lets it fix broken DirectDraw surfaces, old fullscreen modes, frame pacing, color conversion, and API assumptions without modifying the game binary.

This is the user-mode compatibility cousin of `DirectDraw GDI (ddrawgdi).md`. `ddrawgdi` is the driver/DDI surface; `dxwrapper` is the application-facing detour layer. It belongs in the same mental bucket as OpenGL `opengl32.dll` replacement/Mesa notes: DLL search order becomes the deployment mechanism.

## References
- <https://github.com/elishacloud/dxwrapper>
