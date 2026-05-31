# win32asm — Hand-Written x86/x64 Win32 in Assembly

Hand-written x86/x64 Win32 is useful less as an application strategy than as a forcing function for understanding what the CRT and compiler synthesize. The PE entry point is whatever `/ENTRY` names; there is no automatic `argv`, no global constructor pass, no C heap, and no safe return path unless you build one. On x86 you must obey stdcall/cdecl differences; on x64 every Win32 call needs the Microsoft x64 ABI: RCX/RDX/R8/R9 arguments, 32 bytes of shadow space, and 16-byte stack alignment at call boundaries.

The repository also makes import resolution explicit. You can declare imports and let the linker build the import table, or you can walk the PEB and resolve exports dynamically, which is the same technique used by shellcode and some no-import loaders. That is why this belongs beside no-CRT C templates: both are about exposing the process-start contract normally hidden by MSVC startup.

## Source Code Reading

The linked `bplaat/win32asm` repository should be read as a build-and-ABI specimen:
- assembly source owns the entry point;
- import declarations determine whether the linker emits a normal import table;
- x64 calls reserve shadow space and preserve stack alignment;
- process termination is explicit through `ExitProcess`.

Minimal call-shape probe:

```asm
; x64 Win32 call shape
sub rsp, 40        ; 32-byte shadow space + alignment slop
mov rcx, 0         ; first argument
call ExitProcess
```

Claim -> disassembly/probe -> interpretation:
- Claim: "assembly avoids the CRT."
- Probe: inspect imports and entry point with `dumpbin /headers /imports`.
- Interpretation: assembly avoids compiler/CRT startup only if the link also avoids CRT libraries and names a direct entry point. Assembly that links a C runtime is still a CRT program.

## Connections
- `Win32 No-CRT C Template` is the same experiment with C syntax and a compiler.
- `winnt.h` and `basestd.h` explain the calling-convention and integer-width vocabulary that assembly has to satisfy manually.

## References
- <https://github.com/bplaat/win32asm>
