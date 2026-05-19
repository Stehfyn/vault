<!-- generated-from-dump2 -->
# ddspp — Single-File DDS Codec

Single-file C++ encoder/decoder for the DDS (DirectDraw Surface) container. Handles every quirk that the DDS spec accumulated over 20 years: DXT1/3/5/BC4/BC5/BC6H/BC7, the DX10 extended header for typed array/cube formats, the original DDSCAPS2 vs DX10-header dichotomy, mip and cube faces order, and the row-pitch alignment rules that differ between block-compressed and uncompressed surfaces. The whole thing is ~400 lines and has zero dependencies - drops into any engine pipeline.

```cpp
#include "ddspp.h"

ddspp::Descriptor d;
auto* file = OpenFile("tex.dds", "rb");
unsigned char header[ddspp::MAX_HEADER_SIZE];
fread(header, 1, sizeof(header), file);
auto result = ddspp::decode_header(header, d);
// d.width, d.height, d.format (DXGI_FORMAT_BC7_UNORM, etc.)
// d.numMips, d.arraySize, d.type (1D/2D/3D/Cubemap), d.headerSize

fseek(file, d.headerSize, SEEK_SET);
// read d.numMips * d.arraySize subresources at correct pitches
```

## References
- <https://github.com/redorav/ddspp>
