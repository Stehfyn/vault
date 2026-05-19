# Hex Dump

`win32CanonHexdump` is a small Windows-native example of a canonical hex dump: offset column, sixteen bytes per row, and an ASCII gutter. Its value in a PE section is methodological. Before a parser explains a header, import table, overlay, or corrupt section, a hex dump lets you verify the bytes and offsets the parser claims to see.

The raw `Output.cpp` matters because formatting is the whole tool: byte alignment, short final rows, printable-character filtering, and stable offsets make binary comparisons human-readable. It is a useful low-level companion to XPEViewer and CFG tooling because both ultimately stand or fall on correct byte interpretation.

## Connections
- `XPEViewer` turns the same bytes into PE/ELF/Mach-O structures.
- `Control Flow Graph` starts from executable bytes and adds decoding semantics.

## References
- https://raw.githubusercontent.com/SenpaiSilver/win32CanonHexdump/master/src/win32CanonicalHexdump/Output.cpp
- https://github.com/SenpaiSilver/win32CanonHexdump
