<!-- generated-from-dump2 -->
# media2 — FFmpeg Reactive Pipeline Wrapper

Personal C++ wrapper around FFmpeg that re-architects the libav data flow around boost::signals2: each `AVStream` is fronted by an object that emits packets/frames to connected slots, so a pipeline (demux -> decode -> rescale -> OpenCV `cv::Mat` via `Frame2Mat` -> segmenter -> ZeroMQ publisher) is wired with signal/slot connections instead of manual `av_read_frame` loops. The interesting design choice is separating packet reading from decoding so you can fan a single demux out to N decoders, and the segmenter cuts the stream into keyframe-aligned, serializable chunks suitable for distributed processing. Worth reading as a "what if FFmpeg had a reactive API" sketch — author admits leaks and rough edges.

```cpp
// Conceptual wiring (real names in include/hrh/media2/*.hpp).
// Demuxer reads packets and emits per-stream signals.
auto demux = std::make_shared<Demuxer>("input.mp4");
auto vdec  = std::make_shared<VideoDecoder>(demux->videoCodecpar());
demux->videoPacket.connect([&](AVPacket* p){ vdec->push(p); });

// Decoder -> OpenCV Mat -> sink
auto toMat = std::make_shared<Frame2Mat>();
vdec->frame.connect([&](AVFrame* f){ toMat->push(f); });
toMat->mat.connect([&](cv::Mat m){ cv::imshow("v", m); cv::waitKey(1); });

demux->run();
```

## References
- <https://github.com/FlyingRhenquest/media2>
