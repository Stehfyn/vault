<!-- generated-from-dump2 -->
# fastfetch — Fast C Reimplementation of Neofetch

C reimplementation of neofetch — the same "screenshot your terminal showing distro logo + system specs" tool, but ~50-100x faster because it does *not* shell out. The original neofetch was 7K lines of bash; each module spawned `lspci`, `xrandr`, `glxinfo`, etc. fastfetch calls the kernel/sysctl/wmi/dxgi APIs directly, so a full run completes in single-digit milliseconds where neofetch could take 1-2 seconds. Cross-platform (Linux, *BSD, macOS, Windows, Android) with per-OS native implementations. Output format is JSON-or-printable, configured via TOML/JSONC, supports custom logos and per-section formatting. Replaced neofetch effectively for most users after neofetch went unmaintained in 2024.

```bash
# Default invocation:
$ fastfetch
# Configure with JSONC at ~/.config/fastfetch/config.jsonc :
#   {
#     "modules": [
#       "title", "separator", "os", "kernel", "uptime",
#       "cpu", "gpu", "memory", "disk",
#       "display", "terminal", "shell"
#     ]
#   }

# Programmatic / scripting use:
$ fastfetch --format json | jq '.cpu.result.name'
"AMD Ryzen 9 7950X 16-Core Processor"
```

## References
- <https://github.com/fastfetch-cli/fastfetch>
