<!-- generated-from-dump2 -->
# DirectSound to OpenAL (EAX Revival)

Drop-in replacement for `dsound.dll` that routes every DirectSound and DirectSound3D call to OpenAL Soft as the actual backend. The win here is EAX 1-5 support — Creative's EAX is essentially dead on modern Windows because MS removed the DSound HAL in Vista, and dsoal restores it by emulating EAX via OpenAL Soft's EFX. Companion to `kcat/openal-soft`; install both next to a game's exe to revive EAX in older titles.

```text
// Drop dsound.dll (dsoal build) + soft_oal.dll + dsoal.ini next to game.exe.
// Game calls DirectSoundCreate8 -> dsoal -> alcOpenDevice -> OpenAL Soft.
// EAX commits via EAXContextSet -> OpenAL EFX (alAuxiliaryEffectSlot, ALC_EFX_*).
```

## References
- <https://github.com/kcat/dsoal>
