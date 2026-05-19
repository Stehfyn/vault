# VSync (OpenGL)

On Windows OpenGL, swap interval is controlled by `WGL_EXT_swap_control` (`wglSwapIntervalEXT(1)` for vsync). That asks the driver to synchronize `SwapBuffers` with presentation, but in windowed mode DWM composition means the app is not presenting directly to scanout. `DwmFlush` can sometimes reduce phase drift by waiting for DWM to process queued presents, but it is not a universal low-latency fix.

The StackOverflow thread matters because "reliable vsync" is a multi-layer problem: WGL swap interval, driver queue depth, DWM compositor cadence, and DXGI/D3DKMT vblank timing can disagree. Read it with the DWM vblank notes and `Late-Latched Uniforms for Input Lag.md`.

## References
- <https://stackoverflow.com/questions/45676892/reliable-windowed-vsync-with-opengl-on-windows>

## Connections
- `../(DWM) Desktop Window Manager/VBlank Wait.md`
- `../(DWM) Desktop Window Manager/How to dramatically improve Chrome's requestAnimationFrame VSYNC accuracy in Windows.md`
- `Late-Latched Uniforms for Input Lag.md`
