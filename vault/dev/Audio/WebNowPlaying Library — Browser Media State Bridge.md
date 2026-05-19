<!-- generated-from-dump2 -->
# WebNowPlaying Library — Browser Media State Bridge

C library (with bindings for several languages) that exposes the "what is currently playing in my web browser tab" state to native applications. The piece that makes this work is the WebNowPlaying *browser extension* (separate project, by the same author): it monkey-patches `navigator.mediaSession`/`<audio>`/`<video>` event listeners in tabs running Spotify Web, YouTube, YouTube Music, SoundCloud, etc., then ships the metadata over a localhost WebSocket. The library is the **native** side of that bridge — connects to the local WS, parses the protocol, and exposes title/artist/album/album-art/position/state to your app via a tiny C API. Used by Rainmeter skins, OLED display utilities, and stream-overlay tools that need to display "what's playing" without per-service API keys.

```c
#include "WebNowPlaying.h"

// Spin up the WS client (connects to ws://localhost:port the extension owns).
WNPStartListener();

WNPInfo info;
WNPGetInfo(&info);
printf("%s - %s [%lld/%lld ms] %s\n",
       info.artist, info.title,
       info.positionMs, info.durationMs,
       info.isPlaying ? "playing" : "paused");

// Send commands back to the active browser tab:
WNPSendCommand(WNPCMD_TOGGLE_PLAY);
WNPSendCommand(WNPCMD_NEXT_TRACK);
WNPStopListener();
```

## References
- <https://github.com/keifufu/WebNowPlaying-Library>
