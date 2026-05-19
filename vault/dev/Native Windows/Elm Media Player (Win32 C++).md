# Elm Media Player (Win32 C++)

Elm is primarily a Win32 UI specimen rather than a media engine reference: a small Visual Studio C++ player with custom-painted chrome and a deliberate Windows Media Player 9 / Luna-era look. The interesting question is how much surface area a hobby player has to own once it stops using stock controls: non-client painting, hit testing, playlist state, visualization timing, and media graph lifetime all become application code.

Use it near custom frame, DirectShow/Media Foundation, and WTL/MFC control-library entries as a reminder that "native media player" is mostly shell and UI glue unless the repo is explicitly teaching codecs or audio backends.

Code contribution: inspect the project for `WM_NCHITTEST`, `WM_PAINT`, playlist state, and media-backend lifetime rather than treating the link as a codec reference.

## References
- <https://github.com/RKirlew/Elm-Media-Player> - compact C++ player project to inspect for custom skinning and classic Win32 app structure.
