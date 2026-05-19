<!-- generated-from-dump2 -->
# Komorebi — Tiling WM (Windows)

Jade Iqbal's tiling window manager for Windows — the most credible attempt at "i3/bspwm on Windows" and currently the de-facto answer when someone asks. Written in Rust, talks to the Windows API directly (no shell replacement), uses a daemon (`komorebi.exe`) plus a CLI client (`komorebic.exe`) and an optional companion bar (`komorebi-bar`). Strongly opinionated about workspaces, monitors, and per-application rules; the configuration is now a TOML/JSON schema (`komorebi.json`) plus an AHK or whkd-driven hotkey layer. Caveats: certain pathological apps (UWP "windows" that aren't real HWNDs, anything with a custom non-client area like Discord) need explicit rules to behave, and HiDPI mixed-monitor setups can still produce flicker.

```jsonc
// komorebi.json (abridged)
{
  "default_workspace_padding": 8,
  "default_container_padding": 8,
  "monitors": [{
    "workspaces": [
      { "name": "I",   "layout": "BSP" },
      { "name": "II",  "layout": "Columns" },
      { "name": "III", "layout": "Rows" }
    ]
  }],
  "float_rules": [
    { "kind": "Exe", "id": "1Password.exe" },
    { "kind": "Class", "id": "TaskManagerWindow" }
  ]
}
```

```powershell
# Start it
komorebic start --whkd --bar
# Move focused window across the BSP tree
komorebic focus right
komorebic move right
```

## References
- <https://github.com/LGUG2Z/komorebi>
