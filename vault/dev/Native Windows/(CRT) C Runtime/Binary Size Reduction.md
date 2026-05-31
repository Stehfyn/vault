# Binary Size Reduction

Small Windows binaries are mostly a linker discipline problem. `/Os`, `/GL`, `/Gy`, `/Gw`, `/OPT:REF`, and `/OPT:ICF` remove dead functions, isolate data, fold identical COMDATs, and let LTCG see across translation units; they do not fix accidental CRT pull-in from exceptions, iostreams, locale, static constructors, stack cookies, checked iterators, or security-cookie initialization. The first useful pass is to inspect imports and map files: if a "tiny" tool imports `ucrtbase.dll`, `vcruntime*.dll`, or large C++ runtime surfaces, the source likely used a convenience feature that forced startup and teardown machinery into the binary.

The `fmt` size-reduction discussion matters because it shows the real trap: formatting libraries often instantiate templates and locale paths that dwarf the application's own logic. For no-CRT Win32 tools, the alternative is not "write everything in assembly"; it is to keep the API boundary explicit, use compiler intrinsics for memory primitives where possible, avoid C++ runtime features that imply global initialization, and link only the Win32 import libraries you actually call.

## Discussion Claim Triage

Forum/discussion links are useful for claims, not proof. Turn each claim into a binary-layout probe.

```text
claim: "this formatting path can produce a tiny Windows binary"
source/disassembly/probe:
  cl /nologo /Os /GL /Gy /Gw tiny.cpp /link /OPT:REF /OPT:ICF /MAP
  dumpbin /imports tiny.exe
  dumpbin /headers tiny.exe
  findstr /i "fmt locale iostream ucrt vcruntime" tiny.map
interpretation:
  if imports include ucrt/vcruntime or the map contains locale/iostream/codepage
  paths, the size claim is about a narrower source subset than the app now uses.
```

Claims worth extracting from discussion threads:
- "Header-only/template formatting is cheap" -> inspect instantiated symbols and COMDAT folding in the map.
- "`/OPT:REF` removes unused code" -> verify the function vanishes from the map and disassembly.
- "No-CRT is the only way to get small" -> compare no-CRT, `/MT`, `/MD`, and VC-LTL builds with identical behavior.
- "Section merging/alignment saves size" -> compare `SizeOfHeaders`, section raw sizes, and loader compatibility on the oldest target OS.

Do not record a size assertion without the compiler version, flags, target architecture, imports, map-file evidence, and exact source features used.

## Discussion Claim Verification

Claim: "This library or flag makes a Windows executable tiny."

Why it matters for new code: binary size is rarely caused by one switch. The code usually crossed a runtime boundary: formatting, exceptions, RTTI, locale, iostreams, static constructors, stack cookies, debug iterators, or an accidental CRT import. If the claim does not identify which source feature was removed, it does not teach the next program what to avoid.

How to verify:

```powershell
cl /nologo /O1 /GL /Gy /Gw tiny.cpp /link /OPT:REF /OPT:ICF /MAP:tiny.map
dumpbin /imports tiny.exe
dumpbin /headers tiny.exe
dumpbin /disasm tiny.exe > tiny.disasm.txt
findstr /i "ucrt vcruntime iostream locale fmt exception unwind _CxxThrowException" tiny.map
```

Minimal code/pseudocode:

```cpp
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void mainCRTStartup() {
    DWORD written = 0;
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "ok\n", 3, &written, 0);
    ExitProcess(0);
}
```

Interpretation: the Reddit `fmt` size thread is a useful prompt, not a portable conclusion. The only verified claim is the artifact diff for a named compiler, flags, source body, architecture, and target. Nullify any statement like "fmt is always tiny" or "no-CRT is always smaller" unless the map and imports prove that the compared binaries implement the same behavior.

## Connections
- `No-CRT Win32`, `Win32 No-CRT C Template`, and `CRT Linkage (MD MT DLL)` are the practical knobs behind most size wins.
- `VC-LTL5` is a different tradeoff: keep CRT semantics but forward much of the implementation to system DLLs.

## References
- <https://www.reddit.com/r/cpp/comments/1f561x3/honey_i_shrunk_fmt_bringing_binary_size_to_14k/>
- <https://downloads.ctfassets.net/9pcn2syx7zns/1WZnLuQfJlIcjRR8GeJRM2/857dc5743f68461a7e0e39a5faabfd87/c-run-time-reference.pdf>
