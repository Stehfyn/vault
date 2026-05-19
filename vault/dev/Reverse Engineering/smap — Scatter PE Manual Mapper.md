<!-- generated-from-dump2 -->
# smap — Scatter PE Manual Mapper

DLL "scatter" mapper — a manual mapper that avoids the usual giveaways. Standard manual mapping allocates one contiguous block and copies the PE there: anti-cheats walk all VirtualAlloc'd RWX regions and look for an MZ/PE header at base. smap defeats that by **scattering** each section into a separate, unrelated allocation and patching the relative addresses to bridge them, then pages out the PE headers entirely so there's no MZ signature in memory to scan for. Also resolves imports without touching the PEB loader list. Targeted at bypassing user-mode anti-cheat scanners (EAC, BattlEye in user mode). Educational artifact for how PE loaders actually resolve addresses.

```cpp
// Conceptual flow (real impl: Mapper.cpp, ManualMap.cpp):
//   1. For each PE section, VirtualAllocEx into an unrelated address
//      (not contiguous with the others) with the right page protections.
//   2. Copy section bytes; do NOT copy DOS/NT headers.
//   3. Apply base relocations using your scattered layout: a RVA in the
//      .text section now points into a *different* allocation that holds .data.
//   4. Resolve IAT by walking your own .idata copy and writing thunks.
//   5. Discard PE headers (they would be a signature) - never copy them.
//   6. CreateRemoteThread (or hijack) into the new entry point.
```

## References
- <https://github.com/btbd/smap>
