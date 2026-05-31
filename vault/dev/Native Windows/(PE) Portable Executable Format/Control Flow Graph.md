# Control Flow Graph

The linked ControlFlowGraph-Win32-x86 project is a compact example of building a graph from a PE image by finding executable code and decoding branch/call/return edges. The useful detail is not merely "parse `.text`"; a workable CFG has to respect PE section mapping, image base/RVA translation, x86 variable-length instructions, fall-through edges, indirect branches, import thunks, and compiler-generated tables.

For Native Windows work, CFGs connect static PE analysis to runtime mitigation and debugging. Microsoft's Control Flow Guard is a loader-enforced metadata story, while a research CFG is an inference story built from bytes and symbols. Comparing the two explains why static tools can be useful yet incomplete around callbacks, exceptions, virtual dispatch, delay imports, and handwritten assembly.

## Source Code Reading

The linked `ControlFlowGraph-Win32-x86` source is explicit about its assumptions.

Files read:
- `main.cpp`
- `cfg/win32_cfg.cpp`
- `cfg/win32_cfg.h`
- `hde28c/hde32.cpp`
- `graph/graph.cpp`
- `pe/pelib/pelib.cpp`
- `pe/pelib_extend/pelib_extend.cpp`

`main.cpp` uses `PELibrary` / `PEExtend` to open the PE, reads `IMAGE_NT_HEADERS`, chooses the section containing the entry point (`EPSectionNum`), and derives:
- `SizeOfRawData`
- `PointerToRawData`
- `AddressOfEntryPoint`
- `BaseOfCode`
- `ImageBase`
- entry-point offset inside the code section

`cfg/win32_cfg.cpp` then uses `hde32_disasm` to walk variable-length x86 instructions. `cfg_call_builder` marks byte offsets with node IDs, emits call targets, stops on `RET`, follows conditional branches, follows direct `JMP`, and uses `PEExtend::GetFunctionName` to identify import calls.

```text
cfg_call_builder(start):
  while offset < SizeOfRawData:
    if alignment block: stop
    hde32_disasm(text + offset)
    if import call: annotate
    if CALL rel: add fallthrough and target
    if RET: stop
    if Jcc: add branch target and fallthrough
    if JMP: add target and stop/continue per kind
```

Claim -> source/probe -> interpretation:
- Claim: "A static CFG can recover program control flow from a Win32 binary."
- Source/probe: this project recovers direct x86 branches from the entry-point section; test it on `/Od`, `/O2`, and exception-heavy binaries.
- Interpretation: the claim is only partially true. Direct calls and branches are tractable; callbacks, import dispatch, C++ EH, SEH, virtual calls, jump tables, and delay-load thunks require extra metadata and runtime knowledge.

## Connections
- `XPEViewer` is a broader parser for PE directories and metadata.
- `Hex Dump` is the raw inspection baseline before structured PE parsing.

## References
- https://github.com/z4p4n/ControlFlowGraph-Win32-x86
- https://raw.githubusercontent.com/z4p4n/ControlFlowGraph-Win32-x86/master/main.cpp
