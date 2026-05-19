<!-- generated-from-dump2 -->
# Sunshine — Moonlight Game Stream Host

Self-hosted game-stream server compatible with Moonlight clients (the open-source NVIDIA GameStream replacement). Captures the desktop via DXGI/NVENC/AMF/VAAPI/VideoToolbox, encodes H.264/HEVC, and streams over the GameStream protocol. Drop-in replacement after NVIDIA killed GameStream in late 2022.

```yaml
# sunshine.conf excerpt
encoder = nvenc           # nvenc | amdvce | quicksync | software
qp = 23
fec_percentage = 20
[apps]
[[apps]]
name = "Steam Big Picture"
cmd  = "C:\\Program Files (x86)\\Steam\\steam.exe -bigpicture"
```

## References
- <https://github.com/LizardByte/Sunshine>
