# Control Flow Graph

The linked ControlFlowGraph-Win32-x86 project is a compact example of building a graph from a PE image by finding executable code and decoding branch/call/return edges. The useful detail is not merely "parse `.text`"; a workable CFG has to respect PE section mapping, image base/RVA translation, x86 variable-length instructions, fall-through edges, indirect branches, import thunks, and compiler-generated tables.

For Native Windows work, CFGs connect static PE analysis to runtime mitigation and debugging. Microsoft's Control Flow Guard is a loader-enforced metadata story, while a research CFG is an inference story built from bytes and symbols. Comparing the two explains why static tools can be useful yet incomplete around callbacks, exceptions, virtual dispatch, delay imports, and handwritten assembly.

## Connections
- `XPEViewer` is a broader parser for PE directories and metadata.
- `Hex Dump` is the raw inspection baseline before structured PE parsing.

## References
- https://github.com/z4p4n/ControlFlowGraph-Win32-x86
- https://raw.githubusercontent.com/z4p4n/ControlFlowGraph-Win32-x86/master/main.cpp
