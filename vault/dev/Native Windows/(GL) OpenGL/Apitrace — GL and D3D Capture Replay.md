# Apitrace — GL and D3D Capture Replay

Apitrace records graphics API calls and replays them later, which makes it useful for debugging stateful OpenGL and older D3D paths where a single bad bind or pixel-store setting can poison later draws. The replay model is the key distinction from a frame debugger: it captures the API stream, lets you trim/replay it, inspect resources, and compare behavior across drivers.

Use it beside `glintercept` in `OpenGL Examples.md`. `glDebugMessageCallback` tells you what the driver complains about in-process; apitrace gives you a portable artifact that can be replayed and bisected. For native Windows interop work, it is also useful when a bug appears only after WGL/DXGI sharing or swap-chain transitions.

## References
- <https://github.com/apitrace/apitrace>
