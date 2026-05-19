<!-- generated-from-dump2 -->
# ffmpeg-cpp — Fluent C++ Wrapper for libav*

Thin C++ wrapper that hides the `libav*` filter-graph and codec boilerplate behind a fluent API — `InputSource -> Decoder -> Filter -> Encoder -> Muxer`. Good entry point if you've stared at `avformat_open_input` / `avcodec_send_packet` for ten minutes and decided you don't want to debug error codes in `-EAGAIN` form. The trade-off vs. direct libav: you lose some control over packet pacing and explicit pts/dts manipulation, which matters for live streams but not for transcodes.

```cpp
#include <ffmpegcpp.h>
using namespace ffmpegcpp;

Muxer       mux("out.mp4");
H264Codec   vidCodec; vidCodec.SetBitRate(2'000'000);
AACCodec    audCodec;
VideoEncoder vEnc(&vidCodec, &mux);
AudioEncoder aEnc(&audCodec, &mux);

Demuxer demux("in.mov");
demux.DecodeBestVideoStream(&vEnc);
demux.DecodeBestAudioStream(&aEnc);
demux.PreparePipeline();
while (!demux.IsDone()) demux.Step();
mux.Close();
```

## References
- <https://github.com/Raveler/ffmpeg-cpp>
