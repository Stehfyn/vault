# dsound.h

DirectSound 8's COM API for playback/capture buffers, cooperative levels, 3D positional sound, and legacy hardware-acceleration flags. On modern Windows, DirectSound is mostly an emulation layer over the audio engine rather than direct hardware mixing; exclusive low-latency work moved to WASAPI, while games moved to XAudio2, FMOD, Wwise, or custom engines. It remains valuable for old-game compatibility and for understanding why wrapper projects translate `IDirectSoundBuffer8::Lock`/`Unlock` ring-buffer semantics into OpenAL, XAudio2, or WASAPI writes.

Connections: see `Audio/DirectSound to OpenAL (EAX Revival).md` outside this tree and `(MMCSS) Multimedia Class Scheduler Services/MMCSS Research.md`; DirectSound-era assumptions about priority, latency, and hardware buffers do not map cleanly onto Vista+ shared-mode audio.

## References
- dsound.h
