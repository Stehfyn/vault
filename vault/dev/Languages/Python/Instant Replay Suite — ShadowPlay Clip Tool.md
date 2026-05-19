<!-- generated-from-dump2 -->
# Instant Replay Suite — ShadowPlay Clip Tool

(Effectively obsolete since Steam shipped its own Game Recording feature.) Python + FFmpeg desktop utility that watches the folder NVIDIA ShadowPlay / GeForce Experience drops Instant Replay clips into, then post-processes them: auto-trim to a configurable tail length, re-encode to a smaller upload-friendly preset, append metadata, optionally chain clips together. Solves the specific pain of "ShadowPlay always saves the last 30 minutes and you actually want the last 15 seconds" without forcing the user to open an NLE. FFmpeg-driven so the heavy lifting (concat demuxer, stream copy when possible) avoids re-encoding round-trips when the clip is already in the target codec.

```python
# Typical config-driven flow (the actual project uses a GUI, but conceptually:)
import subprocess, pathlib, time

CLIP_DIR = pathlib.Path(r"C:/Users/<you>/Videos")
TAIL_SECONDS = 15

def trim_tail(src: pathlib.Path, dst: pathlib.Path) -> None:
    # -sseof seeks from end of file; stream-copy avoids re-encoding
    subprocess.run([
        "ffmpeg", "-y", "-sseof", f"-{TAIL_SECONDS}",
        "-i", str(src), "-c", "copy", str(dst),
    ], check=True)
```

## References
- <https://github.com/thisismy-github/instant-replay-suite>
