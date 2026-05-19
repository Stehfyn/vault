<!-- generated-from-dump2 -->
# obs-express — Headless CLI Wrapping libobs

OBS Studio reduced to a command-line recorder — same encode pipeline (libobs + the GPU capture/encoder plugins) but with no UI, no scenes, no profile system. You point it at a monitor or window and it writes a file. Designed to be embedded by screen-recording apps (the author's Clowd screenshot tool) that don't want to require users to install full OBS or to ship a custom DXGI/desktop-duplication capture stack. Strips down to roughly: pick source (display/window), pick encoder (NVENC/QSV/AMF/x264), pick resolution/fps, output path. Worth reading the build script to see how a libobs application can be slimmed compared to the full OBS Studio repo.

```bash
# Recorder CLI shape (per project README):
obs-express.exe ^
  --capture display ^
  --display 1 ^
  --encoder nvenc ^
  --fps 60 ^
  --crf 23 ^
  --audio default ^
  --output recording.mp4
# Ctrl+C to stop; mp4 is finalized via libobs's ffmpeg muxer.
```

## References
- <https://github.com/clowd/obs-express>
