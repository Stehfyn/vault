# MinHook - Minimal x86/x64 Hooking Library

MinHook is the standard small Windows inline-hooking library: plain C, x86/x64 support, trampoline generation, thread-safety considerations, and a deliberately narrow API. Its importance is that it does the unglamorous hard parts that most demos omit, especially instruction decoding and building a callable gateway back to the overwritten prologue.

Use it as the baseline for user-mode function interception discussions. If a note claims to "detour" a function but does not discuss instruction boundaries, patch atomicity, executable memory protections, and unwind/calling-convention effects, MinHook is the reference that shows what is missing.

## Connections
- Detour is a simpler demonstration of the same family.
- Capnhook in `Hook Examples` is another inline/IAT hooking reference.

## References
- <https://github.com/TsudaKageyu/minhook>
