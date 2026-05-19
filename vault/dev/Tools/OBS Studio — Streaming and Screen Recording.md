<!-- generated-from-dump2 -->
# OBS Studio — Streaming and Screen Recording

OBS Studio - the canonical open-source streaming and screen-recording app. Worth knowing as a reference codebase for: (a) the plugin architecture (every source/filter/encoder is a loaded .dll/.so implementing a stable C ABI), (b) the cross-platform graphics abstraction (`libobs` exposes a thin layer over D3D11/OpenGL/Metal for compositing video sources to one output texture), (c) how it handles encoder hand-off - NVENC/QuickSync/x264/AMF live behind a uniform encoder interface and OBS auto-selects per platform.

```text
# Repo layout:
libobs/             # core graphics + media pipeline (C ABI)
plugins/            # win-capture, obs-x264, mac-syphon, linux-pipewire, ...
UI/                 # Qt frontend
deps/               # bundled libs (lua, freetype, etc.)
```

## References
- <https://github.com/obsproject/obs-studio>
