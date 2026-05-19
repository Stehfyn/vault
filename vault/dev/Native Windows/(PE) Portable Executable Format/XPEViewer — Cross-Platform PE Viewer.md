# XPEViewer - Cross-Platform PE Viewer

XPEViewer is useful because it is a broad, careful parser rather than a one-directory PE demo. The PE side covers headers, sections, imports, exports, resources, relocations, TLS, debug records, signatures, .NET metadata, overlays, and other directories while also handling ELF and Mach-O for comparison.

The strongest lesson is validation. Real binaries contain malformed offsets, overlays, packed sections, stripped directories, API-set imports, delay imports, and metadata produced by many toolchains. A PE viewer that bounds-checks and cross-validates fields is a better reference than a snippet that assumes every RVA and size is honest.

## Connections
- `Hex Dump` gives the raw byte view behind XPEViewer's structured interpretation.
- `Control Flow Graph` consumes executable sections after PE parsing has identified them.

## References
- <https://github.com/horsicq/XPEViewer>
