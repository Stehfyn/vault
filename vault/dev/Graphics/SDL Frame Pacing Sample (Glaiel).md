<!-- generated-from-dump2 -->
# SDL Frame Pacing Sample (Glaiel)

Sample code from Tyler Glaiel's frame-pacing investigation showing why naive `SDL_Delay`/vsync gives jittery animation. The key insight: present-time variance hides behind vsync, so you need to measure actual display refresh, predict the next vblank, and time-step your simulation against that prediction rather than against `dt = now - last`. Pair with Glaiel's blog post "Squeezing performance out of a fixed timestep" for the math.

```cpp
// Sketch: predict the next vblank, step sim to that time, then sleep until it.
Uint64 prevPresent = SDL_GetPerformanceCounter();
double freq        = (double)SDL_GetPerformanceFrequency();
double refresh     = 1.0 / GetDisplayRefreshHz();

for (;;) {
    Uint64 predicted = prevPresent + (Uint64)(refresh * freq);
    while (SimTime() + FIXED_DT <= predicted / freq) StepSim(FIXED_DT);
    Render(InterpolationAlpha());
    SDL_GL_SwapWindow(win);                // blocks on vsync; measure when it returns
    prevPresent = SDL_GetPerformanceCounter();
}
```

## References
- <https://github.com/TylerGlaiel/SDL-Frame-Pacing-Sample>
