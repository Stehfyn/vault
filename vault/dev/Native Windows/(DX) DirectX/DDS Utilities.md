# DDS Utilities

The archived NVIDIA DDS utilities (`nvDXT`, `readDXT`, detach/stitch tools) are historically useful for understanding the asset pipeline around block-compressed textures. For current Windows code, DirectXTex is the cleaner programmatic path: load DDS metadata and image data, preserve BC formats, generate mipmaps, convert formats, and hand the result to D3D texture creation without inventing a parser.

DDS matters because it stores GPU-native texture layouts and mip chains that PNG/JPEG workflows do not: BC1/BC3/BC5/BC7, cubemaps, arrays, volume textures, and precomputed mip levels. Treat it as an asset/container note, not a rendering API note.

## References
- <https://archive.org/details/NVIDIA_DDS_Utilities_8.31>
- <https://github.com/microsoft/DirectXTex>
