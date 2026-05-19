# lzexpand.h — Legacy LZ Compression API

`lzexpand.h` is the old Windows LZ decompression API behind functions such as `LZOpenFile`, `LZCopy`, and `LZRead`. It exists for setup programs and compressed files from the 16-bit/Win9x lineage, including the familiar underscore-suffixed payloads in old distribution media.

New code should use Cabinet, ZIP/MSIX, or a maintained compression library. Keep this entry for reverse engineering and installer maintenance: the handles, `OFSTRUCT` conventions, and error model are legacy enough that blindly wrapping them in modern file abstractions tends to hide edge cases.

## Connections
- `Cabinet Files (FDI)` is the more relevant Microsoft setup-compression API for MSI-era packages.
- `win98-quickinstall` is an example of old setup media where LZ/CAB-era payload conventions still matter.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/lzexpand/>
