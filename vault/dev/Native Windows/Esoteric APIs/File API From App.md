# File API From App

The `*FromApp` file APIs are the AppContainer-friendly variants of classic file functions. `MoveFileFromAppW` looks mundane until you need desktop-style file work from a packaged app, where capability checks, brokered access, and Store policy replace the assumptions behind `MoveFileW`.

Keep this near MSIX/AppContainer notes rather than ordinary file I/O. It connects to `Known Folders`, `ShellExecute and File Operations`, and `YY-Thunks`: all three show how a familiar Win32 call can mean different things depending on package identity, OS vintage, and loader surface.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/nf-fileapifromapp-movefilefromappw>
