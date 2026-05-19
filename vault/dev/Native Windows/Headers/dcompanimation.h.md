# dcompanimation.h

DirectComposition's curve-animation interface. `IDCompositionAnimation` is not a general timeline framework; it is a compact way to hand the compositor a piecewise function (`AddCubic`, `AddSinusoidal`, repeats, end values) so transforms, opacity, and related visual properties can advance on the compositor side without your UI thread waking every frame. That distinction matters for smoothness: a blocked app thread can miss commits, but an already-submitted compositor animation can continue until it needs new state.

Connections: pair with `dcomp.h` and the DWM timing notes (`VBlank Wait.md`, `DCompositionWaitForCompositorClock -- Decompiled.md`). It is closer to DWM/Composition scheduling than to a Win32 timer or game-loop animation.

## References
- dcompanimation.h
