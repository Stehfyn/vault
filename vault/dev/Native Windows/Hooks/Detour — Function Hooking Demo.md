# Detour - Function Hooking Demo

This Detour repository is a minimal function-hooking demonstration in the Microsoft Detours style: preserve the original callable path, redirect the target entry to replacement code, and use a trampoline when the hook still needs to call through. Its value is as a small specimen of inline user-mode interception, not as a complete hooking framework.

The important engineering issues are the ones demos usually compress: instruction-length decoding, atomic patching around running threads, memory protection changes, instruction-cache flushing, x86/x64 jump encoding, and preserving calling convention/register state. Compare it with MinHook when the question is what a hardened small library adds beyond the concept.

## Connections
- MinHook is the mature minimal library in this family.
- HookLib and Kernel-Bridge move related interception ideas into broader native/kernel contexts.

Code contribution: compare its trampoline and patch path around `VirtualProtect`, instruction decoding, relative jumps, `FlushInstructionCache`, and original-function call-through.

## References
- <https://github.com/Zer0Mem0ry/Detour>
