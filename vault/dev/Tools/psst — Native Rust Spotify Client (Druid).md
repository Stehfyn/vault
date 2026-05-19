<!-- generated-from-dump2 -->
# psst — Native Rust Spotify Client (Druid)

Native-GUI Spotify client in Rust — fast, low-memory, no Electron, no embedded Chromium. Built on **Druid** (a now-deprecated Rust GUI framework from Raph Levien's Linebender group, predecessor of Xilem). Speaks Spotify's protocol via `librespot` (the reverse-engineered library that powers most third-party Spotify clients), so it can stream OGG Vorbis directly from CDNs after authenticating with your Spotify Premium account. Requires Premium (a librespot constraint, not psst's). Useful read for "what does a serious native music-player UI look like in Rust" and as the most polished example of Druid in the wild.

```rust
// Conceptual: psst-core delegates the audio + auth heavy lifting to librespot
// while psst-gui owns the UI tree. (Real entry: src/main.rs in psst-gui.)
use librespot_core::{authentication::Credentials, config::SessionConfig, Session};
use librespot_playback::{audio_backend, config::PlayerConfig, player::Player};

let session = Session::connect(
    SessionConfig::default(),
    Credentials::with_password("user", "pass"),
    None, false,
).await?;

let backend = audio_backend::find(None).unwrap();
let (player, _events) = Player::new(
    PlayerConfig::default(), session.clone(), None,
    move || backend(None, AudioFormat::default()),
);
player.load(SpotifyId::from_uri("spotify:track:...")?, true, 0);
```

## References
- <https://github.com/jpochyla/psst>
