<!-- generated-from-dump2 -->
# SilentPatch for Far Cry (2004)

Adrian Zdanowicz's "SilentPatch" line of unofficial patches applied to Far Cry (2004) — fixes water reflections that stopped working on modern GPUs/drivers, removes hard-coded resolution caps, and corrects FOV math on widescreen monitors. Implementation pattern (same across the SilentPatch series): a `dinput8.dll` proxy that hooks the game's relevant call sites at load time and rewrites instructions with a `Hooking.Patterns` byte-signature matcher so the patch survives across game versions.

```cpp
// Pattern: find the broken call site by a unique instruction signature,
// then redirect to a fixed implementation.
auto pattern = hook::pattern("8B 0D ? ? ? ? 8B 51 ? FF D2");
if (!pattern.empty()) {
    void* call_site = pattern.get_first(0);
    Hooking::InjectHook(call_site, FixedWaterReflections, PATCH_JUMP);
}
```

## References
- <https://github.com/CookiePLMonster/SilentPatchFarCry>
