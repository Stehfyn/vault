# Ms Player

`msplayer` is a minimal Win32 media player built around MCI string commands. `mciSendString` hides device-specific media handling behind commands such as `open`, `play`, `pause`, `stop`, `status`, and `close`, with completion reported through `MM_MCINOTIFY`. That makes it attractive for tiny tools and old samples where "play this file" matters more than format control.

The tradeoff is control and predictability. MCI is legacy, stringly typed, and dependent on installed codecs/device aliases; it is not the right base for modern playback, synchronization, or capture. Its value in this folder is as an example of message-integrated media control in a plain HWND app.

## References
- <https://github.com/v1nns/msplayer> - small MCI-based Win32 audio/video player.

## Connections
- `Window Messaging.md` covers callback message delivery.
- Media Foundation entries elsewhere in Native Windows are the modern replacement path.
