<!-- generated-from-dump2 -->
# spotify-tui — Terminal Spotify Client (tui-rs)

Terminal UI client for Spotify — keyboard-driven library/playlist navigation, playback control, queue management, search, all in a `tui-rs` (now `ratatui`) interface. Talks to the Spotify Web API (so it controls a Spotify client running elsewhere — `spotifyd` is the typical companion to run the actual audio decoder headlessly). Effectively unmaintained since 2023 — the Spotify API surface has tightened (deprecated endpoints, OAuth flow changes) and several user-reported features have rotted. The maintained successor in the same niche is `aome510/spotify-player` (more modern UI, MPV/MP3 playback baked in, better keymap config). Worth knowing about as the historically dominant Spotify TUI.

```bash
cargo install spotify-tui     # or use a package manager
spt                            # launch

# First run walks you through OAuth setup — needs a Spotify dev app
# (Client ID + Client Secret pasted into ~/.config/spotify-tui/client.yml)

# Pair with spotifyd for headless playback on the same host
# (so the TUI doesn't need the GUI client running)
```

## References
- <https://github.com/Rigellute/spotify-tui>
