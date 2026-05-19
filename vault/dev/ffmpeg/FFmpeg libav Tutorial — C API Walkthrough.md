<!-- generated-from-dump2 -->
# FFmpeg libav Tutorial — C API Walkthrough

The single best free walkthrough of the FFmpeg `libav*` C API — starts from "what is a container vs. a codec vs. a stream" and ends with a remuxer + transcoder you actually understand. Notable because it spends real time on the *concepts* (PTS/DTS, time bases, B-frame ordering, GOPs) that the man-pages assume you already know. Translated into ~7 languages.

```c
// Canonical libav decode loop (sketch from the tutorial).
AVPacket* pkt   = av_packet_alloc();
AVFrame*  frame = av_frame_alloc();
while (av_read_frame(fmtCtx, pkt) >= 0) {
    if (pkt->stream_index == videoIdx) {
        avcodec_send_packet(codecCtx, pkt);
        while (avcodec_receive_frame(codecCtx, frame) == 0) {
            // frame->data, frame->linesize, frame->pts
            av_frame_unref(frame);
        }
    }
    av_packet_unref(pkt);
}
```

## References
- <https://github.com/leandromoreira/ffmpeg-libav-tutorial>
