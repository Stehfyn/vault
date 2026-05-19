# CRT Linkage (MD MT DLL)

`/MD` and `/MT` choose the CRT implementation model, not whether the program itself is a DLL or an EXE. `/MD` links import libraries and expects the Universal CRT / vcruntime DLLs at run time; `/MT` copies the static CRT into each linked image. `/LD` merely tells the linker to produce a DLL. Confusing these flags produces the classic plugin bug: an EXE and a DLL each built with static CRTs have separate heaps, separate `errno`, separate locale state, and separate `atexit` lists, so allocating in one module and freeing in another is undefined even when the signatures look compatible.

The modern default for application code is usually `/MD` because servicing, heap ownership, and ABI boundaries are cleaner. `/MT` is defensible for single-file tools, recovery environments, and deployment targets where redistributables are the real failure mode. Mixing `/MDd`, `/MTd`, `/MD`, and `/MT` across a process should be treated as a build-system error unless every boundary is pure Win32 handles or caller-owned buffers.

## Connections
- `Binary Size Reduction` and `VC-LTL5` explain two different reasons people fight the default CRT linkage.
- `CRT Startup Hooks` is affected by this choice because each CRT instance owns its own initializer tables and termination callbacks.

## References
- <https://stackoverflow.com/questions/35884239/conceptual-ambiguity-between-md-mt-and-dll-lib/35884751#35884751>
