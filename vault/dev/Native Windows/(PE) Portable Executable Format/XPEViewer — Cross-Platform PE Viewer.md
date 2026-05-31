# XPEViewer - Cross-Platform PE Viewer

XPEViewer is useful because it is a broad, careful parser rather than a one-directory PE demo. The PE side covers headers, sections, imports, exports, resources, relocations, TLS, debug records, signatures, .NET metadata, overlays, and other directories while also handling ELF and Mach-O for comparison.

The strongest lesson is validation. Real binaries contain malformed offsets, overlays, packed sections, stripped directories, API-set imports, delay imports, and metadata produced by many toolchains. A PE viewer that bounds-checks and cross-validates fields is a better reference than a snippet that assumes every RVA and size is honest.

## Source Code Reading

The linked `horsicq/XPEViewer` repository is a GUI shell around a broad binary-inspection stack. Files inspected at the repository level include:
- `global.h`
- `gui_source/main_gui.cpp`
- `gui_source/guimainwindow.cpp`
- parser/view modules referenced by the project tree for PE, resources, signatures, overlays, and directory views.

Read it as a validation checklist rather than a short algorithm. A serious PE viewer has to display and cross-check:
- DOS header and `e_lfanew`.
- NT headers, optional header, data directories, and section table.
- RVA-to-file-offset translation for imports, exports, resources, relocations, TLS, debug, load config, and certificates.
- overlay bytes beyond mapped image data.
- malformed or packed binaries whose directory sizes and section bounds do not line up cleanly.

Code-driving probe: build a tiny parser that only prints `IMAGE_FILE_HEADER`, `IMAGE_OPTIONAL_HEADER`, and section bounds; then compare against XPEViewer on a normal EXE, a .NET assembly, and a packed/overlayed binary. Every mismatch becomes one missing parser rule.

## Connections
- `Hex Dump` gives the raw byte view behind XPEViewer's structured interpretation.
- `Control Flow Graph` consumes executable sections after PE parsing has identified them.

## References
- <https://github.com/horsicq/XPEViewer>
