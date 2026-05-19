<!-- generated-from-dump2 -->
# ffmpeg-video-player — Modernized dranger A/V Sync Tutorial

Modernized C port of the classic "dranger" FFmpeg+SDL tutorial — eight stages from "load a frame and write a PPM" through "audio-video sync with a separate audio decode thread". The pedagogical core is *clock synchronization*: video sync to audio, audio sync to external, or both sync to external, with the trade-offs each implies for A/V drift correction.

```c
// Stage-7-style sync: schedule next frame display based on PTS delta vs. wall clock.
double delay = vp->pts - is->frame_last_pts;
if (delay <= 0 || delay >= 1.0) delay = is->frame_last_delay;
is->frame_last_delay = delay;
is->frame_last_pts   = vp->pts;

double ref_clock = get_audio_clock(is);
double diff      = vp->pts - ref_clock;
double sync_thr  = (delay > AV_SYNC_THRESHOLD) ? delay : AV_SYNC_THRESHOLD;
if (fabs(diff) < AV_NOSYNC_THRESHOLD) {
    if      (diff <= -sync_thr) delay = 0;
    else if (diff >=  sync_thr) delay = 2 * delay;
}
```

## References
- <https://github.com/rambod-rahmani/ffmpeg-video-player>
