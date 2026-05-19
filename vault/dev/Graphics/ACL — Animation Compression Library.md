<!-- generated-from-dump2 -->
# ACL — Animation Compression Library

Animation Compression Library - Nicholas Frechette's open-source skeletal-animation compressor. Solves the actual problem that ships in real engines: a 60-FPS 100-bone character at 16 floats/bone is 38 KB/s uncompressed, untenable for cinematic scenes. ACL applies per-track quantization + per-segment range reduction + variable-rate keyframes; typically gets 90-98% size reduction with sub-millimeter / sub-degree decompression error. Used in production by Unreal Engine 5 as the default skeletal anim format.

```cpp
#include <acl/compression/compress.h>
#include <acl/decompression/decompress.h>

acl::ANSIAllocator allocator;
acl::track_array_qvvf tracks = LoadRawAnim();           // float QVVf tracks per bone
acl::compression_settings settings = acl::get_default_compression_settings();

acl::compressed_tracks* compressed;
acl::error_result err = acl::compress_track_list(allocator, tracks, settings,
                                                 compressed);
// decoder is a stateless function reading from compressed memory
acl::decompression_context<acl::default_transform_decompression_settings> ctx;
ctx.initialize(*compressed);
ctx.seek(time);
acl::qvvf_writer writer{ outputPose };
ctx.decompress_tracks(writer);
```

## References
- <https://github.com/nfrechette/acl>
