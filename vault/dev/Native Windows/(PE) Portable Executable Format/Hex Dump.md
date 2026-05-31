# Hex Dump

`win32CanonHexdump` is a small Windows-native example of a canonical hex dump: offset column, sixteen bytes per row, and an ASCII gutter. Its value in a PE section is methodological. Before a parser explains a header, import table, overlay, or corrupt section, a hex dump lets you verify the bytes and offsets the parser claims to see.

The raw `Output.cpp` matters because formatting is the whole tool: byte alignment, short final rows, printable-character filtering, and stable offsets make binary comparisons human-readable. It is a useful low-level companion to XPEViewer and CFG tooling because both ultimately stand or fall on correct byte interpretation.

## Source Code Reading

The linked `win32CanonHexdump` source is small enough to read completely.

Files read:
- `src/win32CanonicalHexdump/main.cpp`
- `src/win32CanonicalHexdump/File.cpp`
- `src/win32CanonicalHexdump/Output.cpp`
- `src/win32CanonicalHexdump/win32CanonicalHexdump.vcxproj`

`Output::PrintBytes` composes the canonical line:

```text
PrintBytes(addr, nb, buffer):
  print 8-hex-digit offset: addr - nb
  print bytes 0..7 as two hex digits, pad missing bytes
  print separator
  print bytes 8..15, pad missing bytes
  print ASCII gutter; replace control chars with '.'
```

That explains why a hex dump is a parser sanity tool: the address column is derived from byte count, not PE metadata; the ASCII gutter is filtered independently; the final row is padded so visual alignment survives short reads.

Probe: dump the first `0x200` bytes of a PE and verify `MZ`, `e_lfanew`, `PE\0\0`, and the first section header by offset. If XPEViewer or your parser reports a field inconsistent with this dump, debug RVA/file-offset translation before blaming the binary.

## Connections
- `XPEViewer` turns the same bytes into PE/ELF/Mach-O structures.
- `Control Flow Graph` starts from executable bytes and adds decoding semantics.

## References
- https://raw.githubusercontent.com/SenpaiSilver/win32CanonHexdump/master/src/win32CanonicalHexdump/Output.cpp
- https://github.com/SenpaiSilver/win32CanonHexdump
